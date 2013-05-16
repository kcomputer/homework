#ifndef BAGTEST_H
#define BAGTEST_H


#include <QtCore/QObject>
#include <QtTest/QTest>
#include "bag.h"
#include <iostream>
using namespace std;

using namespace std;

class BagTest : public QObject
{
    Q_OBJECT
public:
    explicit BagTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        multiset = new Bag<int>();
    }
    void cleanup()
    {
        delete multiset;
    }
    void addFindTest()
    {
        multiset->insert(15);
        multiset->insert(45);
        QVERIFY(multiset->find(15));
    }
    void deleteTest()
    {
        multiset->insert(15);
        multiset->insert(45);
        multiset->insert(15);
        multiset->insert(1);
        multiset->insert(-2);
        multiset->remove(1);
        multiset->remove(15);
        multiset->remove(15);
        QVERIFY (!multiset->find(15));
    }
    void quantityTest()
    {
        multiset->insert(15);
        multiset->insert(45);
        multiset->remove(45);
        multiset->insert(15);
        QVERIFY(multiset->size() == 2);
    }
    void iteratorTest()
    {
        multiset->insert(15);
        multiset->insert(45);
        multiset->insert(15);
        multiset->insert(1);
        multiset->insert(-2);
        mIterator = new Bag<int>::iterator(multiset);
        int i = mIterator->next();
        QVERIFY (i == -2);
        for (int k = 0; k < 4; ++k)
            i = mIterator->next();
        QVERIFY (i == 45);
    }
    void addIteratorTest()
    {
        multiset->insert(15);
        multiset->insert(45);
        multiset->insert(15);
        multiset->insert(1);
        multiset->insert(-2);
        mIterator = new Bag<int>::iterator(multiset);
        int i = mIterator->next();
        mIterator->add(5);
        i = mIterator->next();
        i = mIterator->next();
        QVERIFY (i == 5);
    }
    void removeIteratorTest()
    {
        multiset->insert(15);
        multiset->insert(45);
        multiset->insert(15);
        multiset->insert(1);
        multiset->insert(-2);
        *mIterator = Bag<int>::iterator(multiset);
        int i = mIterator->next();
        i = mIterator->next();
        i = mIterator->remove();
        i = mIterator->remove();
        i = mIterator->remove();
        QVERIFY (i == 45);
    }

    void exceptionIteratorTest()
    {
        try
        {
            multiset->insert(15);
            multiset->insert(45);
            multiset->insert(15);
            multiset->insert(1);
            multiset->insert(-2);
            mIterator = new Bag<int>::iterator(multiset);
            for (int k = 0; k < 6; ++k)
                mIterator->next();
        }
        catch (Bag<int>::iterator::DunnoHaveNext)
        {
            QWARN ("There are not elements anymore.");
        }
    }

private:
    Bag<int>* multiset;
    Bag<int>::iterator* mIterator;
};
#endif // BAGTEST_H
