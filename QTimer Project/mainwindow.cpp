#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //початкові значення
    ClearTimer();       //все з нулів
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerCheck()));
    timer->start(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//обробка значень для таймера
void MainWindow::TimerCheck()
{
    ms++;
    if (ms == 1000)
    {
        sec++;
        ms = 0;
    }
    if (sec == 60)
    {
        min++;
        sec=0;
    }

    LoadTimer();
}


//функція відображення значень у таймері
void MainWindow::LoadTimer()
{
    ui->minLbl->setText(QString::number(min) + " : ");
    ui->secLbl->setText(QString::number(sec) + " : ");
    ui->msLbl->setText(QString::number(ms));
}


//функція очистки таймера
void MainWindow::ClearTimer()
{
    ms = 0;
    sec = 0;
    min = 0;
}


//кнопка паузи
void MainWindow::on_pauseBtn_clicked(bool checked)
{
    if (checked)    //ставлення на паузу
    {
        timer->stop();
        ui->pauseBtn->setText("Старт");
    }
    else            //відновлення таймера
    {
        timer->start(1);
        ui->pauseBtn->setText("Пауза");
    }
}



//кнопки очистки таймера
void MainWindow::on_clearBtn_clicked(bool checked)
{
    if (checked)    //очистка з паузою
    {
        timer->stop();

        ClearTimer();   //очистка
        LoadTimer();    //оновлення

        ui->pauseBtn->setEnabled(false);
        ui->clearBtn->setText("Почати");
    }
    else            //відновлення з нуля
    {
        timer->start(1);
        ui->pauseBtn->setEnabled(true);
        ui->clearBtn->setText("Скинути");

        on_pauseBtn_clicked(false);
    }
}

