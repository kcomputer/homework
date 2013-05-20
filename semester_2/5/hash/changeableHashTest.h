#ifndef CHANGEABLEHASHTEST_H
#define CHANGEABLEHASHTEST_H


#include <QtCore/QObject>
#include <QtTest/QTest>
#include "changeableHash.h"
#include "MyHashFunction.h"

class ChangeableHashTest : public QObject
{
    Q_OBJECT
public:
    explicit ChangeableHashTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        mHasher = new MyHashFunction(157);
        mHash = new ChangeableHash(mHasher, mHasher->arrayLength);
    }
    void cleanup()
    {
        delete mHash;
        delete mHasher;
    }
    void testAddElement()
    {
         mHash->addElement("obama");
         QVERIFY(mHash->isIn("obama"));
    }
    void testIsIn()
    {
        QVERIFY(!mHash->isIn("cocacola"));
        mHash->addElement("cocacola");
        QVERIFY(mHash->isIn("cocacola"));
        mHash->deleteElement("cocacola");
        QVERIFY(!mHash->isIn("cocacola"));

    }
    void testElementsQuantity()
    {
        //QString temp = "meow";
        QVERIFY(!mHash->quantity);
        mHash->addElement("meow");
        QVERIFY(mHash->quantity == 1);
        mHash->addElement("california");
        QVERIFY(mHash->quantity == 2);
        mHash->deleteElement("meow");
        QVERIFY(mHash->quantity == 1);
        mHash->addElement("california");
        QVERIFY(mHash->quantity == 1);
    }
    void testDeleteElement()
    {
        mHash->addElement("baconpancakes");
        QVERIFY(mHash->isIn("baconpancakes"));
        mHash->deleteElement("baconpancakes");
        QVERIFY(!mHash->isIn("baconpancakes"));
    }
private:
    ChangeableHash* mHash;
    HashFunction* mHasher;
};

#endif // CHANGEABLEHASHTEST_H
