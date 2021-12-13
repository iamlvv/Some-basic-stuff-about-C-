#include <iostream>
#include <string>

using namespace std;

struct node {
    int data;
    node *next;
    node *pre;
};
struct doublelist {
    node *head;
    node *tail;
};

doublelist *createlist(int x) {
    doublelist *l = new doublelist;
    l->head = new node;
    l->head->data = x;
    l->head->next = NULL;
    l->head->pre = NULL;
    l->tail = l->head;
    return l;
}
doublelist *addHead(doublelist *l, int x) {
    node *temp = new node;
    temp->data = x;
    temp->next = l->head;
    temp->pre = NULL;
    l->head->pre = temp;
    l->head = temp;
    return l;
}
doublelist *addTail(doublelist *l, int x) {
    node *temp = new node;
    temp->data = x;
    temp->next = nullptr;
    temp->pre = l->tail;
    l->tail->next = temp;
    l->tail = temp;
}
doublelist *addNode(doublelist *l, int pos, int x) {
    node *temp = new node;
    temp->data = x;
    node *run = l->head;
    int count = 0;
    while (run != nullptr && count != pos - 1) {
        count++;
        run = run->next;
    }
    temp->pre = run;
    temp->next = run->next;
    run->next->pre = temp;
    run->next = temp;
    return l;
}
doublelist *deleteHead(doublelist *l) {
    node *p = l->head->next;
    node *temp = l->head;
    p->pre = nullptr;
    l->head = p;
    delete(temp);
    return l;
}
doublelist *deleteTail(doublelist *l) {
    node *p = l->tail->pre;
    node *temp = l->tail;
    p->next = nullptr;
    l->tail = p;
    delete(temp);
    return l;
}
doublelist *deleteAt(doublelist *l, int k) {
    node *p = l->head;
    for (int i = 0; i < k - 1; i++) {
        p = p->next;
    }
    node *temp = p->next;
    node *p2 = temp->next;
    p->next = p2;
    p2->pre = p;
    delete(temp);
    return l;
}
void printlist(doublelist *l) {
    node *temp = l->head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main() {
    int n;
    cin >> n;
    int k;
    
    int x;
    cin >> x;
    doublelist *l = createlist(x);
    for (int i = 1; i < n; i++) {
        cin >> x;
        l = addTail(l, x);
    }
    cin >> k;
    if (k == 0) l = deleteHead(l);
    else if (k == n) l = deleteTail(l);
    else l = deleteAt(l, k);
    printlist(l);
    return 0;
}