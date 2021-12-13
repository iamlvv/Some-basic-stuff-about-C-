// C++ program to insert a node in AVL tree
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }
	Node *rLeft(Node *&ptr) {
    Node *temp = ptr;
    ptr = ptr->pRight;
    temp->pRight = ptr->pLeft;
    ptr->pLeft = temp;
    return ptr; 
}
Node *rRight(Node *&ptr) {
    Node *temp = ptr;
    ptr = ptr->pLeft;
    temp->pLeft = ptr->pRight;
    ptr->pRight = temp;
    return ptr;
}
Node *maxLeftValue(Node *ptr) {
	while (ptr != NULL) {
		ptr = ptr->pLeft;
	}
	return ptr;
}
Node *insertAVL(Node *ptr, const T& value) {
    if (ptr == NULL) return new Node(value);
    if (ptr->data > value) {
        ptr->pLeft = insertAVL(ptr->pLeft, value);
    }
    else ptr->pRight = insertAVL(ptr->pRight, value);
    int balance = this->getHeightRec(ptr->pLeft) - this->getHeightRec(ptr->pRight);
    if (balance > 1 && this->getHeightRec(ptr->pLeft->pLeft) - this->getHeightRec(ptr->pLeft->pRight) >= 0) {
        ptr = rRight(ptr);
    }
    else if (balance > 1 && this->getHeightRec(ptr->pLeft->pLeft) - this->getHeightRec(ptr->pLeft->pRight) < 0) {
        ptr->pLeft = rLeft(ptr->pLeft);
        ptr = rRight(ptr);
    }
    else if (balance < -1 && this->getHeightRec(ptr->pRight->pRight) - this->getHeightRec(ptr->pRight->pLeft) >= 0) {
        ptr = rLeft(ptr);

    }
    else if (balance < -1 && this->getHeightRec(ptr->pRight->pRight) - this->getHeightRec(ptr->pRight->pLeft) < 0) {
        ptr->pRight = rRight(ptr->pRight);
        ptr = rLeft(ptr);
    }
    return ptr;
}
void insert(const T &value){
    //TODO
    this->root = insertAVL(this->root, value);
}

Node *remove(Node *ptr, const T &value) {
	if (ptr == NULL) return NULL;
	if (ptr->data > value) ptr->pLeft = remove(ptr->pLeft, value);
	else if (ptr->data < value) ptr->pRight = remove(ptr->pRight, value);
	else {
		Node *temp = ptr->pLeft ? (ptr->pLeft) : ptr->pRight;
		if(ptr->pLeft == NULL || ptr->pRight == NULL) {
			delete ptr;
			ptr = temp;
			return ptr;
		}
		else {
			temp = maxLeftValue(ptr->pLeft);
			ptr->data = temp->data;
			ptr->pLeft = remove(ptr->pLeft, temp->data);
		}
	}
	int balance = this->getHeightRec(ptr->pLeft) - this->getHeightRec(ptr->pRight);
    if (balance > 1 && this->getHeightRec(ptr->pLeft->pLeft) - this->getHeightRec(ptr->pLeft->pRight) >= 0) {
        ptr = rRight(ptr);
    }
    else if (balance > 1 && this->getHeightRec(ptr->pLeft->pLeft) - this->getHeightRec(ptr->pLeft->pRight) < 0) {
        ptr->pLeft = rLeft(ptr->pLeft);
        ptr = rRight(ptr);
    }
    else if (balance < -1 && this->getHeightRec(ptr->pRight->pRight) - this->getHeightRec(ptr->pRight->pLeft) >= 0) {
        ptr = rLeft(ptr);

    }
    else if (balance < -1 && this->getHeightRec(ptr->pRight->pRight) - this->getHeightRec(ptr->pRight->pLeft) < 0) {
        ptr->pRight = rRight(ptr->pRight);
        ptr = rLeft(ptr);
    }
	return ptr;
}
    void remove(const T &value)
    {
        //TODO
		this->root = remove(this->root, value);
    }

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};
//--------------------------------------------------------------------------//


// Driver Code
int main()
{	
	AVLTree<int> avl;
int arr[] = {10,52,98,32,68,92,40,13,42,63,99,100};
for (int i = 0; i < 12; i++){
	avl.insert(arr[i]);
}
avl.remove(13);
avl.printTreeStructure();
	return 0;
}

// This code is contributed by
// rathbhupendra
