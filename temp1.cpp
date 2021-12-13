#include <iostream>
using namespace std;

class SLinkedList {
    private:
    Node *head;
    int size;
    public:
class Node {
    double x, y, z;
    Node *head;
    double distance;
};
    SLinkedList() {
        this->head = nullptr;
        this->size = 0;
        this->distance = 0;
    }
    
};
    void insert(SLinkedlist &list, int index) {
        //Insert at the end of the list
    }
    double EuclideanDistance(double x, y, z) {
        //Calculate the Euclidean distance
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }   
    double returnmax(SLinkedlist &list, Node *head) {
        //return the distance max
        Node *temp = list.head;
        for (int i = 0; i < b.size; i++) {
            temp->distance = EuclideanDistance(temp->x, temp->y, temp->z);
            temp = temp->next;
        }
        Node *run = b.head;
        double max = run->distance;
        for (int i = 0; i < b.size; i++) {
            if (run->distance > max) max = run->distance;
            run = run->next;
        }
        return max;
    }
    int main() {
        SLinkedlist b;
    }