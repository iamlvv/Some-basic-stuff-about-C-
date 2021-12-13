#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
	void push(int data)
	{
		adjList.push_back(data);
		size++;
	}
	void print()
	{
		for (auto const &i : adjList)
			cout << " -> " << i;
	}
	void printArray()
	{
		for (auto const &i : adjList)
			cout << i << " ";
	}
	int getSize() { return adjList.size(); }
	int getElement(int idx) 
	{
		auto it = adjList.begin();
		advance(it, idx);
		return *it;
	}
};


class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	Adjacency *BFS(int v)
    {
        bool *visited = new bool[this->V];
        list<int> queue;
        Adjacency *result = new Adjacency();
        
        for(int i = 0; i < this->V; i++)
            visited[i] = false;

        visited[v] = true;
        queue.push_back(v);

        while(!queue.empty())
        {
            v = queue.front();
            queue.pop_front();
            int i = 0;
            
            result->push(v);
            
            int n = adj[v].getSize();
            
            while(n != 0)
            {
                if (visited[adj[v].getElement(i)] == false)
                {
                    visited[adj[v].getElement(i)] = true;
                    queue.push_back(adj[v].getElement(i));
                }
                n--;
                i++;
            }
        }
        return result;
	}
	void DFS(Adjacency* &result, bool *visited, int v)
	{
	    visited[v] = true;
	    result->push(v);
	    
	    int n = adj[v].getSize();
	    int i = 0;
	    
	    while(n != 0)
        {
            if (visited[adj[v].getElement(i)] == false)
            {
                DFS(result, visited, adj[v].getElement(i));
            }
            n--;
            i++;
        }
	}
	Adjacency *DFS(int v)
    {
        // v is a vertex we start DFS
		bool *visited = new bool[this->V];
	    Adjacency *result = new Adjacency();
	    
	    DFS(result, visited, v);
	    return result;
	}
	void topologicalSort(int v, bool visited[], stack<int> &St)
    {
        visited[v] = true;
	    
	    int n = adj[v].getSize();
	    int i = 0;
	    
	    while(n != 0)
        {
            if (visited[adj[v].getElement(i)] == false)
            {
                topologicalSort(adj[v].getElement(i), visited, St);
            }
            n--;
            i++;
        }
        
        St.push(v);
    }
	void topologicalSort()
    {
        stack<int> St;
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
                topologicalSort(i, visited, St);
        }

        while (St.empty() == false) 
        {
            cout << St.top() << " ";
            St.pop();
        }
    }
};

class DirectedGraph 
{ 
	int V;
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[], bool *rs);
public: 
	DirectedGraph(){
        V = 0;
        adj = NULL;
    }
	DirectedGraph(int V)
	{
		this->V = V; 
		adj = new list<int>[V];
	}
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
	
	
	bool isCyclic()
	{
	    // Student answer
	    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if (checkCyclic(i, visited, recStack))
            return true;
 
    return false;
	}
	bool checkCyclic(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
 
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && checkCyclic(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}
	
}; 
int main() {
    Graph g(6);
g.addEdge(5, 2);
g.addEdge(5, 0);
g.addEdge(4, 0);
g.addEdge(4, 1);
g.addEdge(2, 3);
g.addEdge(3, 1);

g.topologicalSort();
    return 0;
}