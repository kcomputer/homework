#include "arrayListTest.h"
#include "pointerListTest.h"

int main()
{
    ArrayListTest test;
    PointerListTest test2;
    QTest::qExec(&test);
    QTest::qExec(&test2);
}
