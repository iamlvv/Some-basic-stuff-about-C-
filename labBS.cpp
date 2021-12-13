#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
    if (left <= right) {
        int mid = (right - left) / 2 + left;
        cout <<  "We traverse on index: " << mid << endl;
        if(arr[mid] == x) return mid;
        else if (arr[mid] > x) return binarySearch(arr, left, mid - 1, x);
        else return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}

int interpolationSearch(int arr[], int left, int right, int x)
{
    if (left <= right && x >= arr[left] && x <= arr[right]) {
        if (left == right) {
            if (arr[left]== x) return left;
            return -1;
        }
        int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (x - arr[left]));
        cout <<  "We traverse on index: " << pos << endl;
        if (arr[pos] == x) return pos;
        else if (arr[pos] < x) return interpolationSearch(arr, pos + 1, left, x);
        else return interpolationSearch(arr, left, pos - 1, x);
    } 
    return -1;
}

int search(int arr[], int x, int i, int m)
{
    if(i >= m)
        return -1;
    else 
    {
        if(arr[i] == x)
        {
            cout<<i<<" ";
            return i;
        }
        else
        {
            cout<<i<<" ";
            return search(arr, x, i + 1, m);
        }
    }
}

int jumpSearch(int arr[], int x, int n, int i, int m)
{
    if(m > n - 1)
    {
        return search(arr, x, i + 1, m);
    }
    
    if(arr[m] >= x)
    {
        if(arr[m] == x)
        {
            cout<<m<<" ";
            return m;
        }
        else
        {
            cout<<m<<" ";
            return search(arr, x, i + 1, m);
        }
    }
    else
    {
        cout<<m<<" ";
        i = m;
        return jumpSearch(arr, x, n, i, m + sqrt(n));
    }
}

int jumpSearch(int arr[], int x, int n) 
{
    int i = 0;
    int m = 0;
    
    return jumpSearch(arr, x, n, i, m);
}

int main() {
    	
	
int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 611, 612, 613 };
int x = 614;
int n = sizeof(arr) / sizeof(arr[0]);
int index = jumpSearch(arr, x, n);

if (index != -1) {
    cout << "\nNumber " << x << " is at index " << index;
}
else {
    cout << "\n" << x << " is not in array!";
}
    return 0;
}