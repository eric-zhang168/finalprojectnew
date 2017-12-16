#include "pub.h"
#include "airplane.h"
#include <QtGui>
#include "missile.h"
#include "sky.h"
#include "explode.h"
#include <QtWidgets>

QList<QImage> Airplane::airplaneImgs;
Airplane::Airplane(int x,int y,int w,int h,Sky* tc,bool good,int liveValue)
{
  this->x=x;
  this->y=y;
  this->w=w;
  this->h=h;
  BU=BD=BL=BR=false;
  this->tc=tc;
  dir=STOP;
  ptDir=U;
  this->good=good;
  live=true;
  step=0;
  xtemp=ytemp=0;
  this->liveValue=liveValue;
}

void Airplane::drawAirplane(QPainter &p)
{
    if(!live)
    {
        tc->eairplanes.removeOne(this);
        return ;
    }
    if(dir!=STOP)
        ptDir=dir;

    if(good)p.drawImage(x,y,airplaneImgs[0]);
    else p.drawImage(x,y,airplaneImgs[1]);

    p.setPen(Qt::yellow);
    p.setBrush(Qt::black);
    p.drawRect(x,y,33,5);

    p.setBrush(Qt::red);
    p.drawRect(x,y,liveValue/3,5);//画生命值

    moveAirplane();
}


void Airplane::keyPress(int key)
{
    switch(key)
    {
        case Qt::Key_W: BU=true;break;
        case Qt::Key_S: BD=true;break;
        case Qt::Key_A: BL=true;break;
        case Qt::Key_D: BR=true;break;
        case Qt::Key_J: fire();break;
        case Qt::Key_F2:
            {
                tc->step=0;
                tc->start=!tc->start;
                if(!(tc->start))//暂停/继续
                {
                    tc->button[1]->setText(QObject::tr("继续游戏"));
                }
                break;

            }
        case Qt::Key_F1:
            {
                //重启游戏
                while(tc->missile.size())
                    tc->missile.removeOne(tc->missile[0]);
                while(tc->eairplanes.size())
                    tc->eairplanes.removeOne(tc->eairplanes[0]);
                tc->AllObject();
                tc->start=true;
                tc->gameover=false;
                break;
            }
        case Qt::Key_Escape:exit(0);break;//退出游戏
        default:break;
    }
    if(BU&&!BD&&!BL&&!BR)dir=U;
    else if(!BU&&BD&&!BL&&!BR)dir=D;
    else if(!BU&&!BD&&BL&&!BR)dir=L;
    else if(!BU&&!BD&&!BL&&BR)dir=R;

    else if(BU&&!BD&&BL&&!BR)dir=LU;
    else if(!BU&&BD&&BL&&!BR)dir=LD;
    else if(BU&&!BD&&!BL&&BR)dir=RU;
    else if(!BU&&BD&&!BL&&BR)dir=RD;
    else dir=STOP;
}

void Airplane::keyRelease(int key)
{
    switch(key)
    {
        case Qt::Key_W: BU=false;break;
        case Qt::Key_S: BD=false;break;
        case Qt::Key_A: BL=false;break;
        case Qt::Key_D: BR=false;break;
        default:break;
    }
    if(BU&&!BD&&!BL&&!BR)dir=U;
    else if(!BU&&BD&&!BL&&!BR)dir=D;
    else if(!BU&&!BD&&BL&&!BR)dir=L;
    else if(!BU&&!BD&&!BL&&BR)dir=R;

    else if(BU&&!BD&&BL&&!BR)dir=LU;
    else if(!BU&&BD&&BL&&!BR)dir=LD;
    else if(BU&&!BD&&!BL&&BR)dir=RU;
    else if(!BU&&BD&&!BL&&BR)dir=RD;
    else dir=STOP;
}
void Airplane::moveAirplane()
{
    xtemp=x;
    ytemp=y;
    switch(dir)
    {
        case U: y-=5;break;
        case D: y+=5;break;
        case L: x-=5;break;
        case R: x+=5;break;

        case LU: x-=5;y-=5;break;
        case LD: x-=5;y+=5;break;
        case RU: x+=5;y-=5;break;
        case RD: x+=5;y+=5;break;
        default:break;
    }
    if(x<=0)x=0;
    if(y<=0)y=0;
    if(x>=Sky::GAME_WIDTH-w)x=Sky::GAME_WIDTH-w;
    if(!good)
    {
        if(y>=Sky::GAME_HEIGHT-h)
        {
            this->liveValue = 0;
        }
        else
        {
            if(qrand()%20>18)fire();
            if(step==0)
            {
                dir = D;
                step=qrand()%15+10;
            }
           step--;
        }
    }
    else
    {
        if(y>=Sky::GAME_HEIGHT-h)y=Sky::GAME_HEIGHT-h;
    }
}

void Airplane::fire()
{
    int mw=10;
    int mh=10;
    int mx=x+w/2-mw/2;
    int my=y+h/2-mh/2;
    Missile* m=new Missile(mx,my,mw,mh,ptDir,tc,good);
    tc->missile.push_back(m);
}
void  Airplane::fire(Dir tdir)
{
    int mw=10;
    int mh=10;
    int mx=x+w/2-mw/2;
    int my=y+h/2-mh/2;
    Missile* m=new Missile(mx,my,mw,mh,tdir,tc,good);
    tc->missile.push_back(m);
}


void Airplane::init()
{
    airplaneImgs.push_back(QImage(":/images/airplaneU.png"));
    airplaneImgs.push_back(QImage(":/images/airplaneD.png"));

    Missile::missileImgs.push_back(QImage(":/images/missileU.gif"));
    Missile::missileImgs.push_back(QImage(":/images/missileD.gif"));

    Explode::explodeImgs.push_back(QImage(":/images/0.gif"));
    Explode::explodeImgs.push_back(QImage(":/images/1.gif"));
    Explode::explodeImgs.push_back(QImage(":/images/2.gif"));
    Explode::explodeImgs.push_back(QImage(":/images/3.gif"));
    Explode::explodeImgs.push_back(QImage(":/images/4.gif"));
    Explode::explodeImgs.push_back(QImage(":/images/5.gif"));
    Explode::explodeImgs.push_back(QImage(":/images/6.gif"));
    Explode::explodeImgs.push_back(QImage(":/images/7.gif"));
    Explode::explodeImgs.push_back(QImage(":/images/8.gif"));
    Explode::explodeImgs.push_back(QImage(":/images/9.gif"));
    Explode::explodeImgs.push_back(QImage(":/images/10.gif"));


    Sky::logoImgs.push_back(QImage(":/images/logo.png"));
    //Sky::logoImgs.push_back(QImage(":/images/gameover.png"));
}
