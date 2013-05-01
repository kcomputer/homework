#include <QtGui/QApplication>
#include "calculator.h"
#include "calculatorTest.h"

int main(int argc, char *argv[])
{
    CalculatorTest test;
    QTest::qExec(&test);
    QApplication a(argc, argv);
    Calculator w;

    w.setWindowTitle("Calculator");
    w.resize(230, 200);

    w.show();
    
    return a.exec();
}
