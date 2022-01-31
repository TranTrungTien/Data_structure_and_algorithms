#include <iostream>

struct Node
{
    int data;
    Node* next;
};

void initialization(Node*& last)
{
    last->data = 0;
    last = nullptr;
}

Node* createNode(int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = nullptr;

    return temp;
}

void addIntoEmptyList(Node*& last, int value)
{
    Node* temp = createNode(value);
    last = temp;
    temp->next = last;

}
void addNodeAtFirst(Node*& last, int value)
{
    if (last == nullptr)
    {
        addIntoEmptyList(last, value);
        return;
    }
    else
    {
        Node* temp = createNode(value);
        temp->next = last->next;
        last->next = temp;
    }
    
}

void display(Node* const last)
{
    Node* p = last->next;
    do
    {
        std::cout << p->data;
        p = p->next;
    } while (p != last->next);
    
    std::cout << std::endl;
}

int main()
{
    Node* last;
    initialization(last);
    addNodeAtFirst(last, 1);
    addNodeAtFirst(last, 2);
    addNodeAtFirst(last, 3);
    addNodeAtFirst(last, 4);

    display(last);
    return 0;
}