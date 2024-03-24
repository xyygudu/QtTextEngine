#include "QtTextEngine.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtTextEngine w;
    w.show();
    return a.exec();
}
