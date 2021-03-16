#include "CubicCurve.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	a.setWindowIcon(QIcon(":/CubicCurve/cubic"));
    CubicCurve w;
    w.show();
    return a.exec();
}
