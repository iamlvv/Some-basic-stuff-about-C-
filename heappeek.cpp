#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    int getItem(T item);
    void remove(T item);
    void clear();
    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();
    
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int index);
    int getParent(int child);
    int getLeftChild(int child);
    int getRightChild(int child);
    void swap(int &a, int &b);
};

template<class T>
int Heap<T>::size(){
    return this->count;
}

template<class T>
bool Heap<T>::isEmpty(){
    if (this->count == 0) return true;
    return false;
}

template<class T>
T Heap<T>::peek(){
    if (this->count == 0) return -1;
    return this->elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    if (this->count == 0) return false;
    for (int i = 0; i < this->count; i++) {
        if (elements[i] == item) return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if (this->count == 0) return false;
    for (int i = 0; i < this->count; i++) {
        elements[i] = this->elements[i + 1];
    }
    this->count--;
    return true;
}
template<class T>
void Heap<T>::push(T item){
    if (this->count < this->capacity) {
        this->count++;
        elements[this->count - 1] = item;
        reheapUp(this->count-1);
    }
    else if (this->count == this->capacity) {
        ensureCapacity(this->capacity);
        this->count++;
        elements[this->count - 1] = item;
        reheapUp(this->count-1);
    }
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    minCapacity += 1;
    T *newElements = new int[minCapacity];
    for (int i = 0; i < this->count; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    this->capacity = minCapacity;
    elements = newElements;
}

template<class T>
void Heap<T>::reheapUp(int position){
    if (position != 0) {
        int current = (position - 1) / 2;
        if (elements[position] > elements[current]) {
            int temp = elements[position];
            elements[position] = elements[current];
            elements[current] = temp;
            reheapUp(current);
        }
    }
}
template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for (int i = 0; i < this->count; i++) {
        if(elements[i] == item) {
            //reheapDown(i);
            return i;
        }
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    // int index = getItem(item);
    // if(index == -1) return;
    int last_element = elements[this->count - 1];
    elements[0] = last_element;
    this->count--;
    reheapDown(0);
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    this->count = 0;
    elements = NULL;
}
template<class T>
int Heap<T>::getParent(int child) {
    return (child - 1)/ 2;
}
template<class T>
int Heap<T>::getRightChild(int child) {
    return 2*child + 2;
}
template<class T>
int Heap<T>::getLeftChild(int child) {
    return 2*child + 1;
}
template<class T>
void Heap<T>::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
template<class T>
void Heap<T>::reheapDown(int index)
{
    int left = getLeftChild(index);
		if(left < this->count)
		{
            int right = getRightChild(index);
            if (right < this->count) {
                if(elements[left] < elements[right])
			{
				if(elements[index] < elements[right])
				{
					swap(elements[index], elements[right]);
					index = right;
					reheapDown(index);
				}
			}
			else
			{
				if(elements[index] < elements[left])
				{
					swap(elements[index], elements[left]);
					index = left;	
					reheapDown(index);			
				}
			}		
            }
			else
		{
			if (elements[index] < elements[left])
			{
				swap(elements[index], elements[left]);

			}
		}
		}
	}
int main() {
   	
	
Heap<int> maxHeap;
int arr[] = {42,35,30,15,20,21,18,3,7,14};
for (int i = 0; i < 10; i++)
    maxHeap.push(arr[i]);
maxHeap.remove(42);
maxHeap.remove(35);
maxHeap.remove(30);
maxHeap.printHeap();
}