#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};
bool isnode(Node *t) {
    return (t->left == nullptr && t->right == nullptr);
}

int countleaf(Node *t) {
    if (t == nullptr) return 0;
    if (isnode(t)) return 1;
    return countleaf(t->left) + countleaf(t->right);
}
Node *insertNode(Node*t, int x) {
    if (t == nullptr) {
        Node *temp = new Node;
        temp->data = x;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    }
    else {
        if (x < t->data) {
            t->left = insertNode(t->left, x);
        }
        else t->right = insertNode(t->right, x);
    }
}
void printmiddle(Node *t) {
    if (t != nullptr) {
        printmiddle(t->left);
        cout << t->data << " ";
        printmiddle(t->right);
    }
    
}
void printpre(Node *t) {
    if (t != nullptr) {
        cout << t->data << " ";
        printpre(t->left);
        printpre(t->right);
    }
}
void printpost(Node *t) {
    if (t != nullptr) {
        printpost(t->left);
        printpost(t->right);
        cout << t->data << " ";
    }
}
int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int level(Node *t) {
    if (t == NULL) return -1;
    //if (isnode(t)) return 0;
    return 1 + max(level(t->left), level(t->right));
}
bool checkAVL(Node *t) {
    if (t == NULL) return true;
    if (abs(level(t->left) - level(t->right)) > 1) return false;
    return checkAVL(t->left) && checkAVL(t->right);
}

int main() {
    // int n;
    // cin >> n;
    // Node *t = nullptr;
    // int x;
    // for (int i = 0; i < n; i++) {
    //     cin >> x;
    //     t = insertNode(t, x);
    // }
    // //printmiddle(t);
    // cout << checkAVL(t) << endl;
    int f = 7;
    cout << f / 2;
    return 0;
}