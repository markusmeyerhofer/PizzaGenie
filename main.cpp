#include "pizzagenie.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PizzaGenie w;
    w.show();
    return a.exec();
}
