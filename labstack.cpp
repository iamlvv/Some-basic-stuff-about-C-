#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
bool check(vector<vector<int>> graph, int src, int temp[], int size) {
    temp[src] = 1;
    queue<int> hang;
    hang.push(src);
    while (!hang.empty()) {
        int x = hang.front();
        hang.pop();
        if (graph[x][x] == 1) return false;
        for (int i = 0; i < size; i++) {
            if (graph[x][i] && temp[i] == -1) {
                temp[i] = 1 - temp[x];
                hang.push(i);
            }
            else if (graph[x][i] && temp[i] == temp[x]) {
                return false;
            }
        }
        
    }
    return true;
}
bool isBipartite(vector<vector<int>> graph) {
    int size = graph.size();
    int temp[size];
    for (int i = 0; i < size; i++) {
        temp[i] = -1;
    }

    for (int i = 0; i < size; i++) 
        if (temp[i] == -1) 
            if (check(graph, i, temp, size) == false) return false;
        
    
    return true;
}
vector<int> topologicalSorting(vector<vector<int>> graph) {
    vector <int> vec1(graph.size(), 0);
    vector<int> vec2;
    queue<int> q;
    vec2.clear();
    for(unsigned int i = 0; i < graph.size(); i++) {
        for(unsigned int j = 0; j < graph[i].size(); j++)
        { 
            vec1[graph[i][j]]++;
        }
    }
    
    for(unsigned int i = 0; i < graph.size(); i++) 
    {
        if(vec1[i] == 0) {
            q.push(i);
        }
    }
    while(q.size() > 0) {
        int currentNode = q.front();
        q.pop();
        
        for(unsigned int j = 0; j < graph[currentNode].size(); j++)
        { 
            int newNode = graph[currentNode][j];
            vec1[newNode]--;
            if(vec1[newNode] == 0) 
            { 
                q.push(newNode);
            }
        }
         vec2.push_back(currentNode);
    }
    if (vec2[0] == 0 && vec2.size() == 1) vec2.clear();
    return vec2;
}
class ShellSort: public Complex {
static void sortSegment(Complex *list, int length, int increment, int segment = 0) {
    
}
void sort(Complex *list, int length) {
    int interval, i, j, temp;
	for(interval = n/2; interval > 0; interval /= 2){
		for(i = interval; i < n; i++){
			temp = list[i];
			for(j = i; j >= interval && a[j - interval] > temp; j -= interval){
				list[j] = list[j - interval];			
			}
			list[j] = temp;
		}
    }
}
};
int main() {
    int n = 6;
    int G[6][6] = { {0, 1, 0, 1, 0, 0},
                    {0, 0, 1, 1, 0, 0},
                    {0, 0, 0, 1, 1, 1},
                    {0, 0, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0, 1},
                    {0, 1, 0, 0, 0, 0} };
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (G[i][j] == 1) graph[i].push_back(j);
        }
    }

    vector<int> res = topologicalSorting(graph);
    if (res.empty()) printf("-1");
    else {
        for (int e : res) printf("%d ", e);
    }
}