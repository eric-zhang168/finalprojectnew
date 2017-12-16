#ifndef AIRPLANE_H
#define AIRPLANE_H
#include "pub.h"
#include <QRect>
#include <QList>
#include <QImage>

class QPainter;
class Sky;

class Airplane
{
public:
    Airplane(int x,int y,int w,int h,Sky* tc,bool good,int liveValue);
    void drawAirplane(QPainter &p);
    void keyRelease(int key);
    void keyPress(int key);
    void moveAirplane();
    void fire();
    void fire(Dir tdir);

    static void init();
    inline QRect getRect(){return QRect(x,y,w,h);}//get my position

    int x,y,w,h;
    bool BU,BD,BL,BR;
    Dir dir;
    Dir ptDir;
    Sky* tc;
    bool good;
    bool live;
    int step;
    int xtemp,ytemp;//last position
    int liveValue;
    static QList<QImage> airplaneImgs;

};

#endif // AIRPLANE_H
