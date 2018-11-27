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

    ui->label_mvc->setStyleSheet("QLabel { color : green; }");
}

MainWindow::~MainWindow()
{
    delete ui;
}
