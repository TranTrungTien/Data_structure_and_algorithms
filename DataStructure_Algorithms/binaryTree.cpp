#include <iostream>
struct Node
{
    int data;
    Node* left;
    Node* right;
};

void initialization(Node*& root)
{
    root->data = 0;
    root->left = nullptr;
    root->right = nullptr;
}

Node* createNode(int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;

}

void addNodeAtRoot(Node*& root, int value)
{
    Node* temp = createNode(value);
    root = temp;
}

void addNodeAtleft(Node*& root, int value)
{
   
    Node* temp = root;
    while(temp->left != nullptr)
    {
        temp = temp->left;
    }
    Node* p = createNode(value);
    temp->left = p;
}

void addNodeAtRight(Node*& root, int value)
{

    Node* temp = root;
    while(temp->right != nullptr)
    {
        temp = temp->left;
    }
    Node* p = createNode(value);
    temp->right = p;
}


void preorder(const Node* root)
{
    if (root)
    {
        std::cout << root->data << "\t";
        preorder(root->left);
        preorder(root->right);
    }
    
}

void deleteTree(Node*& root)
{
    if (root == nullptr)
    {
        std::cout << "Empty Tree" << std::endl;
    }
    else
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
    
}

int main()
{
    Node* root;
    initialization(root);
    addNodeAtRoot(root, 1);
    addNodeAtleft(root, 2);
    addNodeAtRight(root, 3);
    addNodeAtleft(root, 4);
    addNodeAtRight(root, 5);
    addNodeAtleft(root, 6);
    addNodeAtRight(root, 7);

    preorder(root);
    deleteTree(root);

    return 0;
}