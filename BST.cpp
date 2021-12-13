#include <iostream>
#include <string>
#include <sstream>

using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class BinarySearchTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    
    //Helping function
    Node* Insert(Node* root, T value)
    {
        if (!root)
        {
            // Insert the first node, if root is NULL
            this->root = new Node(value);
            return this->root;
        }

        // Insert data.
        if (value > root->value)
        {
            // Insert right node data, if the 'value'
            // to be inserted is greater than 'root' node data.

            // Process right nodes.
            root->pRight = Insert(root->pRight, value);
        }
        else
        {
            // Insert left node data, if the 'value'
            // to be inserted is greater than 'root' node data.

            // Process left nodes.
            root->pLeft = Insert(root->pLeft, value);
        }
        // Return 'root' node, after insertion.
        return root;
    }
    void add(T value) {
        //TODO
        Insert(this->root, value);
    }
    Node* minValueNode(Node* node)
    {
        Node* current = node;

        /* loop down to find the leftmost leaf */
        while (current && current->pLeft != NULL)
            current = current->pLeft;
        return current;
    }

    /* Given a binary search tree and a key, this function
    deletes the key and returns the new root */
    Node* deletenode(Node* root, T key)
    {
        // base case
        if (root == NULL)
            return root;

        // If the key to be deleted is
        // smaller than the root's
        // key, then it lies in left subtree
        if (key < root->value)
            root->pLeft = deletenode(root->pLeft, key);

        // If the key to be deleted is
        // greater than the root's
        // key, then it lies in right subtree
        else if (key > root->value)
            root->pRight = deletenode(root->pRight, key);

        // if key is same as root's key, then This is the node
        // to be deleted
        else {
            // node has no child
            if (root->pLeft == NULL and root->pRight == NULL)
                return NULL;

            // node with only one child or no child
            else if (root->pLeft == NULL) {
                Node* temp = root->pRight;
                delete(root);
                return temp;
            }
            else if (root->pRight == NULL) {
                Node* temp = root->pLeft;
                delete(root);
                return temp;
            }

            // node with two children: Get the inorder successor
            // (smallest in the right subtree)
            Node* temp = minValueNode(root->pRight);

            // Copy the inorder successor's content to this node
            root->value = temp->value;

            // Delete the inorder successor
            root->pRight = deletenode(root->pRight, temp->value);
        }
        return root;
    }
    void deleteNode(T value) {
        //TODO
        deletenode(this->root, value);
    }
    string inOrderRec(Node* root) {
        stringstream ss;
        if (root != nullptr) {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }

    string inOrder() {
        return inOrderRec(this->root);
    }

    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;
    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
};

int main() {
    
    string str = "ASSIGN x 'abc'";
    str = str.substr(7);
    string id, type;
    int val = 0;
    int space = 0;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') space = i;
    }
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            val = i;
            id = str.substr(0, val);
            type = str.substr(val + 1, space - id.size() - 1);
            //_static = str.substr(id.size() + type.size() + 2);
            break;
        }
    }
    {
        int x = 5;
    }
    x = 7;
    cout << id << endl << type << endl;
    return 0;
}