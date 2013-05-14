#pragma once
#include <QtCore/QObject>
#include <QtTest/QTest>
#include "priorityQueue.h"

class PriorityQueueTest : public QObject
{
    Q_OBJECT
public:
    explicit PriorityQueueTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        queue = new PriorityQueue<int>();
    }
    void cleanup()
    {
        delete queue;
    }
    void enquueueDequeue()
    {
        queue->enqueue(11, 5);
        queue->enqueue(18, 5);
        queue->enqueue(41, 9);
        queue->enqueue(71, 10);
        queue->dequeue();
        queue->enqueue(18, 5);
        queue->enqueue(41, 9);
        QVERIFY(queue->dequeue() == 41);
        QVERIFY(queue->dequeue() == 11);
        QVERIFY(queue->dequeue() == 18);
    }
    void dequeueExeption()
    {
        try
        {
            queue->dequeue();
        }
        catch (PriorityQueue<int>::EmptyQueue)
        {
            QWARN("Queue is empty!");
        }
    }

private:
    PriorityQueue<int>* queue;
};

