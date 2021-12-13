#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
    string value;
    Node *left = NULL;
    Node *right = NULL;

    Node (string value) {
        this->value = value;
    }
};

class ExpTree {
    Node *root;
    public:

    float change(string s) {
        float num = 0; 
        if(s[0] != '-') 
            for (int i = 0; i < s.length(); i++) 
                num = num * 10 + (int(s[i]) - 48); 
        else
            for (int i = 1; i < s.length(); i++) 
            { 
                num = num * 10 + (int(s[i]) - 48); 
                num = num * -1; 
            }  
        return num; 
    }
    float eval(Node *root) {
        Node *temp = root;
        if (temp == NULL) {
            return 0;
        }
        if (temp->left && !temp->right) {
            return change(temp->value);
        }
        float caleft = eval(temp->left);
        float caright = eval(temp->right);
        if (root->value == "+") return caleft + caright;
        else if (root->value == "-") return caleft - caright;
        else if (root->value == "*") return caleft * caright;
        return caleft / caright;
    }
    float eval() {
        return eval(this->root);
    }
   
    bool isIrrepressible(Node *proot) {
        Node *root = proot;
        while (root != NULL) {
        if (!root) return false;
        if (!root->left && !root->right) return false;
        if (root->value == "*" || root->value == "/") {
            if (root->left->value == "+" || root->left->value == "-") return true;
            if (root->right->value == "+" || root->right->value == "-") return true;
        } 
        root = root->left;
        }
        Node *root2 = proot;
        while (root2 != NULL) {
            if (!root2) return false;
            if (!root2->left && !root2->right) return false;
            if (root2->value == "*" || root2->value == "/") {
            if (root2->left->value == "+" || root2->left->value == "-") return true;
            if (root2->right->value == "+" || root2->right->value == "-") return true;
        } 
        root2 = root2->right;
        }        
        return false;
    }
    bool isIrrepressible() {
        return isIrrepressible(this->root);
    }
    int countNode (Node *root) {
        if (root == NULL) return 0;
        int count = 0;
        if (root->left && root->right) count++;
        count += countNode(root->left) + countNode(root->right);
        return count;
    }
    //Câu 3 độ phức tạp time là O(1);
    //Còn về mặt không gian là O(h + k);


//Đề câu 4: in k node liền sau (khong gian: O(n), thời gian: O(nlogn) với n là số Node
//Giải thuật: tương tự câu 3
// Duyệt trung thứ tự
 };
int main() {
    return 0;
}