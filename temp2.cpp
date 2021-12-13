Node* InsertNode(Node* root, T value)
    {
        if (!root)
        {
            Node* temp = new Node(value);
            temp->pLeft = nullptr;
            temp->pRight = nullptr;
            return temp;
        }
        if (value > root->value)
        {
            root->pRight = InsertNode(root->pRight, value);
        }
        else
        {
            root->pLeft = InsertNode(root->pLeft, value);
        }
        return root;
    }
    void add(T value) {
        //TODO
        if (!this->root) {
            Node* temp = new Node(value);
            temp->pLeft = nullptr;
            temp->pRight = nullptr;
            this->root = temp;
            return;
        }
        Insert(this->root, value);
    }
    Node* getmin(Node* node)
    {
        Node* temp = node;
        while (temp && temp->pLeft != NULL)
            temp = temp->pLeft;
        return temp;
    }

    Node* deletenode(Node* root, T value)
    {
        if (root == NULL)
            return root;
        if (value < root->value)
            root->pLeft = deletenode(root->pLeft, value);
        else if (value > root->value)
            root->pRight = deletenode(root->pRight, value);
        else {
            if (root->pLeft == NULL && root->pRight == NULL)
            {
                delete (root);
                return NULL;
            }
            else if(root->pRight == NULL)
            {
            Node* temp = root;
            root= root->pLeft;
            delete temp;
        }
        else if(root->pLeft == NULL)
        {
            Node* temp = root;
            root= root->pRight;
            delete temp;
        }
            else { 
        if (root->pLeft==NULL and root->pRight==NULL)
            return NULL;
       
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
        Node* temp = getmin(root->pRight);
        root->value = temp->value;
        root->pRight = deleteNode(root->pRight, temp->value);
            }
        }
        return root;
    }
    void deleteNode(T value) {
        //TODO
        deletenode(this->root, value);
    }



    bool subFind(Node* root, T i) {
    // TODO: return true if value i is in the tree; otherwise, return false.
    if (root->value == i) return true;
    if (root == nullptr) return false;
    
    else if (root->value > i)
        return findRec(root->pLeft, i);
    else
        return findRec(root->pRight, i);
}

bool find(T i) {
    // TODO: return true if value i is in the tree; otherwise, return false.
    return subFind(this->root, i);
}

T subSum(Node* root, T l, T r) {
    // TODO: return the sum of all element in the tree has value in range [l,r].
    if (root == nullptr) return 0;
    T res = 0;
    if (root != nullptr && root->value >= l && root->value <= r)
        res = root->value;
    else
        res = 0;
    return res + sumRec(nodeRoot->pLeft, l, r) + sumRec(root->pRight, l, r);
}

T sum(T l, T r) {
    // TODO: return the sum of all element in the tree has value in range [l,r].
    return subSum(this->root, l, r);
}