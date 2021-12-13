#include <iostream>
#include <string>
#include <regex>

using namespace std;
struct node{
    node(): num(-1), type(""), ID("") {}
    int num;
    string type;
    string ID;
};
struct assNode{
    assNode(): data(node()), next(NULL) {}
    assNode(node data, assNode* next): data(data), next(next) {}
    
    node data;
    assNode* next;
};
struct Array{                       //Kiểu dữ liệu array
    Array(): arr(NULL), size(0) {}
    node* arr;
    int size;
};
void initArray(Array &array) {
    array.arr = new node [100];
    array.size = 100;
}
void insertArray(Array &array, node x, int pos) {
        for (int i = array.size; i > pos; i--) {
            array.arr[i] = array.arr[i - 1];
        }
        array.size++;
        array.arr[pos] = x;
    }       //Hàm thêm x vào array
bool CheckSubstring(string firstString, string secondString){   //Hàm kiểm tra id trong chuỗi check
    if(secondString.size() > firstString.size())
        return false;

    for (int i = 0; i < firstString.size(); i++){
        int j = 0;
        if(firstString[i] == secondString[j]){
            int k = i;
            while (firstString[i] == secondString[j] && j < secondString.size()){
                j++;
                i++;
            }
            if (j == secondString.size())
                return true;
            else
                i = k;
        }
    }
    return false;
}

string insert(Array &array, string str) {
    string id;
    string type;
    static string check ="";
    str = str.substr(7);
    int pos = 0;
    //Tach lay identifier va type ra khoi lenh
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            pos = i;
            id = str.substr(0, pos);
            type = str.substr(pos + 1);
            break;
        }
    }
    //Kiểm tra id đã tồn tại trong check chưa, nếu chưa thì thêm vào check, đồng thời thêm vào Array, nếu rồi thì trả ra error
        if (CheckSubstring(check, id)) {
            //throw std::out_of_range("Redeclared: " + str);
            return "error";
        }
        else {
            node x;
            check += id;
            if (type == "string") {
                x.type = "string";
                x.ID = id;
                insertArray(array, x, 0); 
                
            }
            if (type == "number") {
                x.ID = id;
                x.type = "number";
                insertArray(array, x, 0);
            }
        }
        return "success";
}
int main() {
    Array array; //Tao mang de luu du lieu
    string str = "INSERT x1 string";
    string check;
    initArray(array);
    
        getline(cin, check);
        cout << insert(array, check);
        cout << endl;
    
    
    
    return 0;
}