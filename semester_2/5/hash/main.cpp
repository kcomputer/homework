#include <QtCore/QCoreApplication>
#include "changeableHashTest.h"
//#include "interactivePart.h"

int main(int argc, char *argv[])
{
    ChangeableHashTest test;
    QTest::qExec(&test);

    QCoreApplication a(argc, argv);
    
    interactivePart();
    return a.exec();
}
