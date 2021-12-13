#include <iostream>
#include <queue>
using namespace std;
template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    void    add(T e);
    void    add(int index, T e);
    int     size();
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};
template <class T>
void SLinkedList<T>::add(const T& e) {
    if (this->count == 0) {
            Node *temp = new Node;
            temp->data = e;
            this->head = temp;
            this->tail = temp;
            
        }
        if (this->count != 0) {
            Node *temp = new Node;
            temp->data = e;
            temp->next = nullptr;
            tail->next = temp;
            tail = temp;
            
        }
        count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    if (index == count && count!=0) {
            this->add(e);
            
        }
        else if (this->count == 0) {
            this->add(e);
        }
        else if (index == 0) {
            Node *temp = new Node;
            temp->data = e;
            temp->next = this->head;
            this->head = temp;
            count++;
        }
        else if (index < count) {
            Node *temp = new Node;
            temp->data = e;
            Node *run = this->head;
            for (int i = 0; i < index - 1; i++) {
                run = run->next;
            }
            temp->next = run->next;
            run->next = temp;
            count++;
        }
}

template<class T>
int SLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return this->count;
}

int main() {
    SLinkedList<int> list;
int size = 10;

for(int index = 0; index < size; index++){
    list.add(index);
}

cout << list.toString();
    return 0;
}