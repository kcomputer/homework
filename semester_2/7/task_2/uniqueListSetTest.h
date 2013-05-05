#pragma once
#include <QtCore/QObject>
#include <QtTest/QTest>
#include "uniqueListSet.h"

class UniqueListSetTest : public QObject
{
    Q_OBJECT
public:
    explicit UniqueListSetTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        intSet = new UniqueListSet<int>();
    }
    void cleanup()
    {
        delete intSet;
    }
    void testAddAndFind()
    {
        try
        {
            intSet->add(11);
            intSet->add(11);
        }
        catch (UniqueListSet<int>::AddExisting)
        {
            QWARN("It already exists.");
        }
        QVERIFY(intSet->find(11));
    }
    void testDelete()
    {
        intSet->add(15);
        try
        {
            intSet->deleteElement(1);
        }
        catch (UniqueListSet<int>::DeleteUnexisting)
        {
            QWARN("It doesn't exist.");
        }
        intSet->deleteElement(15);
        QVERIFY(!intSet->find(15));
    }

private:
    UniqueListSet<int>* intSet;
};
