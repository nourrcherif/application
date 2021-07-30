#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
class cpu
{


public:
    cpu(){};
    QString GetUserCpu();
    QString GetIdleCpu();


};
class ram
{


public :
    ram(){};
    QString GetTotalRam();
    QString GetFreeRam();
};

class disk
{


public :
    disk(){};
    double GetFileDisk();
    double GetFreeDisk();
};

class swap
{


public :
    swap(){};
    QString GetTotalSwap();
    QString GetFreeSwap();
};

class network
{


public :
    network(){};
    QString GetIP();
    QString GetHW();
};








#endif // MAINWINDOW_H
