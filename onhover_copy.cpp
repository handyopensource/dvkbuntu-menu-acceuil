#include "onhover.h"

class onhover: public QPushButton
{
    // QWidget interface
    protected:
        virtual void enterEvent(QEvent *) {
            qDebug() << "entering";
            QPalette pal = palette();
            pal.setColor(QPalette::Button, QColor(Qt::blue));
            setAutoFillBackground(true);
            setPalette(pal);
            update();
    };
};
