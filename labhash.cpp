#include <iostream>
#include <ctime>
#include <math.h>
#include <string>
using namespace std;

long long int newTime()
{
  
    // Acquiring number of seconds
    // passed from Jan 1, 1970.
    time_t t = time(NULL);
  
    // Converting the time to year, month,
    // day, hour, minute, and second.
    struct tm* tm = localtime(&t);
    long long int x;
  
    // Applying a certain logic to get
    // required number of digits. It may vary.
    x = (tm->tm_hour) * 10000000 + (tm->tm_min) * 100000
        + (tm->tm_sec) * 1000 + (tm->tm_mday) * 10 + (tm->tm_year);
  
    // Return the calculated number.
    return x;
}

int countNum(long long seed) {
    int dem = 0;
    while (seed > 0) {
        ++dem;
        seed /= 10;
    }
    return dem;
}

long int midSquare(long int seed)
{
    long int hashNum = seed * seed;
    hashNum /= 100;
    hashNum %= 10000;
    return hashNum;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed % mod;
}
long int digitExtraction(long int seed,int* extractDigits,int size)
{
    int count = countNum(seed);
    long int result = 0, i = 0;
    while (i < size) {
        long int a = pow(10, count - extractDigits[i]);
        result = result * 10 + (seed % a) / ( a / 10);
        i++;
    }
    return result;
}

int foldShift(long long key, int addressSize)
{
    string s = to_string(key);
    int size = s.size();
    int result = 0;
    for (int i = 0; i < size; i += addressSize) {
        int temp = 0;
        int j = i;
        while (j < (i + addressSize < size ? i + addressSize : size)) {
            temp *= 10;
            temp += (s[j] - '0');
            j++;
        }
        result += temp;
    }
    int temp2 = pow(10, addressSize);
    return result % temp2;
}

int rotation(long long key, int addressSize)
{
    string s = to_string(key);
    int size = s.size();
    if (size > 1)
        s = s[size - 1] + s.substr(0, size - 1);
    long long result = stoll(s);
    return foldShift(result, addressSize);
}

int getParent(int child) {
    return (child - 1)/ 2;
}
int getRightChild(int child) {
    return 2*child + 2;
}
int getLeftChild(int child) {
    return 2*child + 1;
}
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    int left = getLeftChild(index);
		// if there exists a right subtree
		if(left < numberOfElements)
		{
            int right = getRightChild(index);
			//cout<<"right: "<<right<<endl;
            if (right < numberOfElements) {
                if(maxHeap[left] < maxHeap[right])
			{
				if(maxHeap[index] < maxHeap[right])
				{
					swap(maxHeap[index], maxHeap[right]);
					/*cout<<"in left < right: "<<endl;
					display()*/;
					index = right;
					reheapDown(maxHeap, numberOfElements, index);
				}
			}
			else
			{
				if(maxHeap[index] < maxHeap[left])
				{
					swap(maxHeap[index], maxHeap[left]);
					/*cout<<"in left > right: "<<endl;
					display();*/
					index = left;	
					reheapDown(maxHeap, numberOfElements, index);			
				}
			}		
            }
			else
		{
			if (maxHeap[index] < maxHeap[left])
			{
				swap(maxHeap[index], maxHeap[left]);

			}
		}
		}
		// if no right subtree
		
			
	}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    if (index != 0) {
        int current = getParent(index);
        if (maxHeap[index] > maxHeap[current]) {
            swap(maxHeap[index], maxHeap[current]);
            reheapUp(maxHeap, numberOfElements, current);
        }
    }
    
}
int main() {
    int arr[] = {1,2,3,4,5,6,7,8};
int size = sizeof(arr)/sizeof(arr[0]);
reheapDown(arr,size,0);
cout << "[ ";
for(int i=0;i<size;i++)
    cout << arr[i] << " ";
cout << "]";
cout << endl;
cout << foldShift(123456789, 3) << endl;
cout << rotation(600101, 2);
    return 0;
}
