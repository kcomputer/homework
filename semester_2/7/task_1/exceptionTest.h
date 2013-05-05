#ifndef EXEPTIONTEST_H
#define EXEPTIONTEST_H


#include <QtCore/QObject>
#include <QtTest/QTest>
#include <sstream>
#include <stdexcept>
#include "exception.h"

using namespace std;

class ExceptionTest : public QObject
{
    Q_OBJECT
public:
    explicit ExceptionTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void test()
    {
        streambuf* buff = cout.rdbuf();
        cout.rdbuf(nOut.rdbuf());
        Test* mTest = new Test();
        try
        {
            mTest->callExeption();
        }
        catch (invalid_argument)
        {
            delete (mTest);
        }

        QVERIFY(!nOut.str().compare("Constructor""Destructor"));
        cout.clear();
        cout.rdbuf(buff);
    }

private:
    stringstream nOut;
};


#endif // EXEPTIONTEST_H
