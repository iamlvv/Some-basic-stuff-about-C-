#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct element {
	element() : level(0), ID(""), type(""), key(0) {}
	int level;
	string ID;
	string type;
    int key;
};
struct Node {
	Node(): data(element()), next(NULL) {}
	element data;
	Node* next;
	Node *prev;
};
struct SLinked {
    SLinked() : head(NULL), size(0), tail(NULL) {}
    Node* head;
    int size;
    Node* tail;
};
struct Mang {
	Mang(): arr(NULL), size(0), capacity(0) {}
	element *arr;
	int size;
	int capacity;
};
//-----------------------------------------------------------------//
void initMang(Mang& array, int cap) {
    //Init a new array with capacity equals to cap
    //TODO
    array.arr = new element[cap];
    array.capacity = cap;
}

void ensureCapacity(Mang& array, int newCap) {
    //Extend the capacity of the array
    //TODO
    //newCap = array.capacity * 3;
    newCap += 1;
    Mang newArr;
    newArr.arr = new element[newCap];
    for (int i = 0; i < array.size; i++) {
        newArr.arr[i] = array.arr[i];
    }
    delete[]array.arr;
    array.capacity = newCap;
    array.arr = newArr.arr;
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
void setdefault(Mang &mang) {
    for (int i = 0; i < mang.capacity; i++) {
        mang.arr[i].ID = "NULL";
        mang.arr[i].type = "NULL";
        mang.arr[i].level = -1;
    }
}
void linear(Mang &mang, string s, int key, element value) {
	s = s.substr(7);
	int size = s.size();
	int pos_space = 0;
    string s1 = "";
    string s2 = "";
	for (int i = 0; i < size; i++) {
		if (s[i] == ' ') {
			pos_space = i;
            s1 = s.substr(0, pos_space);
            s2 = s.substr(pos_space + 1);
			break;
		}
	}
	int size_hash = stoi(s1);
	int constant = stoi(s2);
    int step = 0;
    int place = key % size_hash;
    for (int i = 0; i < size_hash; i++) {
        if (mang.arr[place].ID == "NULL") {

        }
    }
}
string insertHash(Mang &mang, string str) {
    return "success";
}
string insertdanhsach(SLinked& danhsach, string id, string type, string _static) {      
    Node* run = danhsach.tail;
    element x;
    x.level = findposlast(danhsach);
    if (_static == "true") x.level = 0;
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
        if (type == "string") {
            x.type = "string";
            x.ID = id;
            addNode(danhsach, x, danhsach.size);
        }
        else if (type == "number") {
            x.ID = id;
            x.type = "number";
            addNode(danhsach, x, danhsach.size);
        }
        else {
            // if (checkfunction(type) == 1) {
            //     if (x.level != 0) return "Invalid";
            //     string s = ",";
            //     x.ID = id;
            //     x.con = typeforfunction(type);
            //     x.type = type;
            //     addNode(danhsach, x, danhsach.size);
            // }
        }
    }
    return "success";
}
int decode(string ID, string level) {
	string str = "";
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
			int result = 0;
			result = (int)ID[i] - 48;
			str += to_string(result);
		}
	}
	return stoi(str);
}

int hash2(int prime, int key) {
    return (prime - (key % prime));
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
int main() {
	SLinked danhsach;
	Mang mang;
	initMang(mang, 10000);
    setdefault(mang);
	string line;
	fstream f;
	f.open("C:/Users/DELL/Desktop/testcase.txt", ios::in);
    int i = 0;
	// while (!f.eof()) {
	// 	getline(f, line);
	// 	//if (checkline(line) == false) throw "Invalid" + line;
    //     text[i] = line;
    //     i++;
	// }
    // if (CheckSubstring(text[0], "LINEAR")) {

    // }
    // if (CheckSubstring(text[0], "QUADRATIC")) {

    // }
    // if (CheckSubstring(text[0], "DOUBLE")) {

    // }
    // string s = "LINEAR 3 4";
    // //s = s.substr(7);
    // //linear(mang, s);
	// cout << decode("a1", to_string(0)) << endl;
    // string s = "QUADRATIC 2223 3112 433333";
    // int size = s.size();
    // string s1 = "";
    // string s2 = "";
    // string s3 = "";
    // s = s.substr(10);
    // for (int i = 0; i < size; i++) {
    //     if (s[i] == ' ') {
    //         s1 = s.substr(0, i);
    //         s = s.substr(i + 1); 
    //         break;
    //     }
    // }
    // size = s.size();
    // for (int i = 0; i < size; i++) {
    //     if (s[i] == ' ') {
    //         s2 = s.substr(0, i);
    //         s3 = s.substr(i + 1);
    //         break;
    //     }
    // }
    // int hashing = hash2(14, 2);
    // cout << hashing << endl;
    // cout << s1 << endl << s2 << endl << s3 << endl;
    string level = "0";
    string ID = "rUEim";
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
    else if (level == "0") {
        int size = ID.size();
        for (int i = 0; i < size; i++) {
            result = (int)ID[i] - 48;
            str += to_string(result);
        }
    }
    //int final = stoi(str);
    string tme = "CALL emd";
    tme = tme.substr(5);
    for (int i = 0 ; i < tme.size(); i++) {
        if (tme[i] == '(') {
                tme = tme.substr(0, i);
                break;
            }
    }
    cout << tme << endl;
    string x = "foo(354562,'ababab',567,m3m3mmw)";
    string name = takenamefunction(x);
    x = x.substr(name.size());
    cout << x << endl;
    x = x.substr(1, x.size() - 2);
    int count_phay = 0;
    cout << x << endl;
    for (int i = 0; i < x.size();i++) {
        if (x[i] == ',') count_phay++;
    }
    string *arr = new string[count_phay + 1];
    int newsize = count_phay + 1;
    int find = 0;
    while (count_phay> 0) {
        find = x.find(",");
        arr[count_phay] = x.substr(0, find);
        x = x.substr(find + 1);
        count_phay--;
    }
    arr[0] = x;
    for (int i = 0; i < newsize; i++) {
        cout << arr[i] << " " << endl;
    }
    
    return 0;
}