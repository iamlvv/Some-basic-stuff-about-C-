#include <iostream>
using namespace std;

template <class T>
class Sorting
{
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void oddEvenSort(T *start, T *end);
};
template <class T>
void Sorting<T>::oddEvenSort(T *start, T *end)
{
    int size = end - start;
    bool flag = false;
    while (!flag) {
        flag = true;

        for (int i = 0; i <= size - 2; i += 2) {
            if (start[i] > start[i + 1]) {
                T temp = start[i];
                start[i] = start[i + 1];
                start[i + 1] = temp;
                flag = false;
            }
        }

        for (int i = 1; i <= size - 2; i += 2) {
            if (start[i] > start[i + 1]) {
                T temp = start[i];
                start[i] = start[i + 1];
                start[i + 1] = temp;
                flag = false;
            }
        }
        printArray(start, end);
    }
    return;
}
int main() {
    int arr[] = {3, 2, 3, 8, 5, 6, 4, 1};
Sorting<int>::oddEvenSort(&arr[0], &arr[8]);
return 0;
}