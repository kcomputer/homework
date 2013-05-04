#include <calculationTreeTest.h>
#include <QTest>

int main()
{
    CalcTreeTest test;
    QTest::qExec(&test);
    return 0;
}
