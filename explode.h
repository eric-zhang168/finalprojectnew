#ifndef EXPLODE_H
#define EXPLODE_H
#include <QList>
#include <QImage>
class QPainter;
class Sky;
class Explode
{
public:
    Explode(int x,int y,Sky* tc);
    void drawExplode(QPainter &p);

    int x,y;
    bool live;
    int dis[10];
    int i;
    Sky* tc;

    static QList<QImage> explodeImgs;
};
#endif // EXPLODE_H
