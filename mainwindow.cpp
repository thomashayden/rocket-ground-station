#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->layout()->setSizeConstraint(QLayout::SetFixedSize);

    HandleFullScreen* key = new HandleFullScreen(this);
    installEventFilter(key);

    QPixmap pix("/home/thomas/Northeastern/AIAA/CompetitionRocketry/GroundStation/test.jpeg");
    ui->label_pic->setPixmap(pix);
    // This shouldn't be needed, but just in case
    ui->label_pic->setScaledContents(true);

    QPixmap logo_pix("/home/thomas/Northeastern/AIAA/aeronu640x120.png");
    ui->logo->setPixmap(logo_pix);
    // This shouldn't be needed, but just in case
    ui->logo->setScaledContents(true);

    MainWindow::red = new QPixmap("/home/thomas/Northeastern/AIAA/CompetitionRocketry/GroundStation/red.png");
    MainWindow::green = new QPixmap("/home/thomas/Northeastern/AIAA/CompetitionRocketry/GroundStation/green.png");

    ui->label_comm_status->setPixmap(*green);
    ui->label_mov_status->setAlignment(Qt::AlignRight);
    ui->label_mov_status->setPixmap(*red);
    ui->label_col_status->setPixmap(*red);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete red;
    delete green;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_mov_status->setPixmap(*green);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->label_col_status->setPixmap(*green);
}
