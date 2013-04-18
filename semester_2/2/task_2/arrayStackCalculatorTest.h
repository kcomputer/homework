#ifndef ARRAYSTACKCALCULATORTEST_H
#define ARRAYSTACKCALCULATORTEST_H

#include <QTest>
#include <QObject>
#include <stackMachine.h>



//! Testing array stack calculator.


class ArrayStackCalculatorTest : public QObject
{
    Q_OBJECT
public:
    explicit ArrayStackCalculatorTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void testCalculator()
    {
        QVERIFY(stackMachine("5 1 2 + 4 * + 3 -", 1) == 14);
    }
};


#endif // ARRAYSTACKCALCULATORTEST_H
