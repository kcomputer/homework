#include "network.h"
#include <iostream>;

using namespace std;


void Network::run()
{
    int step = 0;
    if (!check())
    {
        do
        {
            step++;
            this->networkState(step);
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (this->net[i][j])
                    {

                        if (this->computers[i]->isInfected())
                            this->computers[j]->virus();
                    }

                }
            }
        } while (!check());
        this->networkState(++step);
    }
}
bool Network::check()
{
    int k = 0;
    for (int i = 0; i < 10; i++)
    {
        if (this->computers[i]->isInfected())
            k++;
    }
    return (k > 9);
}

void Network::networkState(int step)
{

    cout << "Step number:" << step << endl;
    for (int i = 0; i < 10; i++)
    {
        if (this->computers[i]->isInfected())
        {
            cout << "Computer # " << i << " is infected";
        }
        else
        {
            cout << "Computer # " << i << " isn't' infected";
        }
        cout << endl;
    }
}

