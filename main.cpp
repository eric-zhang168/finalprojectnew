
#include "sky.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sky w;
    w.show();

    return a.exec();
}
