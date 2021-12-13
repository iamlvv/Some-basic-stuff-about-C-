#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
void insertionsort(int a[], int n) {
    int index = 0, value = 0;
    for (int i = 1; i < n; i++) {
        index = i;
        value = a[index];
        while (index > 0 && a[index - 1] > value) {
            a[index] = a[index - 1];
            index--;
        }
        a[index] = value;
    }
}
void selectionSort(int a[], int n){
	int indexMin;
	for (int i = 0; i < n-1; i++){
		indexMin = i;
		for (int j = i+1; j < n; j++){
			if (a[indexMin] > a[j]){
				indexMin = j;
			}
		}
		if (i != indexMin){
			int temp = a[i];
			a[i] = a[indexMin];
			a[indexMin] = temp;
		}
	}
} 
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int *L = new int[n1];
    int *R = new int [n2];
    for (i = 0; i < n1; i++){
    	L[i] = arr[l + i];
	}  
    for (j = 0; j < n2; j++){
    	R[j] = arr[m + 1+ j];
	}
    i = 0;
    j = 0; 
    k = l; 
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}
void shellSort(int a[], int n){
	int interval, i, j, temp;
	for(interval = n/2; interval > 0; interval /= 2){
		for(i = interval; i < n; i++){
			temp = a[i];
			for(j = i; j >= interval && a[j - interval] > temp; j -= interval){
				a[j] = a[j - interval];				
			}
			a[j] = temp;
		}
    }
}
void quickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (a[i] < p){
			i++;
		}
		while (a[j] > p){
			j--;
		}
		if (i <= j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r){
		quickSort(a, i, r);
	}
	if (l < j){
		quickSort(a, l, j);
	}
}
int returnmin(int a[], int n) {
    quickSort(a, 0 , n - 1);
    int min = a[0];
    if (min > 0) return 0;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > 1) return a[i - 1] + 1;
        
    }
    return a[n - 1] + 1;
}
void frequency(int a[], int n) {
    quickSort(a, 0 , n - 1);
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            count++;
        }
        else {
            cout << a[i - 1] << " " << count << "; ";
            count = 1;
        }
    }
    cout << a[n - 1] << " " << count << "; ";
}

int covidity(int a[], int n, int k) {
    quickSort(a, 0 , n -1);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (abs(a[i + 1] - a[i]) <= k) {
            continue;
        }
        else count += 1;
    }
    return count;
}

bool chinhphuong(int n) {
    int temp = sqrt(n);
    if (temp * temp == n) return true;
    return false;
}
string coutchinhphuong(vector<int> &result, int a[], int n) {
    quickSort(a, 0 , n - 1);
    for (int i = 0; i < n; i++) {
        if (chinhphuong(a[i])) {
            bool check = true;
            for (int j = 0; j < result.size(); j++) {
                if (result[j] == a[i]) {check = false;break;}
                else continue;
            }
            if (check == true) result.push_back(a[i]);
        }
        else continue;
    }
    if (result.size() == 0) return "NULL";
    return "success";
}

int main(int argc, char **argv) {
    int n; 
    cin >> n;
    vector<int> result;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string end = coutchinhphuong(result, a, n);
    if (end != "NULL") {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
    }
    else cout << "NULL";
    //frequency(a, n);
    return 0;
}