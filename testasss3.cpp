#include <iostream>
#include <string.h>
#include <fstream>
#include <regex>
using namespace std;

struct element {
    element() : level(0), ID(""), type(""), key(0), position(0), con(""), index(0), khe(0) {}
    int level;
    string ID;
    string type;
    long long key;
    int position;
    string con;
    long long index;
    int khe;
};
struct Node {
    Node() : data(element()), next(NULL), prev(NULL) {}
    element data;
    Node* next;
    Node* prev;
};
struct SLinked {
    SLinked() : head(NULL), size(0), tail(NULL) {}
    Node* head;
    int size;
    Node* tail;
};
struct Mang {
    Mang() : arr(NULL), size(0), capacity(0) {}
    element* arr;
    int size;
    int capacity;
};
//-----------------------------------------------------------------//
element newNode(string id, string type, int level, int key) {
    element x;
    x.ID = id;
    x.type = type;
    x.level = level;
    x.key = key;
    return x;
}

void initMang(Mang& array, int cap) {
    //Init a new array with capacity equals to cap
    //TODO
    array.arr = new element[cap];
    array.size = cap;
}

void addNode(SLinked& danhsach, element x, int pos) {
    if (danhsach.size == 0) {
        Node* temp = new Node;
        temp->data = x;
        danhsach.head = temp;
        danhsach.tail = temp;
        danhsach.size++;
    }
    else {
        if (pos == 0) {
            Node* temp = new Node;
            temp->data = x;
            temp->next = danhsach.head;
            danhsach.head->prev = temp;
            danhsach.head = temp;
            danhsach.size++;
        }
        else if (pos == danhsach.size) {
            Node* temp = new Node;
            temp->data = x;
            temp->next = nullptr;
            temp->prev = danhsach.tail;
            danhsach.tail->next = temp;
            danhsach.tail = temp;
            danhsach.size++;
        }
    }
}
bool checkton(SLinked& danhsach, string str) {
    Node* temp = danhsach.head;
    for (int i = 0; i < danhsach.size; i++) {
        if (temp->data.ID == str) return true;
        temp = temp->next;
    }
    return false;
}

