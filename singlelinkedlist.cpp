#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class IntSLinkedList {
public:
    class Node; // Forward declaration

private:
    Node* head;
    Node* tail;
    int count;

public:
    IntSLinkedList() : head(NULL), tail(NULL), count(0) {};
    void add(int element) {
        if (this->count == 0) {
            Node *temp = new Node;
            temp->data = element;
            this->head = temp;
            this->tail = temp;
            
        }
        if (this->count != 0) {
            Node *temp = new Node;
            temp->data = element;
            temp->next = nullptr;
            tail->next = temp;
            tail = temp;
            
        }
        count++;
    }
    Node* dem(Node *p, int index) {
        
        if (index - 1 == 0) return p;
        
            return dem(p->next, index - 1);
        
    }
    void add(int index, int element) {
        if (index > count) throw std::out_of_range("Index is out of range");
        if (index == count && count!=0) {
            this->add(element);
            
        }
        else if (this->count == 0) {
            this->add(element);
        }
        else if (index == 0) {
            Node *temp = new Node;
            temp->data = element;
            temp->next = this->head;
            this->head = temp;
            count++;
        }
        else if (index < count) {
            Node *temp = new Node;
            temp->data = element;
            Node *run = this->head;
            run = dem(this->head, index);
            
            temp->next = run->next;
            run->next = temp;
            count++;
        }
    }
    Node *xremove1(Node *p, int index) {
        if (index - 1 == 0) return p;
        return xremove1(p->next, index - 1);
    }
    Node *xremove2(Node *p, int index) {
        if (index == 0) return p;
        return xremove2(p->next, index - 1);
    }
    int removeAt(int index) {
        Node*temp1 = this->head;
        Node*temp2 = new Node;   
    if (index < 0 || index > count - 1 || count == 0) throw std::out_of_range("Index is out of range");
        int rem;
    if (index == 0)
    {
        rem = this->head->data;
        this->head = this->head -> next;
        temp2 -> next = NULL;
        delete temp2;
        count--;
    }
    else if (index > 0 && index < count - 1) 
    {
        temp1 = xremove1(this->head, index);
        temp2 = temp1->next;
        rem = temp2->data;
        temp1->next = temp2 -> next;
        temp2 -> next = NULL;
        delete temp2;
        count--;
    }
    else if (count == 1) {
        rem = this->head->data;
        
        count--;
    }
    else if (index == count - 1) {
        Node *run = this->head;
        
        run = xremove2(this->head, index);
        rem = run->data;
        Node *temp3 = this->head;
        
        temp3 = xremove2(this->head, index);
        temp3->next = nullptr;
        this->tail = temp3;
        count--;
    }
    return rem;
    }
    int xremoveitem(Node *node, int item, int i) {
        if (node == nullptr) return -1;
        if (node->data == item) return i;
        int ans = xremoveitem(node->next, item, i+1);
        return ans;
    } 
    bool removeItem(int item) {
        if (count == 0) throw std::out_of_range("Index is out of range");
        else {
            
            int pos = xremoveitem(this->head, item, 0);
            if (pos == -1) {
                return false;
                
            }
            this->removeAt(pos);
                return true;
        }
    }

    bool empty() {
        if (this->count == 0) return true;
        return false;
    }

    int size() {
        return this->count;
    }
    Node *xget(Node *p, int index) {
        if (index == 0) return p;
        return xget(p->next, index - 1); 
    }
    int get(int index) {
        if (index >= count || count == 0) throw std::out_of_range("Index is out of range");
        else {
            Node *temp = xget(this->head, index);
            return temp->data;
        }
        
    }

    void set(int index, int element) {
        
        if (index >= count || count == 0) throw std::out_of_range("Index is out of range");
        else {
            
            Node *temp = xget(this->head, index);
            temp->data = element;
        }
    }
    int xindex(Node *p, int item, int i) {
        if (p == nullptr) return -1;
        if (p->data == item) return i;
        int ans = xindex(p->next, item, i+1);
        return ans;
    }
    int indexOf(int item) {
        if (count == 0) throw std::out_of_range("Index is out of range");
        else {
        return xindex(this->head, item, 0);
        }
        return -1;
    }
    int xcontain(Node *p, int item, int i) {
        if (p->data == item) return i;
        if (p == nullptr) return -1;
        int ans = xcontain(p->next, item, i++);
        return ans;
    }
    bool contains(int item) {
        if (this->count == 0) throw std::out_of_range("Index is out of range");
        else {
        int i = xcontain(this->head, item, 0);
        if (i == -1) return false;
        return true;
    }
    }
    
    
    void RemoveHead(int index)
{
	if (this->head != NULL)
	{
		Node* node = this->head;
		this->head = node->next;
		delete node;         
		if (this->head == NULL)
			this->tail = NULL;
		count--;
	}
}
    
    void clear() {
        this->tail = nullptr;
        count = 0;
        this->head = nullptr;

    }
    
    
    string toString() {
        
    }

public:
    class Node {
    public:
        int data;
        Node* next;

    public:
        Node() : next(NULL) {};
        Node(int data) : 
            data(data), next(NULL) {};
    };
};

int main() {
    // Test: Adding items (append)
IntSLinkedList list;
int values[]   = {10, 15, 2,  6,  4,  7,  40,  8};
int index[]    = {0,  0,  1,  3,  2,  3,  5,   0};
for (int idx = 0; idx < 8; idx++){
   list.add(index[idx], values[idx]);
}
cout << list.toString() << endl;
list.clear();
cout << list.toString();
}
