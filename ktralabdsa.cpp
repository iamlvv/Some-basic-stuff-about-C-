#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;
class Node
{
    int data;
    Node* next;
public:
    Node(): data(0), next(nullptr){}

    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }

    int getData()
    {
        return this->data;
    }

    void setData(int data)
    {
        this->data = data;
    }

    Node* getNext()
    {
        return this->next;
    }

    void setNext(Node* next)
    {
        this->next = next;
    }
    void *addTail(Node *l, int x){
	Node *p = l;
	while (p->next != NULL){
		p = p->next;
	}
	Node *temp = new Node;
	temp->data = x;
	temp->next = NULL;
	p->next = temp;
}


};
void reduceDuplicate(Node* root)
{
    Node *temp1 = root;
    Node *temp2 = NULL;
    while (temp1 != NULL && temp1->getNext() != nullptr){
        temp2 = temp1->getNext();
        while (temp2 != nullptr && temp1->getData() == temp2->getData()) {
            if (temp2->getNext() != NULL) {
                Node *x = temp2->getNext();
                temp1->setNext(x);
            }
            else temp1->setNext(NULL);
            temp2 = temp2->getNext();
        }
        temp1 = temp1->getNext();
    }
}
void printList(Node *root) {
    while (root != NULL) {
        cout << root->getData() << " ";
        root = root->getNext();
    }
    cout << endl;
}
class PrinterQueue
{
    // your attributes
    vector<string> root;
    int *temp = new int[1000];
public:
    // your methods
    void swap (int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void addNewRequest(int priority, string fileName)
    {
        // your code here
        root.push_back(fileName);
        temp[root.size() - 1] = priority;
    }

    void print()
    {
        // your code here
        // After some logic code, you have to print fileName with endline
        for(unsigned int i = 0; i < root.size() - 1; i++){
        for(unsigned int j = i + 1; j < root.size(); j++){
            if(temp[i] < temp[j]){
                // Hoan vi 2 so a[i] va a[j]
                int x = temp[i];
                temp[i] = temp[j];
                temp[j] = x;        
            }
        }
    }
    
    }
};
class Neighbor {
public:
    string majorityNeighbor(vector<string>& neighbor) {
        int size = neighbor.size();
        int* contain = new int[size];
        for (unsigned int i = 0; i < neighbor.size(); i++) {
            int dem = 1;
            contain[i] = dem;
            for (unsigned int j = i + 1; j < neighbor.size(); j++) {
                if (neighbor[i] == neighbor[j]) {
                    contain[i] = ++dem;
                }
            }
        }
        int max = 0, index = 0;
        for (unsigned int i = 0; i < neighbor.size(); i++) {
            if (contain[i] >= max) {
                max = contain[i];
                index = i;
            }
        }
        delete[]contain;
        return neighbor[index];
    }
};
int main() {
    // vector<string> nums = { "Peter","Bob","Andrew","Peter","Bob","Peter","Bob","Peter" };
    // Neighbor s;
    // cout << s.majorityNeighbor(nums);
    Node* node1 = new Node(1, nullptr);
    Node* node2 = new Node(1, node1);
    Node* node3 = new Node(0, node2);
    printList(node3);
    reduceDuplicate(node3);
    printList(node3);
    return 0;
}