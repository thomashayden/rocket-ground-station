#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "handlefullscreen.h"
#include "communication.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void check_buttons();

    bool is_file_exist(const char *file_name);

private:
    Ui::MainWindow *ui;
    QPixmap *red;
    QPixmap *green;
    QTimer *timer;
};

#endif // MAINWINDOW_H
