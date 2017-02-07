#include "pointless.h"
#include "ui_pointless.h"

#include <QThread>

QString error = "QProgressBar::chunk {background: red;border-bottom-right-radius: 5px;border-bottom-left-radius: 5px;border: .px solid black;}";
QString ok= "QProgressBar::chunk {background: green;border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}";

Pointless::Pointless(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pointless)
{
    ui->setupUi(this);

    //Set up control window
    ctrlWindow = new ControlWindow(this);
    ctrlWindow->show();

    //Set up main window
    ui->text_score->setText("100");
    ui->text_score->setAlignment(Qt::AlignCenter);

    ui->prog_score->setRange(0,100);
    ui->prog_score->setValue(100);
    ui->prog_score->setStyleSheet(ok);
    ui->prog_score->setTextVisible(false);
}

Pointless::~Pointless()
{
    delete ui;
}


/*!
 * \brief Pointless::StartRun
 *
 * Start countdown
 *
 * \param score - score to count down to
 *
 */
void Pointless::StartRun(int score)
{
    DoReset();

    if ((score < 100) && (score >= 0))
    {
        ui->prog_score->setStyleSheet(ok);
        QThread::msleep(500);

        for (int val = 100; val >= score; val--)
        {
            ui->prog_score->setValue(val);
            ui->text_score->setText(QString::number(val));
            ui->text_score->setAlignment(Qt::AlignCenter);
            QThread::msleep(75);
        }

    }
    else if (score == 100)
    {
        ui->text_score->setText("X");
        ui->text_score->setAlignment(Qt::AlignCenter);
        ui->prog_score->setStyleSheet(error);
    }
}


/*!
 * \brief Pointless::DoReset
 *
 * Reset the score indicator
 */
void Pointless::DoReset()
{
    ui->prog_score->setValue(100);
    ui->text_score->setText("100");
    ui->text_score->setAlignment(Qt::AlignCenter);
    ui->prog_score->setStyleSheet(ok);
}
