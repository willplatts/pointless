#include "controlwindow.h"
#include "ui_controlwindow.h"

ControlWindow::ControlWindow(Pointless *pointless_window, QWidget *parent) :
    QDialog(parent),
    pointless_window(pointless_window),
    ui(new Ui::ControlWindow)
{
    ui->setupUi(this);

    //connect(this, SIGNAL(CtrlRun(int)), pointless_window, SLOT(StartRun(int)));
    //connect(this, SIGNAL(CtrlReset()), pointless_window, SLOT(DoReset()));
}

ControlWindow::~ControlWindow()
{
    delete ui;
}

void ControlWindow::on_pb_reset_clicked()
{
    pointless_window->DoReset();
}

void ControlWindow::on_pb_run_clicked()
{
    pointless_window->StartRun(ui->textEdit->toPlainText().toInt());
}
