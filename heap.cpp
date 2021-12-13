#include <iostream>

using namespace std;
class Heap {
private:
    int* data;
    int size;
public:
    Heap() {
        this->data = NULL;
        this->size = 0;
    }
    
    void copyFromArray(int* arr, int n) {
        this->size = n;
        this->data = new int[this->size];
        for (int i = 0; i < this->size; i++) {
            this->data[i] = arr[i];
        }
    }
    
    
    void reHeapUp(int index) {
        if (index == 0) return;
        int parent = float((index -1) / 2.0);
        if (this->data[index] > this->data[parent]) {
            swap(this->data[index], this->data[parent]);
            reHeapUp(parent);
        }
    }   
    void reHeapDown(int index) {
        int left = index * 2 + 1;
        if (left >= this->size) return;
        
        int right = 2 * index + 2;
        {
            if (right >= this->size) {
                if (this->data[left] > this->data[index]) {
                    swap(this->data[left], this->data[index]);
                    reHeapDown(left);
                }
            }
            else {
                int child = (this->data[left] >= this->data[right]) ? left : right;
                if (this->data[child] > this->data[index]) {
                    swap(this->data[child], this->data[index]);
                    reHeapDown(child);
                }
            }
        }
    }   
    void insert(int key) {
        this->size += 1;
        this->data[this->size -1] = key;
        reHeapUp(this->size - 1);
    }   
    void build(int* arr, int n) {
        int start = n / 2;
        for (int i = start; i >= 1; i--) {
            reHeapDown(i);
        }
    }
    void print() {
        for (int i = 0; i < this->size; i++) {
            cout << this->data[i] << " ";
        }
    }
};
int rec(int n) {
    if (n == 0) return 1;
    if (n == 1) return 4;
    return 3 * rec(n - 1) + 4 * rec(n - 2);
}
int main() {
    cout << rec(4) << endl;
return 0;
}