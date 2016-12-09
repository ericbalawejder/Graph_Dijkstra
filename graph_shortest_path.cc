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

// Function to print shortest path from source to destination using spanningTree array
void printSpanningTree(int spanningTree[], int vertex)
{
	// Base Case, vertex is starting point
	if (spanningTree[vertex] == -1)
	{
		return;
	}
	printSpanningTree(spanningTree, spanningTree[vertex]);
	// print the path
	printf("-> %d ", vertex);
}

// A function to print the distance array
void print(int distance[], int n, int spanningTree[])
{
	int start = 0;
	printf("Vertex\t   Distance\tPath");
	for (int i = 1; i < Verticies; i++)
	{
		printf("\n%d --> %d %8d %8d ", start, i, distance[i], start);
		printSpanningTree(spanningTree, i);
	}
	printf("\n");
}

// Funtion that implements Dijkstra's algorithm for a graph represented 
// using an adjacency matrix 
void dijkstraAlgorithm(int graph[Verticies][Verticies], int start)
{
	// distance[] will hold the shortest distance[i] from start to i
	int distance[Verticies]; 

	// spanningSet[i] will be true if vertex i is included in the spanning tree
	bool spanningSet[Verticies];

	// spanningTree array to store shortest path tree
	int spanningTree[Verticies];

	// Initialize all distances as infinite (INT_MAX) and spanningSet[] as false
	for (int i = 0; i < Verticies; i++)
	{
		// initialize to a vertex value not in the graph to start from
		spanningTree[0] = -1;
		distance[i] = INT_MAX;
		spanningSet[i] = false;
	}

	// Distance of source vertex from itself is always 0
	distance[start] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < Verticies - 1; count++)
	{
		// Pick the minimum distance vertex from the set of
		// vertices not yet visted. u is always equal to start
		// in first iteration.
		int u = minimumDistance(distance, spanningSet);

		// Mark the picked vertex as visited
		spanningSet[u] = true;

		// Update distance value of the adjacent vertices of the picked vertex.
		for (int vertex = 0; vertex < Verticies; vertex++)
		{
			// Update distance[vertex] only if is not in spanningSet, there is
			// an edge from u to vertex, and total weight of path from
			// start to vertex through u is smaller than current value of
			// distance[vertex]
			if (!spanningSet[vertex] && graph[u][vertex] && distance[u] + graph[u][vertex] < distance[vertex])
			{
				spanningTree[vertex] = u;
				distance[vertex] = distance[u] + graph[u][vertex];
			} 
		}
	}

	// print the distance values array
	print(distance, Verticies, spanningTree);
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

	// pass dijkstraAlgorithm the graph and starting point
	dijkstraAlgorithm(graph, 0);

	return 0;
}