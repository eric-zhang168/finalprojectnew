#include "missile.h"
#include <QtGui>
#include "sky.h"
#include <QList>
#include "airplane.h"
#include "explode.h"

QList<QImage> Missile::missileImgs;

Missile::Missile(int x,int y,int w,int h,Dir dir,Sky* tc,bool good)
{
  this->x=x;
  this->y=y;
  this->w=w;
  this->h=h;
  this->dir=dir;
  live=true;
  this->tc=tc;
  this->good=good;
}

void Missile::drawMissile(QPainter &p)
{
    if(!live)
    {
        tc->missile.removeOne(this);
        return ;
    }
    if(good) p.drawImage(x,y,missileImgs[0]);
    else p.drawImage(x,y,missileImgs[1]);

    moveMissile();
}

void Missile::moveMissile()
{
    if(good) y-=15;
    else y+=15;

    if(x<=0||y<=0||x>=Sky::GAME_WIDTH||y>=Sky::GAME_HEIGHT)live=false;
}
bool Missile::hitAirplane(Airplane* t)
{
    if(live&&t->live&&good!=t->good&&this->getRect().intersects(t->getRect()))
    {
        live=false;
        t->liveValue-=20;
        if( t->liveValue==0)
        {
            t->live=false;
            Explode* e=new Explode(x,y,tc);
            tc->explodes.push_back(e);
            return true;
        }
    }
    return false;
}
void Missile::hitAirplanes(QList<Airplane*> ts)
{
    for(int i=0;i<ts.size();i++)
    {
        if(hitAirplane(ts[i]))return ;
    }
}


