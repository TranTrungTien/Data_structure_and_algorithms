#include <iostream>


struct Node
{
    int data;
    Node* left;
    Node* right;
};

class ManagerTree
{
private:
    Node* root;
    void initialization();
public:
    ManagerTree();
    ManagerTree(int value);
    ~ManagerTree();
    Node* createNode(int value);
    
    bool addNodeAtLeft(int value);
    bool addNodeAtRight(int value);
    
    void preorder() const;

    bool deleteNodeLeafLeft();
    bool deleteNodeLeafRight();
    bool deleteNodeByValue(int value);
    
    bool deleteNode(Node*& node);
    bool deleteTree();
};

ManagerTree::ManagerTree()
{
    initialization();
}

ManagerTree::ManagerTree(int value)
{
    initialization();
    Node* tmp = createNode(value);
    this->root = tmp;
}

ManagerTree::~ManagerTree()
{

}


void ManagerTree::initialization()
{
    this->root = nullptr;
    this->root->data = 0;
    this->root->left = nullptr;
    this->root->right = nullptr;
}

Node* ManagerTree::createNode(int value)
{
    Node* tmp = new Node();
    tmp->data = value;
    tmp->left = nullptr;
    tmp->right = nullptr;
    return tmp;
}

void ManagerTree::preorder()const
{
    if(this->root == nullptr)
    {
        std::cout << "Empty Tree" << std::endl;
        return;
    }
    else
    {
        Node* tmp = this->root;
        
    }

}

int main(int argc, char* agrv[])
{
    ManagerTree* tree = new ManagerTree(1);

    return 0;
}