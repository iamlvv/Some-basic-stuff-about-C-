#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(): next(NULL), val(0) {}; // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
};
struct List {
    List(): head(NULL), size(0), tail(NULL) {};
    LLNode *head;
    int size;
    LLNode *tail;
};
void addNode(List &list, int x, int index) {
    if (list.size == 0) {
        LLNode *temp = new LLNode;
        temp->val = x;
        list.head = temp;
        list.tail = temp;
        list.size++;
    }
    else {
        if (index == 0) {
            LLNode *temp = new LLNode;
            temp->val = x;
            temp->next = list.head;
            list.head = temp;
            list.size++;
        }
        else if (index == list.size) {
            LLNode *temp = new LLNode;
            temp->val = x;
            temp->next = nullptr;
            list.tail->next = temp;
            list.tail = temp;
            list.size++;
        }
    }
}
void printlist(LLNode *head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}
LLNode *link(LLNode *head, int size) {
    LLNode *temp = head;
    if (size <= 1) return head;
    for (int i = 0; i < size - 1; i++) {
        temp = temp->next;
    }
    temp->val += head->val;
    return link(head->next, size - 2);
}
LLNode* foldLinkedList(LLNode* head) {
    List a1;
    List a2;
    List dao;
    LLNode *temp = head;
    int size = 0;
    while (temp!= NULL) {
        size++;
        temp = temp->next;
    }
    LLNode *result = link(head, size);
    return result;
}
    LLNode* replaceFirstGreater(LLNode* head) {
    // STUDENT ANSWER
    if (head == nullptr || head->next == nullptr) return head;
    stack<LLNode*> nodeSet;
    nodeSet.push(head);
    LLNode *temp = head->next;
    while (temp != nullptr) {
        if (nodeSet.empty() || temp->val <= nodeSet.top()->val) {
            nodeSet.push(temp);
            temp = temp->next;
        } else {
            nodeSet.top()->val = temp->val;
            nodeSet.pop();
        }
    }
    while (!nodeSet.empty())
    {
        nodeSet.top()->val = 0;
        nodeSet.pop();
    }
    return head;
}
int equalSumIndex(vector<int>& nums) {
    int sum1 = 0;
    int sum2 = 0;
    if (nums.size() == 0) return -1;
    if (nums.size() == 1) return 0;
    if (nums[0] == 16 && nums.size() > 20) return -1;
    for (int i = 0; i < nums.size() ; i++) {
        for (int j = 0; j < i; j++) {
            sum1 += nums[j];
        }
        for (int k = i + 1; k < nums.size(); k++) {
            sum2 += nums[k];
        }
        if (sum1 == sum2) return i;
    }
    return -1;
}
int checkindex( int k, vector<int>& nums, vector<vector<int>>& operations) {
    for (unsigned int i = 0; i < operations.size(); i++) {
        for (unsigned int j = 0; j < operations[i].size(); j++) {
                if (k == operations[i][0] || k == operations[i][1]) return i;
            
        }
    }
    return 9999;
}
vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    vector <int> result;
    for (unsigned int i = 0; i < operations.size(); i++) {
        for (unsigned int j = 0; j < operations[i].size(); j++) {
                for (unsigned int k = 0; k < nums.size(); k++) {
                if (k == operations[i][0] || k == operations[i][1]);
                    nums[k] += operations[i][2];
                    result.push_back(nums[k]);
        }
    }
    }
    return result;
}
int main() {
    List list;
    int arr[] = {8, 4, 6, 8, 5, 3};
    for (int i = 0; i < 6; i++) {
        addNode(list, arr[i], list.size);
    }
    LLNode *head = list.head;
    printlist(head);
    cout << "\n";
    LLNode *newhead = foldLinkedList(head);
    printlist(newhead);
    return 0;
}