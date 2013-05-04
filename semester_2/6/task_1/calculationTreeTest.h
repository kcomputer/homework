#ifndef CALCULATIONTREETEST_H
#define CALCULATIONTREETEST_H
#include <QtCore/QObject>
#include <QtTest/QTest>
#include "calculationTree.h"
#include <sstream>

using namespace std;

class CalcTreeTest : public QObject
{
    Q_OBJECT
public:
    explicit CalcTreeTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        expression = "(*(+11)2)";
        mTree = new Operation(expression);
    }
    void cleanup()
    {
        delete mTree;
    }

    void test_Tree_Result()
    {
        int tmp = mTree->result();
        QCOMPARE(tmp,4);
    }
    void test_Tree_Print()
    {
        //! redirecting cout's output thrrough its stream buffer.

        streambuf* buff = cout.rdbuf();
        cout.rdbuf(bt.rdbuf());
        mTree->print();
        QVERIFY(bt.str().compare("(*(+11)2)"));
        cout.clear();
        cout.rdbuf(buff);
    }

private:
    string expression;
    CalcTree* mTree;
    stringstream bt;
};

#endif // CALCULATIONTREETEST_H


