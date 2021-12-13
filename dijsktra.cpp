#include <iostream>

using namespace std;

int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < 6; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

int dijkstra(int **graph, int src, int dst)
{
    int dist[6]; // The output array.  dist[i] will hold the shortest
    // distance from src to i
 
    bool sptSet[6]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < 6; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < 6 - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < 6; v++)
 
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    // print the constructed distance array
    //printSolution(dist, 6);
    return dist[dst];
}
int Dijkstra(int** graph, int src, int dst) {
	// TODO: return the length of shortest path from src to dst.
    return dijkstra(graph, src, dst);
	
}

int main() {
    int n = 6;
int init[6][6] = {
	{0, 10, 20, 0, 0, 0},
	{10, 0, 0, 50, 10, 0},
	{20, 0, 0, 20, 33, 0},
	{0, 50, 20, 0, 20, 2},
	{0, 10, 33, 20, 0, 1},
	{0, 0, 0, 2, 1, 0} };

int** graph = new int*[n];
for (int i = 0; i < n; ++i) {
	graph[i] = init[i];
}

cout << Dijkstra(graph, 0, 0);
    return 0;
}