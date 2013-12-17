#ifndef NETWORK_H
#define NETWORK_H
#include "mac.h"
#include "linux.h"
#include "windows.h"
#include "computer.h"
#include "QTest"

#include <iostream>

using namespace std;

//! A class representing a local network with.

class Network
{
public:
    Network(Computer** computers, int** recievedNet): computers(computers), net(recievedNet){}
    void run();
    bool check();

private:
    Computer** computers;
    void networkState(int step);
    int** net;
};

#endif // NETWORK_H
