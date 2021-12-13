#define SEPARATOR "#<ab@17943918#@>#"
#ifndef SORTING_H
#define SORTING_H
#include <iostream>
using namespace std;
template <class T>
class Sorting {
public:
    static void printArray(T *start, T *end)
    {
        long size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    static void heapify(T *start, int size, int i) {
        int largest = i; 
        int l = 2 * i + 1; 
        int r = 2 * i + 2; 
    if (l < size && start[l] > start[largest])
        largest = l;
    if (r < size && start[r] > start[largest])
        largest = r;
    if (largest != i) {
        T temp = start[i];
        start[i] = start[largest];
        start[largest] = temp;
        heapify(start, size, largest);
    }
    }
    static void heapSort(T* start, T* end){
        //TODO
        int size = end - start;
        for (int i = size / 2 - 1; i >= 0; i--)
        heapify(start, size, i);
    for (int i = size - 1; i > 0; i--) {
        T temp = start[0];
        start[0] = start[i];
        start[i] = temp;
        heapify(start, i, 0);
    }
        Sorting<T>::printArray(start,end);
    }
    
};

int main() {
    int arr[4]={4,2,9,1};
    Sorting<int>::heapSort(&arr[0],&arr[4]);

}
#endif /* SORTING_H */
