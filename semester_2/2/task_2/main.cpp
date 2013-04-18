#include <QtCore/QCoreApplication>
#include "arrayStackCalculatorTest.h"
#include "pointerStackCalculatorTest.h"

int main()
{
    ArrayStackCalculatorTest test;
    PointerStackCalulatorTest test2;
    QTest::qExec(&test);
    QTest::qExec(&test2);
}
