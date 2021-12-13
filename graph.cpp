#include <iostream>
#include <string>
#include <map>
using namespace std;
class Graph
{
private:
    map<string, int> dictionary;
    int **data;
    int numOfVertices;
    bool isWeightedGraph;
    bool isDirectedGraph;

protected:
    // Increase capacity of adjacency matrix and return current number of vertices
    int ensure(int newNumOfVertices)
    {
        if (this->numOfVertices >= newNumOfVertices)
            return this->numOfVertices;

        int **newData = new int *[newNumOfVertices];
        for (int i = 0; i < newNumOfVertices; i++)
        {
            newData[i] = new int[newNumOfVertices];
            for (int j = 0; j < newNumOfVertices; j++)
            {
                if (i < this->numOfVertices && j < this->numOfVertices)
                {
                    newData[i][j] = this->data[i][j];
                }
                else
                    newData[i][j] = 0;
            }
        }

        for (int i = 0; i < numOfVertices; i++)
        {
            delete[] this->data[i];
        }
        delete[] this->data;

        this->data = newData;

        int currentNumOfVertices = this->numOfVertices;
        this->numOfVertices = newNumOfVertices;

        return currentNumOfVertices;
    }

    string getName(int index)
    {
        map<string, int>::iterator it;
        for (it = this->dictionary.begin(); it != this->dictionary.end(); ++it)
        {
            if (it->second == index)
                return it->first;
        }
        return "";
    }

public:
    Graph(bool isWeighted = false, bool isDirected = false)
    {
        this->isWeightedGraph = isWeighted;
        this->isDirectedGraph = isDirected;
        this->numOfVertices = 0;
        this->data = NULL;
    }

    void addVertex(string vName)
    {
        
    }

    void addVertices(string vNameList[], int numToAdd)
    {
        
    }

    void addEdge(string sourceName, string destinationName, int weight = 1)
    {
        
    }

    void removeEdge(string sourceName, string destinationName)
    {
        
    }

    void dump()
    {
        for (int i = 0; i < this->numOfVertices; ++i)
        {
            string sourceName = this->getName(i);
            cout << "Vertex " << sourceName << ":" << endl;
            for (int j = 0; j < this->numOfVertices; ++j)
            {
                string destinationName = this->getName(j);
                if (this->data[i][j] != 0)
                    cout << "   -> To " << destinationName << (this->isWeightedGraph ? ": " + to_string(this->data[i][j]) : "") << endl;
            }
        }
    }

    ~Graph()
    {
        for (int i = 0; i < numOfVertices; i++)
        {
            delete[] this->data[i];
        }
        delete[] this->data;
    }
};

int main() {
    Graph* g = new Graph();
int numOfVertices = 3;
string vertices[] = {"A", "B", "C"};
g->addVertices(vertices, numOfVertices);

g->addEdge("A", "B");
g->addEdge("C", "A");

g->dump();

delete g;

delete g;
}