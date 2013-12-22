#ifndef GRAPH_H
#define GRAPH_H

#include "string"

using namespace std;


//! A class that represents a graph with robots on its vertices.
//! Can calculate probability if all robots are distracted.
class GraphWithRobots
{
public:
    GraphWithRobots(string *graphFileName);
    ~GraphWithRobots();
    void insertData(string *recievedGraphFileName);
    bool calculteProbability();

private:
    void deleteData();

    string *graphFileName;

    int verticesQuantity;


    int *robotsLocation;

    bool* used;
    int **graph;
    int** newGraph;


    void createANewGraph();
    int dfs(int v);

};
#endif // GRAPH_H
