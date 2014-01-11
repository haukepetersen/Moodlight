#include "cutelight.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cutelight w;
    w.show();

    return a.exec();
}
