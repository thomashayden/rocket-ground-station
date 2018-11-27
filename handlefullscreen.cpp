#include "handlefullscreen.h"

HandleFullScreen::HandleFullScreen(QMainWindow* root, QObject* parent) : QObject(parent)
{
    mainWindow = root;
}

bool HandleFullScreen::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *key = static_cast<QKeyEvent*>(event);
        if (key->key() == Qt::Key_F11) {
            if (mainWindow->isFullScreen()) {
                mainWindow->showNormal();
            } else {
                mainWindow->showFullScreen();
            }
        } else {
            return QObject::eventFilter(obj, event);
        }
        return true;
    } else {
        return QObject::eventFilter(obj, event);
    }
}
