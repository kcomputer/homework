#include <QtCore/QCoreApplication>
#include "changeableHashTest.h"
#include "interactivePart.h"

int main()
{
    ChangeableHashTest test;
    QTest::qExec(&test);

    interactivePart();
}
