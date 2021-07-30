#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include<QFile>
#include <QMessageBox>
#include <QPushButton>
#include <sys/statvfs.h>



using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cpu* c=new cpu();
    ui->lineEdit_5->setText(c->GetUserCpu());
    ui->lineEdit_6->setText(c->GetIdleCpu());

    ram* r=new ram();
    ui->lineEdit_9->setText(r->GetTotalRam());
    ui->lineEdit_8->setText(r->GetFreeRam());

    disk* d=new disk();
    ui->lineEdit_10->setText(QString::number(d->GetFileDisk()));
    ui->lineEdit_11->setText(QString::number(d->GetFreeDisk()));

    class swap* s=new class swap();
    ui->lineEdit_12->setText(s->GetTotalSwap());
    ui->lineEdit_13->setText(s->GetFreeSwap());

    network* n=new network();
    ui->lineEdit_17->setText(n->GetHW());
    ui->lineEdit_16->setText(n->GetIP());

}

MainWindow::~MainWindow()
{
    delete ui;
}


QString cpu::GetUserCpu()
{
    QFile file("/proc/stat");
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"error",file.errorString());
    QTextStream in(&file);
    QString s,ss;
    int i;
    for (i=0;i<25;i++)
    {
        s=s+in.read(i);
    }
    for (i=4;i<11;i++)
    {
        ss=ss+s[i];
    }
    return ss;
}
QString cpu::GetIdleCpu()
{
    QFile file("/proc/stat");
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"error",file.errorString());
    QTextStream in(&file);
    QString s,ss;
    int i;
    for (i=0;i<25;i++)
    {
        s=s+in.read(i);
    }
    for (i=22;i<30;i++)
    {
        ss=ss+s[i];
    }
    return ss;
}

QString ram::GetTotalRam()
{
    QFile file("/proc/meminfo");
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"error",file.errorString());
    QTextStream in(&file);
    QString s,ss;
    int i;
    for (i=0;i<26;i++)
    {
        s=s+in.read(i);
    }
    for (i=16;i<28;i++)
    {
        ss=ss+s[i];
    }
    return ss;

}
QString ram::GetFreeRam()
{
    QFile file("/proc/meminfo");
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"error",file.errorString());
    QTextStream in(&file);
    QString s,ss;
    int i;
    for (i=0;i<60;i++)
    {
        s=s+in.read(i);
    }
    for (i=45;i<56;i++)
    {
        ss=ss+s[i];
    }
    return ss;

}

double disk::GetFileDisk()
{
    const unsigned int GB = (1024 * 1024) * 1024;
    struct statvfs buffer;

    const double total = (buffer.f_blocks * buffer.f_frsize) / GB;

    return total;
}
double disk::GetFreeDisk()
{
    const unsigned int GB = (1024 * 1024) * 1024;
    struct statvfs buffer;

    const double free = (buffer.f_bfree * buffer.f_frsize) / GB;


    return free;
}

QString swap::GetTotalSwap()
{
    QFile file("/proc/meminfo");
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"error",file.errorString());
    QTextStream in(&file);
    QString s,ss;
    int i;
    for (i=0;i<31;i++)
    {
        s=s+in.read(i);
    }
    for (i=408;i<420;i++)
    {
        ss=ss+s[i];
    }
    return ss;

}
QString swap::GetFreeSwap()
{
    QFile file("/proc/meminfo");
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"error",file.errorString());
    QTextStream in(&file);
    QString s,ss;
    int i;
    for (i=0;i<31;i++)
    {
        s=s+in.read(i);
    }
    for (i=436;i<448;i++)
    {
        ss=ss+s[i];
    }
    return ss;

}

QString network::GetIP()
{
    QFile file("/proc/net/arp");
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"error",file.errorString());
    QTextStream in(&file);

    QString s,ss;
    int i;
    for (i=0;i<200;i++)
    {
        s=s+in.read(i);
    }
    for (i=79;i<87;i++)
    {
        ss=ss+s[i];
    }
    return ss;
}
QString network::GetHW()
{

    QFile file("/proc/net/arp");
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"error",file.errorString());
    QTextStream in(&file);

    QString s,ss;
    int i;
    for (i=0;i<200;i++)
    {
        s=s+in.read(i);
    }
    for (i=120;i<142;i++)
    {
        ss=ss+s[i];
    }
    return ss;


}

void MainWindow::on_pushButton_clicked()
{
    cpu* c=new cpu();
    ui->lineEdit_5->setText(c->GetUserCpu());
    ui->lineEdit_6->setText(c->GetIdleCpu());

    ram* r=new ram();
    ui->lineEdit_9->setText(r->GetTotalRam());
    ui->lineEdit_8->setText(r->GetFreeRam());


    disk* d=new disk();
    ui->lineEdit_10->setText(QString::number(d->GetFileDisk()));
    ui->lineEdit_11->setText(QString::number(d->GetFreeDisk()));

    class swap* s=new class swap();
    ui->lineEdit_12->setText(s->GetTotalSwap());
    ui->lineEdit_13->setText(s->GetFreeSwap());

    network* n=new network();
    ui->lineEdit_17->setText(n->GetHW());
    ui->lineEdit_16->setText(n->GetIP());
}