bool CheckSubstring(string firstString, string secondString) {
    if (secondString.size() > firstString.size())
        return false;
    for (unsigned int i = 0; i < firstString.size(); i++) {
        unsigned int j = 0;
        if (firstString[i] == secondString[j]) {
            int k = i;
            while (firstString[i] == secondString[j] && j < secondString.size()) {
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
bool checkline(string str) {
    bool check = false;
    if (CheckSubstring(str, "BEGIN")) check = true;
    else if (CheckSubstring(str, "END")) check = true;
    else if (CheckSubstring(str, "INSERT")) check = true;
    else if (CheckSubstring(str, "ASSIGN")) check = true;
    else if (CheckSubstring(str, "PRINT")) check = true;
    else if (CheckSubstring(str, "LOOKUP")) { check = true; }
    return check;
}
int countspace(string str) {        //return the number of space in given string
    int count = 0;
    int pos = 0;
    string temp = "";
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            count += 1;
            pos = i;
            temp = str.substr(pos + 1);
            break;
        }
    }
    for (unsigned int i = 0; i < temp.size(); i++) {
        if (temp[i] == ' ') {
            count += 1;
            break;
        }
    }
    return count;
}
long long decode(string ID, string level) {
    /*Hàm này giải mã ID thành key dạng int*/
    string str = "";
    int result = 0;
    if (level != "0") {
        str += level;
        int size = ID.size();
        for (int i = 0; i < size; i++) {
            int result = 0;
            result = (int)ID[i] - 48;
            str += to_string(result);
        }
    }
    if (level == "0") {
        int size = ID.size();
        for (int i = 0; i < size; i++) {
            
            result = (int)ID[i] - 48;
            str += to_string(result);
        }
    }
    long long final = stoll(str);
    return final;
}
int findposlast(SLinked& danhsach) {
    int count = 0;
    Node* run = danhsach.head;
    for (int i = 0; i < danhsach.size; i++) {
        if (run->data.type == "BEGIN") count++;
        if (run->data.type == "END") count--;
        run = run->next;
    }
    return count;
}
bool demblock(SLinked& danhsach) {
    int dembegin = 0;
    int demnd = 0;
    Node* temp2 = danhsach.head;
    for (int i = 0; i < danhsach.size; i++) {
        if (temp2->data.type == "BEGIN") {
            dembegin++;
        }
        if (temp2->data.type == "END") {
            demnd++;
        }
        temp2 = temp2->next;
    }
    if (dembegin == 0 || (dembegin - demnd < 0)) return false;
    return true;
}
void setdefault(Mang& mang, int size) {
    /*Hàm này đặt mặc định các phần tử trong hash về "NULL*/
    for (int i = 0; i < size; i++) {
        mang.arr[i].ID = "NULL";
        mang.arr[i].type = "NULL";
        mang.arr[i].level = -1;
    }
}
int linear(SLinked &danhsach, Mang& mang, string s, element &value) {
    /*
    Cách làm:
    Truyền vào mảng Hash, chuỗi mang[0] quy định kiểu dò tìm, giá trị value cần chèn
    vào hash.
    B1: Phân tách chuỗi s, ép về kiểu int các giá trị size, constant
    B2: Gắn flag = false. Cho chạy vòng lặp điều kiện flag == false.
    B3: Nếu tại place mà hash đang NULL thì tiến hành gán, flag = true và break vòng
    lặp, nếu khác NULL thì chỉnh lại place theo công thức LINEAR PROBING, sau đó
    tiếp tục cho tới khi gán được.
    B4: Trả về số lần skip ô hash trước khi gán được value vào hash.*/
    s = s.substr(7);
    int size = s.size();
    string s1 = "";
    string s2 = "";
    for (int i = 0; i < size; i++) {
        if (s[i] == ' ') {
            s1 = s.substr(0, i);
            s2 = s.substr(i + 1);
            break;
        }
    }
    int size_hash = stoi(s1);
    int constant = stoi(s2);
    int step = 0;
    long long place = value.key % size_hash;
    bool flag = false;
    while (flag == false) {
        if (mang.arr[place].ID == "NULL") {
            mang.arr[place] = value;
            danhsach.tail->data.index = place;
            danhsach.tail->data.khe = step;
            mang.arr[place].index = place;
            mang.arr[place].khe = step;
            flag = true;
            break;
        }
        else {
            step++;
            place = (value.key % size_hash + constant * step) % size_hash;
        }
    }
    if (flag == false) return -1; //Nếu không thể gán vào hash -> bị overflow, trả
    //về -1
    return step;
}
int quadratic(SLinked &danhsach, Mang& mang, string s, element& value) {
    s = s.substr(10);
    int size = s.size();
    string s1 = "";
    string s2 = "";
    string s3 = "";
    
    for (int i = 0; i < size; i++) {
        if (s[i] == ' ') {
            s1 = s.substr(0, i);
            s = s.substr(i + 1);
            break;
        }
    }
    size = s.size();
    for (int i = 0; i < size; i++) {
        if (s[i] == ' ') {
            s2 = s.substr(0, i);
            s3 = s.substr(i + 1);
            break;
        }
    }
    int size_hash = stoi(s1);
    int constant1 = stoi(s2);
    int constant2 = stoi(s3);
    int step = 0;
    bool flag = false;
    int place = value.key % size_hash;
    while (flag == false) {
        if (mang.arr[place].ID == "NULL") {
            mang.arr[place] = value;
            danhsach.tail->data.index = place;
            danhsach.tail->data.khe = step;
            mang.arr[place].index = place;
            mang.arr[place].khe = step;
            flag = true;
            break;
        }
        else {
            step++;
            place = (value.key % size_hash + constant1 * step + constant2 * step * step)
            % size_hash;
        }
    }
    return step;
}
int Double(SLinked &danhsach, Mang& mang, string s, element& value) {
    s = s.substr(7);
    int size = s.size();
    string s1 = "";
    string s2 = "";
    for (int i = 0; i < size; i++) {
        if (s[i] == ' ') {
            s1 = s.substr(0, i);
            s2 = s.substr(i + 1);
            break;
        }
    }
    int size_hash = stoi(s1);
    int constant = stoi(s2);
    int step = 0;
    long long place1 = value.key % size_hash;
    long long place = 0;
    long long place2 = 0;
    bool flag = false;
    if (mang.arr[place1].ID != "NULL") {
        place2 = 1 + (value.key % (size_hash - 2));
        place = place2;
        step++;
        while (flag == false) {
            if (mang.arr[place].ID == "NULL") {
                mang.arr[place] = value;
                danhsach.tail->data.index = place;
                danhsach.tail->data.khe = step;
                mang.arr[place].index = place;
                mang.arr[place].khe = step;
                flag = true;
                break;
            }
            else {
                step++;
                place = (place1 + constant * step * place2) % size_hash;
            }
        }
    }
    return step;
}
string insertdanhsach(SLinked& danhsach, string id, string parameter, int& position) {
    /*Hàm insert vào double linked list*/
    Node* run = danhsach.tail;
    element x;
    x.level = findposlast(danhsach);
    x.key = decode(id, to_string(x.level));
    if (parameter.size() != 0) {
        if (x.level != 0) return "Invalid Declaration";
    }
    bool flag = true;
    for (int i = danhsach.size - 1; i >= 0; i--) {
        if (run->data.type == "BEGIN") {
            if (run->data.level == x.level) break;
        }
        if (run->data.ID == id && run->data.level == x.level) return "Redeclared";
        if (run->data.ID != id) {
            flag = true;
        }
        run = run->prev;
    }
    if (flag == true) {
        if (parameter == "") {
            x.type = "void";
            x.ID = id;
            x.position = position;
            addNode(danhsach, x, danhsach.size);
        }
        else if (parameter != "") {
            x.ID = id;
            x.type = "void";
            x.position = position;
            addNode(danhsach, x, danhsach.size);
        }
    }
    return "success";
}
string insertHash(SLinked &danhsach, Mang& mang, string s, string str, int &position) {
    /*Hàm insert vào Hash*/
    int number_of_space = countspace(str);
    if (number_of_space <= 0) return "Invalid Instruction" + str;
    str = str.substr(7);
    int size = str.size();
    string id = "";
    string parameter = "";
    int result = 0;
    if (number_of_space == 1) {
        id = str;
    }
    else if (number_of_space >= 2) {
        for (int i = 0; i < size; i++) {
            if (str[i] == ' ') {
                id = str.substr(0, i);
                parameter = str.substr(i + 1);
                break;
            }
        }
    }
    string result_of_insert_danhsach = insertdanhsach(danhsach, id, parameter, position);
    if (result_of_insert_danhsach == "success") {
        if (CheckSubstring(s, "LINEAR")) {
            result = linear(danhsach, mang, s, danhsach.tail->data);
        }
        else if (CheckSubstring(s, "QUADRATIC")) {
            result = quadratic(danhsach, mang, s, danhsach.tail->data);
        }
        else if (CheckSubstring(s, "DOUBLE")) {
            result = Double(danhsach, mang, s, danhsach.tail->data);
        }
        if (result == -1) return "Overflow";
    }
    else if (result_of_insert_danhsach == "Redeclared") return "Redeclared";
    else if (result_of_insert_danhsach == "Invalid Declaration") return "Invalid Declaration";
    return to_string(result);
}

int return_size_linear(string s) {
    /*Hàm trả về kích thước của hash*/
    s = s.substr(7);
    int size = s.size();
    string s1 = "";
    for (int i = 0; i < size; i++) {
        if (s[i] == ' ') {
            s1 = s.substr(0, i);
            break;
        }
    }
    int size_hash = stoi(s1);
    return size_hash;
}
int return_size_quad(string s) {
    s = s.substr(10);
    int size = s.size();
    string s2 = "";
    for (int i = 0; i < size; i++) {
        if (s[i] == ' ') {
            s2 = s.substr(0, i);
            break;
        }
    }
    int size_hash = stoi(s2);
    return size_hash;
}
int return_size_double(string s) {
    s = s.substr(7);
    string s3 = "";
    int size = s.size();
    for (int i = 0; i < size; i++) {
        if (s[i] == ' ') {
            s3 = s.substr(0, i);
            break;
        }
    }
    int size_hash = stoi(s3);
    return size_hash;
}

void deleteNode(Mang& mang, element value) {
    element Default = newNode("NULL", "NULL", -1, 0);
    for (int i = 0; i < mang.size; i++) {
        if (mang.arr[i].position == value.position) {
            mang.arr[i] = Default;
        }
    }
}
string checkvalue(string value) {
    string num = "";
    bool flag = false;
    bool check = false;
    if (value[0] == '\'') {
        if (value[value.size() - 1] != '\'') return "error";
        else {
            for (unsigned int i = 1; i < value.size() - 1; i++) {
                if ((value[i] >= 48 && value[i] <= 57) || (value[i] >= 65 && value[i] <= 90) || (value[i] >= 97 && value[i] <= 122) || value[i] == ' ') flag = true;
            }
            if (flag) num = "string";
        }
    }
    else {
        for (unsigned int i = 0; i < value.size(); i++) {
            int temp = value[i];
            if (temp >= 48 && temp <= 57) check = true;
            else return "error";
        }
        if (check) num = "num";
    }
    return num;
}
string lookforid(SLinked& danhsach, string str) {
    /*
    */
    Node* look = danhsach.tail;
    Node* run = danhsach.tail;
    look->data.level = findposlast(danhsach);
    for (int i = danhsach.size - 1; i >= 0; i--) {
        if (run->data.type == "BEGIN") {
            if (run->data.level == look->data.level) look->data.level -= 1;
        }
        if (run->data.ID == str && run->data.level == look->data.level) return run->data.ID;
        run = run->prev;
    }
    return "";
}
string lookforfunct(SLinked& danhsach, string str) {
    Node* look = danhsach.tail;
    Node* run = danhsach.tail;
    look->data.level = findposlast(danhsach);
    for (int i = danhsach.size - 1; i >= 0; i--) {
        if (run->data.type == "BEGIN") {
            if (run->data.level == look->data.level) look->data.level -= 1;
        }
        if (run->data.ID == str && run->data.level == look->data.level) return run->data.type;
        run = run->prev;
    }
    return "";
}
string valid_value(SLinked &danhsach, string s) {
    string result = "";
    result = lookforid(danhsach, s);
    if (result != "") return "constant id";
    result = checkvalue(s);
    if (result == "num") return "constant number";
    if (result == "string") return "constant string";
    return "error";
}
string lookfor(SLinked& danhsach) {
    Node* look = danhsach.tail;
    Node* run = danhsach.tail;
    look->data.level = findposlast(danhsach);
    for (int i = danhsach.size - 1; i >= 0; i--) {
        if (run->data.type == "BEGIN") {
            if (run->data.level == look->data.level) look->data.level -= 1;
        }
        if (run->data.ID == look->data.type && run->data.level == look->data.level) return run->data.type;
        run = run->prev;
    }
    return "";
}
string takenamefunction(string str) {       //Return name of the function. for example: foo(2,1) -> return "foo"
    int size = str.size();
    int pos = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] == '(') {
            pos = i;
            break;
        }
    }
    string result = str.substr(0, pos);
    return result;
}
string formatfunction(SLinked& danhsach, string str) {
    string format = "";
    int size = str.size();
    string pa = "(";
    int pos = str.find(pa);
    string temp = "";
    for (int i = 0; i < size; i++) {
        if (str[i] == ',' || str[i] == ')') {
            temp = str.substr(pos + 1, i - pos - 1);
            if (temp == "number") format += '1';
            else if (temp == "string") format += '2';
            else {
                if (temp == "") {
                    format += 'b';
                }
                string check = checkvalue(temp);    //Nếu temp là kiểu hằng
                if (check == "string") format += '2';
                else if (check == "num") format += '1';
                else if (check == "error") {
                    string check2 = lookforid(danhsach, temp);  //Nếu temp là kiểu danh hiệu đã khai báo trước
                    if (check2 == "") format += 'x';
                    else if (check2 != "") format += '5';
                }
            }
            pos = i;
        }
    }
    return format;
}

