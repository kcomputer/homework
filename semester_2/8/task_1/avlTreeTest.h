#ifndef AVLTREETEST_H
#define AVLTREETEST_H

#include <QtCore/QObject>
#include <QtTest/QTest>
#include "avlTree.h"

using namespace std;

class avlTreeTest : public QObject
{
    Q_OBJECT
public:
    explicit avlTreeTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        tree = new AVLTree<int>();
    }
    void cleanup()
    {
        delete tree;
    }

    void addFindTest()
    {
        tree->addElement(tree->root,15);
        tree->addElement(tree->root,15);
        tree->addElement(tree->root,11);
        tree->addElement(tree->root,12);
        QVERIFY(tree->find(tree->root,15) != NULL);
    }
    void deleteTest()
    {
        tree->addElement(tree->root,15);
        tree->addElement(tree->root,15);
        tree->addElement(tree->root,4);
        tree->addElement(tree->root,11);
        tree->addElement(tree->root,-2);
        tree->removeElement(tree->root,15);
        tree->removeElement(tree->root,15);
        QVERIFY(tree->find(tree->root,15) == NULL);
    }

    void nodeCounterTest()
    {
        tree->addElement(tree->root,11);
        tree->addElement(tree->root,12);
        QVERIFY(tree->nodeCounter == 2);
    }
    void elementsCounterTest()
    {
        tree->addElement(tree->root,15);
        tree->addElement(tree->root,15);
        tree->addElement(tree->root,11);
        tree->addElement(tree->root,12);
        QVERIFY(tree->elementsCounter == 4);
    }

    void heightTest()
    {
        tree->addElement(tree->root,15);
        tree->addElement(tree->root,11);
        tree->addElement(tree->root,12);
        tree->addElement(tree->root,20);
        QVERIFY(tree->height(tree->root) == 3);
    }
private:
    AVLTree<int>* tree;
};

#endif // AVLTREETEST_H
