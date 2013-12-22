#include "GraphWithRobots.h"
#include <iostream>
#include <fstream>

GraphWithRobots::GraphWithRobots(string *graphFileName):graphFileName(graphFileName)
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

void GraphWithRobots::insertData(string *recievedGraphFileName)
{
    graphFileName = recievedGraphFileName;
    if (verticesQuantity != 0)
    {
        this->deleteData();
    }
    ifstream graphFile;
    graphFile.open(graphFileName->c_str());
    if (graphFile.is_open())
    {
        graphFile >> verticesQuantity;

        graph = new int*[verticesQuantity];
        for (int i = 0; i < verticesQuantity; i++)
        {
            graph[i] = new int[verticesQuantity];
        }

        for (int i = 0; i < verticesQuantity; i++)
        {
            for (int j = 0; i < verticesQuantity; i++)
            {
                graphFile >> graph[i][j];
            }
        }

        robotsLocation = new int[verticesQuantity];
        for (int i = 0; i < verticesQuantity; i++)
        {
            graphFile >> robotsLocation[i];
        }


        used = new bool[verticesQuantity];

        newGraph = new int*[verticesQuantity];
        for(int i = 0; i < verticesQuantity; i++){
            newGraph[i] = new int[verticesQuantity];
        }

        for(int i = 0; i < verticesQuantity; i++){
            for(int j = 0; j < verticesQuantity; j++){
                newGraph[i][j] = 0;
            }
        }
        memset(used, 0, sizeof (used));


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
    for(int u = 1; u <=verticesQuantity; u++)
        for(int v = u+1; v <= verticesQuantity; v++)
            for(int mid = 1; mid <= verticesQuantity; mid++)
                if ((mid != u) && (mid != v) && graph[u][mid] && graph[v][mid]){
                    newGraph[u][v]=1;
                    newGraph[v][u]=1;
                }
}
