#ifndef NETWORKTEST_H
#define NETWORKTEST_H

#include "RandomNumberGeneratorInterface.h"
#include <iostream>
#include <QObject>
#include "network.h"
#include <sstream>
#include "notRandomNumberGenerator.h"

class NetworkTest : public QObject
{
    Q_OBJECT
public:
    explicit NetworkTest(QObject *parent = 0): QObject(parent){}
private slots:
    void init()
    {
        randomizer = new NotRandomNumberGenerator();

        computers[0] = new Computer(new(Mac), 1, randomizer);
        computers[1] = new Computer(new(Windows), 1, randomizer);
        computers[2] = new Computer(new(Mac), 0, randomizer);
        computers[3] = new Computer(new(Linux), 0, randomizer);
        computers[4] = new Computer(new(Windows), 0, randomizer);
        computers[5] = new Computer(new(Linux), 0, randomizer);
        computers[6] = new Computer(new(Windows), 0, randomizer);
        computers[7] = new Computer(new(Mac), 1, randomizer);
        computers[8] = new Computer(new(Linux), 0, randomizer);
        computers[9] = new Computer(new(Linux), 1, randomizer);

        const int constNet[10][10] =
        {
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 1, 0, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 1, 0}
        };

        int** net = new int*[10];
        for(int i = 0; i < 10; ++i)
            net[i] = new int[10];

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                net[i][j] = constNet[i][j];
            }
        }
        testNetwork = new Network(computers, net);
    }

    void networkRunTest()
    {
        testNetwork->run();
        QCOMPARE(testNetwork->check(), true);
    }

    void cleanup()
    {
        for (int i = 0; i < 10; i++)
        {
            delete computers[i];
        }
        delete testNetwork;
    }
private:
    RandomNumberGeneratorInterface* randomizer;
    Computer* computers[10];
    Network* testNetwork;
};

#endif // NETWORKTEST_H
