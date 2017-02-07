#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QDialog>

#include "pointless.h"

class Pointless;

namespace Ui {
class ControlWindow;
}

class ControlWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ControlWindow(Pointless *pointless_window, QWidget *parent = 0);
    ~ControlWindow();

private slots:

    void on_pb_reset_clicked();

    void on_pb_run_clicked();

private:
    Ui::ControlWindow *ui;
    Pointless *pointless_window;

signals:
    void CtrlRun(int val);
    void CtrlReset();
};

#endif // CONTROLWINDOW_H
