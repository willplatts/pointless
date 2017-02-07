#include "pointless.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pointless w;
    w.show();

    return a.exec();
}
