#ifndef POINTERLISTTEST_H
#define POINTERLISTTEST_H
#include <QTest>
#include <QObject>
#include <pointerList.h>

class PointerListTest : public QObject
{
    Q_OBJECT
public:
    explicit PointerListTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        mList = new PointerList();
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


#endif // POINTERLISTTEST_H
