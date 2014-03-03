#include "GraphWithRobotsTest.h"
#include <fstream>
#include "string"
#include <iostream>


using namespace std;
int main()
{
//    char *graphFileName;

//    graphFileName = "Graph_1.txt";
//    cout << graphFileName;


//    ifstream graphFile (graphFileName);

//    if (graphFile.is_open())
//    {
//        cout << "BITCH";
//    }
//    else
//    {
//        cout << "DEQQ";
//    }

    GraphWithRobotsTest test;
    QTest::qExec(&test);

    return 0;
}
