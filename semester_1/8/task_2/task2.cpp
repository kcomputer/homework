#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

void implementingDijkstra (int matrix[100][100], bool visited[], int distances[], int n)
{
	for (int i = 1; i <= n; ++i)
	{
		int currentCity = 0;
		while (visited[currentCity])
		{
			currentCity++;
		}
		for (int jimm = 1; jimm <= n; ++jimm)
		{
			if ((!visited[jimm]) && (distances[jimm] < distances[currentCity]))
			{
				currentCity = jimm;
			}
		}
		visited[currentCity] = 1;
		cout << currentCity << " the shortest distance: " << distances[currentCity] << endl;
		for (int jimm = 1; jimm <= n; ++jimm)
		{
            		if ((matrix[currentCity][jimm]) && (!visited[jimm]))  
			{
                		if (distances[currentCity] + matrix[currentCity][jimm] < distances[jimm])
				{
                    			distances[jimm] = distances[currentCity] + matrix[currentCity][jimm];
				}
			}
		}
	}
}


int main()
{
	ifstream input("input.txt", ifstream::in);
	int m = 0;
	int n = 0;
	if (input.good())
	{
		input >> n >> m;
		int i = 0;
		int j = 0;
		int length = 0;
		int matrix[100][100];
		bool *visited = new bool[n + 1];
		int *distances = new int[n + 1];
		for (int k = 1; k <= n; ++k)
		{
			visited[k] = 0;
			distances[k] = INT_MAX;
			for (int q = 1; q <= n; ++q)
			{
				matrix[k][q] = 0;
			
			}	
		}
		distances[1] = 0;
		for (int k = 1; k <= m; ++k)
		{
			input >> i >> j >> length;
			matrix[i][j] = length;
			matrix[j][i] = length;
		}
		implementingDijkstra (matrix, visited, distances, n);
		delete[] distances;
		delete[] visited;
	}
	else
	{
		cout << "Error! Something is wrong with input file.\n";
	}
	return 0;
}
