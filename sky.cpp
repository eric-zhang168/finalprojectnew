#include "sky.h"
#include "airplane.h"
#include "missile.h"
#include "explode.h"
#include <QtWidgets>

QList<QImage> Sky::logoImgs;
Sky::Sky(QWidget *parent) :
    QMainWindow(parent)
{
    step=0;
    eairplaneCount=0;
    time_s = 0;
    start=false;
    gameover=false;
    victory=false;
    Airplane::init();
    setWindowTitle(tr("airplane game"));
    setStyleSheet("image:url(:/images/skypicture5.jpeg)");
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    move(100,100);
    AllObject();

    QPushButton* startGame=new QPushButton(tr("start game"),this);
    button.push_back(startGame);
    QPushButton* exitGame=new QPushButton(tr("quit game"),this);
    button.push_back(exitGame);
    button[0]->setGeometry(160,100,80,40);
    button[1]->setGeometry(440,100,80,40);
    connect(button[0],SIGNAL(clicked()),this,SLOT(pressStart()));
    connect(button[1],SIGNAL(clicked()),this,SLOT(close()));
    //ui->setupUi(this);
    startTimer(30);
}

Sky::~Sky()
{
}

void Sky::createEairplane()
{
    Airplane* t=new Airplane(qrand()%600,20,30,30,this,false,100);
    eairplanes.push_back(t);//randomly draw 1 enemy
    eairplaneCount++;
}

void Sky::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    if(start)
    {
        for(int i=0;i<button.size();i++)
        {
            button[i]->hide();
        }
        myairplane->drawAirplane(p);//draw player's airplane
        if(time_s >= 600)
        {
            createEairplane();
            time_s = 0;
        }
        else time_s += 30;


        p.drawText(10,30,tr("Amount of enemy：")+ QString::number(eairplanes.size()));
        for(int i=0;i<missile.size();i++)//draw the bullet
        {
            //check if there is a hit
            missile[i]->hitAirplanes(eairplanes);
            missile[i]->hitAirplane(myairplane);
            missile[i]->drawMissile(p);
        }
        for(int i=0;i<eairplanes.size();i++)//draw all enemy
        {
            eairplanes[i]->drawAirplane(p);
        }
        for(int i=0;i<explodes.size();i++)//draw the explodes
        {

            explodes[i]->drawExplode(p);
        }
        if(eairplanes.size()==0 || myairplane->liveValue == 0 || eairplaneCount >= 50)
        {
            close();
        }
    }
    else
    {
        p.drawImage(80,400-3*step,Sky::logoImgs[0]);
        step++;
        if(step>=80)step=80;
        button[0]->show();
        button[1]->show();
    }
}

void Sky::timerEvent(QTimerEvent *)
{
    update();
}

void Sky::keyPressEvent(QKeyEvent *e)
{
   qDebug("key=%d",e->key());
   if(myairplane->live)
    myairplane->keyPress(e->key());
   else
   {
       switch(e->key())
       {
           case Qt::Key_F1: myairplane->keyPress(Qt::Key_F1);break;
           case Qt::Key_Escape: myairplane->keyPress(Qt::Key_Escape);break;
           default: break;
       }
   }
}
void Sky::keyReleaseEvent(QKeyEvent *e)
{
   if(myairplane->live)
    myairplane->keyRelease(e->key());
}
void Sky::AllObject()
{
    myairplane=new Airplane(300,450,30,30,this,true,100); //create user's airplane
    for(int i=0;i<5;i++)//create 5 enemies
    {
        Airplane* t=new Airplane(qrand()%600,20,30,30,this,false,100);
        eairplanes.push_back(t);
    }

    eairplaneCount = 5;

}

void Sky::pressStart()
{
     myairplane->keyPress(Qt::Key_F2);
}
