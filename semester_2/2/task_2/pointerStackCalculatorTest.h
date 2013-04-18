#ifndef POINTERSTACKCALCULATORTEST_H
#define POINTERSTACKCALCULATORTEST_H



#include <QTest>
#include <QObject>
#include "stackMachine.h"


//! Testing pointer stack calculator.


class PointerStackCalulatorTest : public QObject
{
    Q_OBJECT
public:
    explicit PointerStackCalulatorTest(QObject *parent = 0): QObject(parent) {}
private slots:

    void testCalculator()
    {
        QVERIFY(stackMachine("5 1 2 + 4 * + 3 -", 2) == 14);
    }

};


#endif // POINTERSTACKCALCULATORTEST_H
