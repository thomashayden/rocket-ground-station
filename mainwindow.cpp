#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostAddress>
#include <QAbstractSocket>
#include <QNetworkInterface>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->layout()->setSizeConstraint(QLayout::SetFixedSize);

    HandleFullScreen* key = new HandleFullScreen(this);
    installEventFilter(key);

    QPixmap pix(":/res/test.jpeg");
    ui->label_pic->setPixmap(pix);
    // This shouldn't be needed, but just in case
    ui->label_pic->setScaledContents(true);

    QPixmap logo_pix(":/res/aeronu640x120.png");
    ui->logo->setPixmap(logo_pix);
    // This shouldn't be needed, but just in case
    ui->logo->setScaledContents(true);

    MainWindow::red = new QPixmap(":/res/red.png");
    MainWindow::green = new QPixmap(":/res/green.png");

    ui->label_comm_status->setPixmap(*green);
    ui->label_mov_status->setAlignment(Qt::AlignRight);
    ui->label_mov_status->setPixmap(*red);
    ui->label_col_status->setPixmap(*red);

    QList<QHostAddress> list = QNetworkInterface::allAddresses();

    for(int nIter=0; nIter<list.count(); nIter++)
    {
        if(!list[nIter].isLoopback())
            if (list[nIter].protocol() == QAbstractSocket::IPv4Protocol )
                ui->ip_label->setText(ui->ip_label->text() + list[nIter].toString() + "   ");

    }

    ui->pid_label->setText("PID: " + QString::number(QCoreApplication::applicationPid()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete red;
    delete green;
}

void MainWindow::on_pushButton_clicked()
{
    Communication comm;
    const char* testing = "testing";
    comm.Write(testing);
    ui->label_mov_status->setPixmap(*green);
}

void MainWindow::on_pushButton_2_clicked()
{
    Communication comm;
    const char* testing = "more testing";
    comm.SaveImage(testing);
    ui->label_col_status->setPixmap(*green);
}
