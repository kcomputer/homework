#include "avlTreeTest.h"
#include "bagTest.h"

int main()
{
    avlTreeTest test;
    BagTest test2;
    QTest::qExec(&test);
    QTest::qExec(&test2);
    return 0;
}