int tim_id(int level, Mang& mang, string id) {
    while (level >= 0) {
        for (int i = 0; i < mang.size; i++) {
            if (mang.arr[i].ID == "NULL") continue;
            else {
                if (mang.arr[i].ID == id) {
                    if (mang.arr[i].level == level) {
                        if (mang.arr[i].type != "NULL") {
                            return mang.arr[i].khe;
                        }
                        else return -2;
                    }
                    else continue;
                }
            }
        }
        level -= 1;
    }
    return -3;
}

int linear_assign(SLinked &danhsach, Mang& mang, string s, string str, element &value) {
    s = s.substr(7);
    int size = s.size();
    string s1 = "";
    string s2 = "";
    for (int i = 0; i < size; i++) {
        if (s[i] == ' ') {
            s1 = s.substr(0, i);
            s2 = s.substr(i + 1);
            break;
        }
    }
    int size_hash = stoi(s1);
    int constant = stoi(s2);
    int step = 0;
    int place = value.key % size_hash;
    bool flag = false;
    while (flag == false) {
        if (mang.arr[place].ID == "NULL") {
            mang.arr[place] = value;
            danhsach.tail->data.index = place;
            flag = true;
            break;
        }
        else {
            step++;
            place = (value.key % size_hash + constant * step) % size_hash;
        }
    }
    if (flag == false) return -1; //Nếu không thể gán vào hash -> bị overflow, trả
    //về -1
    return step;
}
string takenamefunction(string str) {       //Return name of the function. for example: foo(2,1) -> return "foo"
    int size = str.size();
    int pos = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] == '(') {
            pos = i;
            break;
        }
    }
    string result = str.substr(0, pos);
    return result;
}
void takepara(string contain[], string value, int count_phay) {
    while (count_phay > 0) {
        int found = value.find(",");
        contain[count_phay] = value.substr(0, found);
        value = value;
        count_phay--;
    }
}

