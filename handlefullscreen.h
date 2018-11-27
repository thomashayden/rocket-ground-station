#ifndef HANDLEFULLSCREEN_H
#define HANDLEFULLSCREEN_H

#include <QObject>
#include <QKeyEvent>
#include <QMainWindow>

class HandleFullScreen : public QObject
{
    Q_OBJECT
public:
    explicit HandleFullScreen(QMainWindow* root, QObject* parent = nullptr);

signals:

public slots:

protected:
    bool eventFilter(QObject* obj, QEvent* event);

private:
    QMainWindow* mainWindow;
};

#endif // HANDLEFULLSCREEN_H
