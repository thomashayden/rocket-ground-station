#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    HandleFullScreen* key = new HandleFullScreen(this);
    installEventFilter(key);
}

MainWindow::~MainWindow()
{
    delete ui;
}
