#include <iostream>
#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph
#define Verticies 13

// Function to find the vertex with minimum distance value from the set of 
// vertices not yet included in the minimum spanning tree
int minimumDistance(int distance[], bool spanningSet[])
{
	// Set minimum to arbitrary large value, (2^31) - 1
	int minimum = INT_MAX; 
	int minimum_index;

	for (int vertex = 0; vertex < Verticies; vertex++)
	{ 
		// if vertex is unvisited and distance < INT_MAX
		if ((spanningSet[vertex] == false) && distance[vertex] <= minimum)
		{
			minimum = distance[vertex];
			minimum_index = vertex;
			//printf("\n%d", minimum_index);
		}
		//printf("\n%d", vertex);
	}
	return minimum_index;
}

int main()
{
	
	int graph[Verticies][Verticies] = 
					{{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{1, 0, 15, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 15, 0, 0, 0, 0, 0, 4, 9, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0},
					{0, 5, 0, 0, 0, 5, 0, 0, 0, 0, 7, 0, 0},
					{0, 0, 0, 7, 5, 0, 3, 0, 0, 0, 8, 0, 0},
					{0, 0, 0, 0, 0, 3, 0, 5, 0, 0, 0, 5, 0},
					{0, 0, 4, 0, 0, 0, 5, 0, 0, 4, 0, 0, 0},
					{0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 17, 13},
					{0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 7, 8, 0, 0, 0, 0, 0, 29, 0},
					{0, 0, 0, 0, 0, 0, 5, 0, 17, 0, 29, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0}};

	
	return 0;
}