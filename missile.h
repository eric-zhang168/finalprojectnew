#ifndef MISSILE_H
#define MISSILE_H
#include "pub.h"
#include <QRect>
#include <QList>
#include <QImage>

class QPainter;
class Sky;
class Airplane;
//class Wall;
class Missile
{
public:
    Missile(int x,int y,int w,int h,Dir dir,Sky* tc,bool good);
    void drawMissile(QPainter &p);
    void moveMissile();
    bool hitAirplane(Airplane *t);
    void hitAirplanes(QList<Airplane*> ts);
    //bool hitWall(Wall* w);
    //void hitWalls(QList<Wall*> ws);
    inline QRect getRect(){return QRect(x,y,w,h);}

    int x,y,w,h;
    Dir dir;
    bool live;
    Sky* tc;
    bool good;

    static QList<QImage> missileImgs;

};
#endif // MISSILE_H
