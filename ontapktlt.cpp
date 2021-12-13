#include <iostream>
#include <vector>
using namespace std;

// vector<vector<int>> threeSum(vector<int>& nums) {
//     vector<int>temp;
//     vector<vector<int> >last;
//     int sum = 0;
//     for (int i = 0; i < nums.size(); i++) {
//         for (int j = i + 1; j < nums.size(); j++) {
//             for (int k = j + 1; k < nums.size(); k++) {
//                 sum = nums[i] + nums[j] + nums[k];
//                 if (sum == 0) {
//                     temp.push_back(nums[i]);
//                     temp.push_back(nums[j]);
//                     temp.push_back(nums[k]);
//                     //Sap xep temp
//                     for (int a = 0; a < temp.size(); a++) {
//                         for (int b = a + 1; b < temp.size(); b++) {
//                             if (temp[a] > temp[b]) {
//                                 int tam = temp[a];
//                                 temp[a] = temp[b];
//                                 temp[b] = tam;
//                             }
//                         }
//                     }
//                     last.push_back(temp);
//                     //Kiem tra neu temp trung voi 1 phan tu trong last thì xoa temp di
//                     for (int x = 0; x < last.size(); x++) {
//                         if (temp == last[x]) {
//                             last.pop_back();
//                             break;
//                         }
//                     }
//                     temp.clear();
//                 }
//             }
//         }
//     }
//     return last;
// }

int main() {
    vector <int> nums = { 0, 0, 0, 0 };
    int n = 6;
    vector<int>temp;
    vector<vector<int> >last;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    //Sap xep temp
                    for (int a = 0; a < temp.size(); a++) {
                        for (int b = a + 1; b < temp.size(); b++) {
                            if (temp[a] > temp[b]) {
                                int tam = temp[a];
                                temp[a] = temp[b];
                                temp[b] = tam;
                            }
                        }
                    }
                    if (last.size() == 0) {
                        last.push_back(temp);
                    }
                    if (last.size() != 0) {
                        bool check = false;
                        for (int x = 0; x < last.size(); x++) {
                            if (temp == last[x]) {
                                check = true;
                                break;
                            }
                        }
                        if (check == false) last.push_back(temp);
                    }
                    //Kiem tra neu temp trung voi 1 phan tu trong last thì xoa temp di
                    
                    temp.clear();
                }
            }
        }
    }

    for (int i = 0; i < last.size(); i++) {
        for (int j = 0; j < last[i].size(); j++) {
            cout << last[i][j] << " ";
        }
    }
    return 0;
}