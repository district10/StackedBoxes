#include "StackedBoxes.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StackedBoxes w;
    w.show();

    return a.exec();
}
