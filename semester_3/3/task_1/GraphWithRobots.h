#ifndef GRAPH_H
#define GRAPH_H

#include "string"

using namespace std;


//! A class that represents a graph with robots on its vertices.
//! Can calculate probability if all robots are distracted.
class GraphWithRobots
{
public:
    GraphWithRobots(char *graphFileName);
    ~GraphWithRobots();
    void insertData(char *recievedGraphFileName);
    bool calculteProbability();

private:
    void deleteData();

    char *graphFileName;

    int verticesQuantity;


    int *robotsLocation;

    bool* used;
    int **graph;
    int** newGraph;


    void createANewGraph();
    int dfs(int v);

};
#endif // GRAPH_H