string assignHash(SLinked& danhsach, Mang& mang, string s, string str, int& position) {
    /*
    Tách ra, xem thử value có phải hàm hay không.
    Nếu value không phải hàm thì assign như bình thường.
    Nếu value là 1 hàm, thì phân tích các tham số */
    int level_assign = findposlast(danhsach);
    int ori = level_assign;
    str = str.substr(7);
    int size = str.size();
    string iden_name = "";
    string value = "";
    for (int i = 0; i < size; i++) {
        if (str[i] == ' ') {
            iden_name = str.substr(i);
            value = str.substr(i + 1);
            break;
        }
    }
    int khe_value = 0;
    int khe_iden = 0;
    int khe_para = 0;
    string bracket = "(";
    if (value.find(bracket) < 1000) { //Nếu value là kiểu hàm
        string name_of_function = takenamefunction(value);
        value = value.substr(name_of_function.size());
        int count_phay = 0;

        int sizex = value.size();
        for (int i = 0; i < sizex; i++) {
            if (value[i] == ',') count_phay++;
        }
        int newsize = count_phay + 1;
        string* contain = new string[newsize];
        
    }
    else {  //Nếu value thuộc 1 trong các kiểu: string, number, danh hiệu
        string check_value = valid_value(danhsach, value);
        if (check_value == "error") return "Type Mismatch";
        while (level_assign >= 0) {
            for (int i = 0; i < mang.size; i++) {
                if (mang.arr[i].ID == "NULL") {
                    continue;
                }
                else {
                    if (mang.arr[i].ID == iden_name) {
                        if (level_assign == mang.arr[i].level) {
                            if (check_value == "constant string") mang.arr[i].type = "string";
                            else if (check_value == "constant number") mang.arr[i].type = "number";
                            else if (check_value == "constant id") {
                                int check = tim_id(ori, mang, check_value);
                                if (check == -2) return "Cannot inferred";
                                else if (check == -3) return "Undeclared";
                                else {
                                    mang.arr[i].type = "danh hieu";
                                    khe_value = check;
                                }
                            }
                            break;
                        }
                        else continue;
                    }

                }
            }
            level_assign -= 1;
        }
    }
    int result = khe_iden + khe_value + khe_para;
    return to_string(result);
}
string block(SLinked& danhsach) {
    int dembegin = 0;
    int demnd = 0;
    Node* temp2 = danhsach.head;
    for (int i = 0; i < danhsach.size; i++) {
        if (temp2->data.type == "BEGIN") {
            dembegin++;
        }
        if (temp2->data.type == "END") {
            demnd++;
        }
        temp2 = temp2->next;
    }
    if ((demnd != 0 && dembegin == 0) || dembegin - demnd < 0) return "";
    if (dembegin == demnd) return "";
    else return "Unclosed Block: " + to_string(dembegin - demnd);
}

 string lookup(SLinked& danhsach, string str) {
    if (countspace(str) != 1) return "Invalid for space: " + str;
    string id = str.substr(7);
    if (!checkton(danhsach, id)) return "Undeclared " + str;
    regex r("^[a-z]\\w*");
    if (!regex_match(id, r)) return "Invalid: " + str;
    element x;
    x.type = "LOOKUP";
    x.con = id;
    x.level = findposlast(danhsach);
    addNode(danhsach, x, danhsach.size);
    Node* run = danhsach.tail->prev;
    Node* lookup = danhsach.tail;
    for (int i = danhsach.size - 2; i >= 0; i--) {
        if (run->data.type == "BEGIN") {
            if (run->data.level == lookup->data.level) lookup->data.level -= 1;
        }
        if (run->data.ID == lookup->data.con && run->data.level == lookup->data.level) return to_string(run->data.index);
        run = run->prev;
    }
    return "Undeclared" + str;
}


