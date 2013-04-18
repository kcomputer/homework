#ifndef ARRAYLISTTEST_H
#define ARRAYLISTTEST_H
#include <QTest>
#include <QObject>
#include <arrayList.h>
#include "arraylist.h"


//! Testing array list.


class ArrayListTest : public QObject
{
    Q_OBJECT
public:
    explicit ArrayListTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        mList = new ArrayList();
    }
    void cleanup()
    {
        delete mList;
    }

    void testIsIn_and_Add()
    {
        mList->add(50);
        mList->add(87);
        mList->add(550);
        QVERIFY(mList->isIn(50));
    }
    void testLength()
    {
        mList->add(50);
        mList->add(87);
        mList->add(550);
        QVERIFY(mList->length() == 3);
    }
    void testRemove()
    {
        mList->add(50);
        mList->add(87);
        mList->add(550);
        mList->remove(87);
        QVERIFY(!mList->isIn(87));

    }
private:
    List* mList;
};

#endif // ARRAYLISTTEST_H
