#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

bool check(char *text, char *pattern) {
    if (*text == '\0' && *pattern != '\0') return false;
    if (*pattern == '\0') return true;
    if (*text == *pattern) {
        return check(text + 1, pattern + 1);
    }
    return false;
}
bool containsPattern(char *text, char *pattern) {
    if (*text == '\0') return false;
    if (*text == *pattern) {
        if (check(text, pattern)) return true;
        else return containsPattern(text + 1, pattern);
    }
    return containsPattern(text + 1, pattern);
}
bool CheckSubstring(std::string firstString, std::string secondString){
    if(secondString.size() > firstString.size())
        return false;

    for (int i = 0; i < firstString.size(); i++){
        int j = 0;
        // If the first characters match
        if(firstString[i] == secondString[j]){
            int k = i;
            while (firstString[i] == secondString[j] && j < secondString.size()){
                j++;
                i++;
            }
            if (j == secondString.size())
                return true;
            else // Re-initialize i to its original value
                i = k;
        }
    }
    return false;
}
int strLen(char* str)     
{ 
    int k = 0;
    if (*str == '\0') return k;
    k++;
    return k + strLen(str + 1);

}
int countspace(string str) {
    int count = 0;
    int pos = 0;
    string temp = "";
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            count+=1;
            pos = i;
            temp = str.substr(pos + 1);
            break;
    }
    }
    for (unsigned int i = 0; i < temp.size(); i++) {
        if (temp[i] == ' ') {
            count+= 1;
            break;
        }
    }
    cout << temp << endl;
    return count;
} 
int main() {
    // string format = "";
    // string str = "sum(1,2)";
    // string nex = "(";
    // int size = str.size();
    // int pos = str.find(nex);
    // string temp = "";
    // for (int i = 0; i < size; i++) {
    //     if (str[i] == ',' || str[i] == ')') {
    //         temp = str.substr(pos + 1, i - pos - 1);
    //         cout << temp << endl;
    //         if (temp == "number") format += '1';
    //         else if (temp == "string") format += '2';
    //         pos = i;
    //     }
    // }
    
    // cout << format << endl;
    // string pa1 = "(";
    // string pa2 = ")";
    // string co = ",";
    // cout << str.find(co) << endl;
    // if (str.find(pa1) > 1000 || str.find(pa2) > 1000) cout << "Type Mismatch";
    // string str = "LINEAR 19 2";
    // str = str.substr(7);
    // int size = str.size();
    // string id = "";
    // string parameter = "";
    // for (int i = 0; i < size; i++) {
    //     if (str[i] == ' ') {
    //         id = str.substr(0, i);
    //         parameter = str.substr(i + 1);
    //         break;
    //     }
    // }
    // int size2 = stoi(id);
    // int constant = stoi(parameter);
    // cout << size2 << " " << constant << endl;
    // cout << id << " " << parameter << endl;
    // cout << parameter.size() << endl;
    vector<int>er = {1, 2, 3, 4};
    er.push_back(6);
    cout << er.size() << endl;
    return 0;
}