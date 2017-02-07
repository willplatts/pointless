#ifndef POINTLESS_H
#define POINTLESS_H

#include <QMainWindow>


#include "controlwindow.h"
class ControlWindow;

namespace Ui {
class Pointless;
}

class Pointless : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pointless(QWidget *parent = 0);
    ~Pointless();

public slots:
    void StartRun(int score);
    void DoReset();

private:
    Ui::Pointless *ui;
    ControlWindow *ctrlWindow;

};

#endif // POINTLESS_H