void print_danhsach(SLinked& danhsach) {
    Node* temp = danhsach.head;
    for (int i = 0; i < danhsach.size; i++) {
        cout << temp->data.khe << " ";
        temp = temp->next;
    }
}
void print_mang(Mang& mang) {
    for (int i = 0; i < mang.size; i++) {
        cout << mang.arr[i].type << " ";
    }
}
string Call(Mang& mang, SLinked& danhsach, string s) {
    s = s.substr(5);
    int size = s.size();
    bool check = false;
    bool flag = true;
    for (int i = 0; i < mang.size; i++) {
        if (mang.arr[i].ID != "NULL") {
            flag = false;
            break;
        }
    }
    if (flag == true) return "Undeclared";

    for (int i = 0; i < size; i++) {
        if (s[i] == '(' || s[i] == ')') {
            check = true; 
            break;
        }
    }
    if (check == true) {
        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                s = s.substr(0, i);
                break;
            }
        }
        for (int i = 0; i < mang.size; i++) {
            if (mang.arr[i].ID == "NULL") continue;
            else {
                if (mang.arr[i].ID == s) {
                    if (mang.arr[i].type != "function") return "Type Mismatch";
                }
            }
        }
    }
    return "";
}
void print(Mang& mang) {
    int pos = -1;
    for (int i = 0; i < mang.size; i++) {
        if (mang.arr[i].ID != "NULL") pos = i;
    }
    if (pos == -1) return;
    for (int i = 0; i <= pos; i++) {
        if (mang.arr[i].ID == "NULL") continue;
        else {
            if (i != pos) {
                cout << i << " " << mang.arr[i].ID << "//" << mang.arr[i].level << ";";
            }
            else cout << i << " " << mang.arr[i].ID << "//" << mang.arr[i].level;
        }
    }
    cout << endl;
}
int main() {
    int position = 0;
    SLinked danhsach;
    string line;
    fstream f;
    f.open("C:/Users/DELL/Desktop/testcase.txt", ios::in);
    SLinked text;
    while (!f.eof()) {
        getline(f, line);
        element x;
        x.ID = line;
        addNode(text, x, text.size);
    }
    Mang mang;
    int size_mang = 0;
    if (CheckSubstring(text.head->data.ID, "LINEAR")) {
        size_mang = return_size_linear(text.head->data.ID);
    }
    else if (CheckSubstring(text.head->data.ID, "QUADRATIC")) {
        size_mang = return_size_quad(text.head->data.ID);
    }
    else if (CheckSubstring(text.head->data.ID, "DOUBLE")) {
        size_mang = return_size_double(text.head->data.ID);
    }
    initMang(mang, size_mang);
    setdefault(mang, size_mang);
    //print_mang(mang);
    Node* temp2 = text.head->next;
    for (int i = 1; i < text.size; i++) {
        position += 1;
        if (CheckSubstring(temp2->data.ID, "INSERT")) {
            cout << insertHash(danhsach, mang, text.head->data.ID, temp2->data.ID, position) << endl;
        }
        else if (CheckSubstring(temp2->data.ID, "BEGIN")) {
            element x;
            x.type = "BEGIN";
            addNode(danhsach, x, danhsach.size);
            danhsach.tail->data.level = findposlast(danhsach);
        }
        else if (CheckSubstring(temp2->data.ID, "ASSIGN")) {
            cout << assignHash(danhsach, mang, text.head->data.ID, temp2->data.ID, position) << endl;
        }
        else if (CheckSubstring(temp2->data.ID, "END")) {
            element x;
            x.type = "END";
            x.level = findposlast(danhsach);
            addNode(danhsach, x, danhsach.size);
            if (demblock(danhsach) == false) {
                cout << "Unknown Block" << endl;
                break;
            }
            int from = 0;
            Node* temp = danhsach.tail;
            Node* start = danhsach.head;
            for (int i = danhsach.size; i >= 0; i--) {
                if (temp->data.type == "BEGIN" && temp->data.level == x.level) {
                    start = temp;
                    from = i;
                    break;
                }
                temp = temp->prev;
            }
            from += 1;
            Node* run = start->next;
            while (run->data.type != "END") {
                if (run->data.ID != "") {
                    deleteNode(mang, run->data);
                }
                run = run->next;
            }
        }
        else if (CheckSubstring(temp2->data.ID, "CALL")) {
            string str = temp2->data.ID;
            string result_call = Call(mang, danhsach, str);
            cout << result_call << endl;
        }
        else if (CheckSubstring(temp2->data.ID, "LOOKUP")) {
            cout << lookup(danhsach, temp2->data.ID) << endl;
        }
        else if (temp2->data.ID == "PRINT") {
            print(mang);
        }
        temp2 = temp2->next;
    }
    if (block(danhsach) != "") cout << block(danhsach) << endl;
    print_danhsach(danhsach);
    cout << endl;
    print_mang(mang);
    f.close();
    return 0;
}