#include "GraphWithRobotsTest.h"
#include <fstream>

#include <iostream>


using namespace std;
int main()
{
    GraphWithRobotsTest test;
    QTest::qExec(&test);

    return 0;
}
