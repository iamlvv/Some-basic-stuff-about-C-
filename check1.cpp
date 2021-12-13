    #include <iostream>
    #include <string>
    #include <vector>
    #include <queue>
    using namespace std;
    int x[11];
    
    void print(int a[], int n) {
        for (int i = 1; i <= n; i++) {
            cout << a[i];
        }
        cout << " ";
    }
    void check(int h, int k, int n) {
        for (int i = x[h - 1] + 1; i <= n - (k - h); i++ ) {
            x[h] = i;
            if (h == k) print(x, k);
            else check(h + 1, k, n);
        }
        
    }
    int main() {
        int n;
        cin >> n;
        int k;
        cin >> k;
        x[0] = 0;
        check(1, k, n);
        return 0;
    }