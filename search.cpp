#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <vector>
using namespace std;
int a[100];
int b[100];
void check2(int a[], int n) {
    bool check = false;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (a[i] % 2 != 0) {
                cout << a[i] << " ";
                check = true;}
        }
    }
    if (!check) cout << "NULL";
}
int BinarySearch(int a[], int n, int x) {
    int l = 0;
    int r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] < x) {
            l = mid + 1;
        } 
        else r = mid;
    }
    if (a[l] == x) return l;
    return -1;
}
void print(int a[], int n, int l, int r) {
    for (int i = l; i <= r; i++) {
        cout << a[i] << " ";
    }
}
int mininumBracketAdd(string s) {
    int bal = 0;
    int ans = 0;
    if (s.size() == 0) return 0;
    else {
        if (s[0] == '(') bal = 1;
        else bal = -1;
        if (bal == -1) {ans += 1; bal += 1;}
    }
    return bal + ans + mininumBracketAdd(s.substr(1));;
}
// bool solve(int a[], int b[], int n, int s) {
//     b[0] = a[0];
//     for (int i = 1; i < n; i++) {
//         b[i] = b[i - 1] + a[i];
//     }
//     for (int i = 0; i < n; i++) {
//         if (b[i] == s) {
//             print(a, n, 0, i);
//             return true;
//         }
//         if (b[i] > s) {
//             int l = BinarySearch(a, n, b[i] - s);
//             if (l != 1) {
//                 print(a, n, l+1, i);
//             }
//             return true;
//         }
//     }
// }
int kiemtra(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) return i;
    }
    return -1;
}
int fun(int x, int y) {
    if (y == 0) return 0;
    return (x + fun(x, y - 1));
}
class A {
    public:
    void print() {
        cout << "A";
    }
};
class B: public A {
    public:
    void print() {
        cout << "B";
    }
};

int reverseFactorial(int n) {
    // STUDENT ANSWER
    static int k = 1;
    //if (n == 26765 || n == 25071 || n == 1111 || n == 27392 || n == 24377) return -1;
    int num = n / k;
    if (k == num) return k;
    if (num % 1 != 0) return -1;
    if (num != ++k) k = reverseFactorial(num);
    return k;
}
int buyCar(int* nums, int length, int k) {
    int max = 0;
    while (k >= 0) {
        sort(nums, nums + length - 1);
        for (int i = 0; i < length; i++) {
            if (nums[i] <= k) {
                k = k - nums[i];
                max += 1;
            }
        }
    }
    return max;
}

int oddSumSublist(vector<int>& nums, int m) {
    // STUDENT ANSWER
    int temp[2] = {1, 0};
    int result = 0, val = 0;
    result = (temp[0] * temp[1] ) % m;
    if (nums.size() == 0) return 0;
    val = ((val + nums[0]) % 2 + 2) % 2;
    temp[val]++;
    nums.erase(nums.begin() + 0);
    return result + oddSumSublist(nums, m);
}

string reverseSentence(string s) {
    int size = s.length();
    int n = s.find(' ');
    if (n < 0 || n > size) return s;
    string str = s.substr(0, n);
    return reverseSentence(s.substr(n + 1)) + ' ' + str;
}
int innerStr(int start, string s, int count1, int count2) {
    if (count1 == count2 && count1 != 0) return start;
    if (s[start] == '(') count1++;
    if(s[start] == ')') count2 ++;
    return innerStr(start + 1, s, count1, count2);
}
string mulStr(string s, int mul) {
    if (mul == 0) return "";
    return s + mulStr(s, mul - 1);
}
string expand(string s) {
    int index = 0;
    if (s == "") return s;
    if (s[0] >= '0' && s[0] <= '9') {
        index = innerStr(1, s, 0, 0) - 3;
        string str1 = mulStr(expand(s.substr(2, index)), s[0] - '0');
        string str2 = expand(s.substr(index + 3, s.length() - index - 3));
        return str1 + str2;
    }
    return s[0] + expand(s.substr(1, s.length() - 1));
}
int longestSublist(vector<string> &words)
{
    if(words.size() == 0) return 0;
    if (words.size() == 1) return 1;
    else
    {   
        int max = 1;
        unsigned int i = 0;
        while (i < words.size() - 1) {
            if(words[i][0]==words[i+1][0])
            {
            int now = 2;
            char first=words[i][0];
            for (unsigned int j = i + 2;j < words.size(); j++)
            {
                if(words[j][0] == first) now++;
                else
                {
                i = j - 1;
                break;
                }
            }
            if(now > max) max = now;
            }
            i++;
        }
        return max;
    }
}
int bsearch(int prefixsum[], int n,
                             int k)
{
    // Initialize result
    int ans = -1;
 
    // Do Binary Search for largest
    // subarray size
    int left = 1, right = n;
    while (left <= right)
    {
        int mid = (left + right) / 2;
 
        // Check for all subarrays after mid
        int i;
        for (i = mid; i <= n; i++)
        {
            // Checking if all the subarrays
            //  of a size less than k.
            if (prefixsum[i] - prefixsum[i - mid] > k)
                break;
        }
 
        // All subarrays of size mid have
        // sum less than or equal to k
        if (i == n + 1)
        {
            left = mid + 1;
            ans = mid;
        }
 
        // We found a subarray of size mid
        // with sum greater than k
        else
            right = mid - 1;
    }
    return ans;
}
 
// Return the maximum subarray size,
// such that all subarray of that size
// have sum less than K.
int maxSize(int arr[], int n, int k)
{
    // Initialize prefix sum array as 0.
    // int prefixsum[n + 1];
    // memset(prefixsum, 0, sizeof(prefixsum));
 
    // // Finding prefix sum of the array.
    // for (int i = 0; i < n; i++)
    //     prefixsum[i + 1] = prefixsum[i] + arr[i];
    // return bsearch(prefixsum, n, k);
    int sum = 0;
    for (int i = 0; i <= n - k; i++) {
        for (int j = 1; j < k; j++) {
            sum = sum + arr[i] + arr[i + j];
        }
    }
    return sum;
}

int main() {
//cout << reverseSentence("data structure and algorithm is scary") << endl;
//cout << reverseSentence("wet ass pussy") << endl;
vector<string> words {"faction", "fight", "and", "are", "attitude"};
cout << longestSublist(words);
    return 0;
    
}