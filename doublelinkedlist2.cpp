#include <iostream>
#include <stack>
#include <queue>
#include <assert.h>
using namespace std;
class IntDLinkedList
{
private:
    class Node;
private:
    Node *head;
    Node *tail;
    int count;
public:
    IntDLinkedList() : head(NULL), tail(NULL), count(0) {}
    ~IntDLinkedList()
    {
        this->clear();
    }
    void add(int element) {
        if (this->count == 0) {
            Node *temp = new Node;
            temp->value = element;
            this->head = temp;
            this->tail = temp;
            this->count++;
        }
        else {
            Node *temp = new Node;
            temp->value = element;
            temp->next = nullptr;
            temp->prev = this->tail;
            this->tail->next = temp;
            this->tail = temp;
            this->count++;
        }
        
    }
    void add(int index, int element) {
        if (index < 0 || index > this->count) throw std::out_of_range("Index is out of range");
        if (index == this->count ||this->count == 0 ) {
            return this->add(element);
            
        }
        if (index == 0) {
            Node *temp = new Node;
            temp->value = element;
            temp->next = this->head;
            this->head->prev  = temp;
            this->head = temp;
            this->count++;
            return;
        }   
            Node *run = this->head;
            for (int i = 0; i < index - 1; i++) {
                run = run->next;
            }
            Node *current = run->next;
            Node *temp = new Node;
            temp->value = element;
            temp->next =current;
            temp->prev = run;
            run->next = temp;
            current->prev = temp;
            this->count++;
        
    }
    bool empty() {
        if (this->count == 0) return true;
        return false;
    }

    int size() {
        return this->count;
    }
    int removeAt(int index) {
        int rem;
        if (index < 0 || index > count - 1 || count == 0) throw std::out_of_range("Index is out of range");
        if (this->count == 1) {
            rem = this->head->value;
            this->head = nullptr;
            this->tail = nullptr;
            this->count--;
        }
        else if (index == 0) {
            Node *p = this->head->next;
            Node *temp = this->head;
            p->prev = nullptr;
            rem = this->head->value;
            this->head = p;
            delete(temp);
            this->count--;
        }
        else if (index == this->count - 1) {
            Node *p = this->tail->prev;
            Node *temp = this->tail;
            rem = temp->value;
            p->next = nullptr;
            this->tail = p;
            delete(temp);
            this->count--;
        }
        else if (index > 0 && index < this->count) {
            Node *run = this->head;
            for (int i = 0; i < index - 1; i++) {
                run = run->next;
            }
            Node *temp = run->next;
            run->next = temp->next;
            run->next->prev = temp;
            rem = temp->value;
            delete(temp);
            this->count--;
        }
            
            return rem;
    }
    bool removeItem(int item) {
        if (count == 0) throw std::out_of_range("Index is out of range");
        else {
            int pos = 0;
            bool flag = false;
            Node *temp = this->head;
            for (int i = 0; i < count; i++) {
                if (temp->value == item) {
                    pos = i;
                    flag = true;
                    break;
                }
            }
            if (flag == true) {
                this->removeAt(pos);
                return false;
            }
        }
        return true;
    }
    int get(int index) {
         if (index >= count || count == 0) throw std::out_of_range("Index is out of range");
         else {
             
             Node *temp = this->head;
             for (int i = 0; i < count; i++) {
                 if (i == index) {
                     return temp->value;
                 }
                 temp = temp->next;
             }
         }
         return -1;
    }
    void set(int index, int element) {
        if (index >= count || count == 0) throw std::out_of_range("Index is out of range");
        else {
            Node *temp = this->head;
            for (int i = 0; i < count; i++) {
                if (i == index) {
                    temp->value = element;
                }
                temp = temp->next;
            }
        }
    }
    int indexOf(int item) {
        if (count == 0) throw std::out_of_range("Index is out of range");
        else {
            Node *temp = this->head;
            for (int i = 0; i < count; i++) {
                if (temp->value == item) {
                    return i;
                }
                temp = temp->next;
            }
        }
        return -1;
    }
    bool contains(int element) {
        if (this->count == 0) throw std::out_of_range("Index is out of range");
        else {
            Node *temp = this->head;
            for (int i = 0; i < count; i++) {
                if (temp->value == element) return true;
                temp = temp->next;
            }
        }
        return false;
    }
    void clear() {

    }
    void dump()
    {
        if (this->count == 0)
        {
            assert(this->head == NULL);
            assert(this->tail == NULL);
            cout << "List: []" << endl;
            cout << "Reverse list: []" << endl;
            return;
        }
        
        cout << "List: [";
        Node *temp = this->head;
        while (temp != this->tail)
        {
            cout << temp->value << ",";
            temp = temp->next;
        }
        cout << temp->value << "]" << endl;
        cout << "Reverse list: [";
        temp = this->tail;
        while (temp != this->head)
        {
            cout << temp->value << ",";
            temp = temp->prev;
        }
        cout << temp->value << "]" << endl;
    }
    
private:
    class Node
    {
    public:
        int value;
        Node *prev;
        Node *next;
        Node(int value = 0, Node *prev = NULL, Node *next = NULL) : value(value), prev(prev), next(next) {}
    };
};

int main() {
	
	
IntDLinkedList list;
int values[]   = {10, 15, 2,  6,  4,  7,  40,  8};
int index[]    = {0,  0,  1,  3,  2,  3,  5,   0};
for (int idx = 0; idx < 8; idx++){
   list.add(index[idx], values[idx]);
}

for (int idx = 0; idx < 8; idx++){
   int removed = list.removeAt(4);
   cout << removed << endl;
}
list.dump();
return 0;
}