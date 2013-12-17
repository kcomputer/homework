#include "counterTest.h"

int main()
{
    CounterTest test;
    QTest::qExec(&test);
    return 0;
}
