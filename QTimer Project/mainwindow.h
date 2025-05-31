#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    int ms, sec, min;

private slots:
    void TimerCheck();
    void LoadTimer();
    void ClearTimer();

    void on_pauseBtn_clicked(bool checked);
    void on_clearBtn_clicked(bool checked);
};
#endif // MAINWINDOW_H
