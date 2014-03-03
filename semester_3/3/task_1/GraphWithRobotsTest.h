#ifndef TEST_H
#define TEST_H

#include <QtTest/QTest>
#include "GraphWithRobots.h"
#include "string.h"


using namespace std;

class GraphWithRobotsTest : public QObject
{
        Q_OBJECT
public:
        explicit GraphWithRobotsTest(QObject *parent = 0) : QObject(parent) {}

private:
    char *graphFileName;
    GraphWithRobots *GraphTest;

private slots:
        void init()
        {
            graphFileName ="Graph_1.txt";
            GraphTest = new GraphWithRobots(graphFileName);
        }

        void firstTest()
        {
            QCOMPARE(GraphTest->calculteProbability(), true);
        }

        void secondTest()
        {
            graphFileName = "Graph_2.txt";
            GraphTest->insertData(graphFileName);

            QCOMPARE(GraphTest->calculteProbability(), false);
        }

        void cleanup()
        {
                delete GraphTest;
        }
};
#endif // TEST_H
