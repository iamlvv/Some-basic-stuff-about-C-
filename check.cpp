#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <vector>
using namespace std;
bool consecutiveOnes(vector<int>& nums) {
    // STUDENT ANSWER
    int temp[100];
    int first = 0;
    int last = 0;
    bool check = true;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            first = i;
            break;
        }
    }
    for (int i = first; i < nums.size(); i++) {
        if (nums[i] == 1) last = i;
    }
    for (int i = first; i <= last; i++) {
        if (nums[i] != 1) check = false;
    }
    return check;
}
string longestCommonPrefix(vector<string>& strs) {
    int min = 0;
    if (strs.empty() == 1) return "";
    else {
        min = strs[0].length();
        for (int i = 1; i < strs.size(); i++) {
            if (min > strs[i].length())
                min = strs[i].length();
            for (int j = 0; j < min; j++) {
                if (strs[i][j] != strs[i - 1][j]) {
                    min = j;
                    break;
                }
            }
        }
    }
    return strs[0].substr(0, min);
}
int longestSublist(vector<string>& words) {
    // STUDENT ANSWER

    return 1;
}
int buyCar(int* nums, int length, int k) {
    int max = 0;
    
        int min = nums[0];
        sort(nums, nums + length);
        for (int i = 0; i < length; i++) {
            if (k >= 0) {
                if (nums[i] <= k) {
                    k = k - nums[i];
                    max += 1;
                }
            }
            if (k < 0) break;
        }

    return max;
}
int oddSumSublist(vector<int>& nums, int m) {
    // STUDENT ANSWER
    int sum = 0;
    return sum;
}
int sumLessThanTarget(vector<int>& nums, int target) {
    // STUDENT ANSWER
    unsigned pos = nums.size();
    int sum = 0;
    int dem = 0;
    for (unsigned int i = 0; i < nums.size(); i++) {
        if (nums[i] >= target)
        {
            pos = i;
            break;
        }
    }
    int max = nums[0] + nums[1];
    for (unsigned int i = 0; i < pos; i++) {
        for (unsigned int j = i + 1; j < pos; j++) {
            sum = nums[i] + nums[j];
            if (sum < target && sum > max) max = sum;
        }
    }
    return max;
}
int main() {
    vector<string> words {"faction", "fight", "and", "are", "attitude"};
    cout << longestCommonPrefix(words);
    return 0;
}