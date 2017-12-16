#ifndef SKY_H
#define SKY_H
#include <QMainWindow>
#include "airplane.h"
#include "missile.h"
#include <QImage>

class Explode;
class QPushButton;


class Sky : public QMainWindow
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void AllObject();
    void createEairplane();
    Sky(QWidget *parent = 0);
    ~Sky();

    static const int GAME_WIDTH=640;
    static const int GAME_HEIGHT=480;

    bool start;
    bool gameover,victory;
    Airplane* myairplane;
    QList<Missile*> missile;
    QList<Airplane*> eairplanes;
    QList<Explode*> explodes;
    QList<QPushButton*> button;

    static QList<QImage> logoImgs;
    int step;
    int eairplaneCount;
    int time_s;
private slots:
    void pressStart();
};

#endif // SKY_H
