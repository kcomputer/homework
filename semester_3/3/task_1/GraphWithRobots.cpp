#include "GraphWithRobots.h"
#include <iostream>
#include <fstream>

GraphWithRobots::GraphWithRobots(char *graphFileName):graphFileName(graphFileName)
{
    verticesQuantity = 0;

    this->insertData(graphFileName);
}


GraphWithRobots::~GraphWithRobots(){
   this->deleteData();
}

void GraphWithRobots::deleteData(){
    for(int i = 0; i < verticesQuantity; i++)
        delete[] graph[i];
    delete[] graph;

    for(int i = 0; i < verticesQuantity; i++)
        delete[] newGraph[i];
    delete[] newGraph;

    delete[] used;
    delete[] robotsLocation;
}

void GraphWithRobots::insertData(char *recievedGraphFileName)
{
    graphFileName = recievedGraphFileName;
    if (verticesQuantity != 0)
    {
        this->deleteData();
    }
    ifstream graphFile;
    graphFile.open(graphFileName);
    if (graphFile.is_open())
    {

        graphFile >> verticesQuantity;
        cout << endl;
        cout << verticesQuantity;
cout << endl;
        graph = new int*[verticesQuantity];
        for (int i = 0; i < verticesQuantity; i++)
        {
            graph[i] = new int[verticesQuantity];
        }

        for (int i = 0; i < verticesQuantity; i++)
        {
            for (int j = 0; j < verticesQuantity; j++)
            {
                graphFile >> graph[i][j];
                cout << graph[i][j] << "   ";
            }
            cout << endl;
        }

        robotsLocation = new int[verticesQuantity];
        for (int i = 0; i < verticesQuantity; i++)
        {
            graphFile >> robotsLocation[i];
            cout <<  robotsLocation[i] << "     ";
        }


        used = new bool[verticesQuantity];

        newGraph = new int*[verticesQuantity];
        for(int i = 0; i < verticesQuantity; i++){
            newGraph[i] = new int[verticesQuantity];
        }

        for(int i = 0; i < verticesQuantity; i++){
            for(int j = 0; j < verticesQuantity; j++){
                newGraph[i][j] = 0;
                cout<< newGraph[i][j];
            }
            cout << endl;
        }
        for (int i = 0; i < verticesQuantity; i++)
        {
            used[i] = false;
        }


        createANewGraph();
    }
    graphFile.close();

}



bool GraphWithRobots::calculteProbability()
{
    bool state = true;
    for(int i = 1; i <= verticesQuantity; i++)
        if(!used[i])
            if(dfs(i) == 1){
                state = false;
                break;
            }
    return state;
}

int GraphWithRobots::dfs(int currentVertex)
{
    used[currentVertex] = true;
    int count = 0;
    if(robotsLocation[currentVertex])
    {
        count++;
    }
    for(int i = 1; i <= verticesQuantity; i++)
    {
        if((newGraph[currentVertex][i] != 0) && (!used[i]))
        {
            count += dfs(i);
        }
    }
    return count;
}

void GraphWithRobots::createANewGraph(){
    for(int u = 0; u <verticesQuantity; u++)
        for(int v = u + 1; v < verticesQuantity; v++)
            for(int mid = 0; mid < verticesQuantity; mid++)
                if ((mid != u) && (mid != v) && graph[u][mid] && graph[v][mid]){
                    newGraph[u][v]=1;
                    newGraph[v][u]=1;
                }
    cout << endl;
    for(int i = 0; i < verticesQuantity; i++){
        for(int j = 0; j < verticesQuantity; j++){

            cout<< newGraph[i][j]<< "    ";
        }
        cout << endl;
    }
}
