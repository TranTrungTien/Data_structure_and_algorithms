#include <iostream>

struct Node
{
    int data;
    Node* next;
};

struct singlyLinkedList
{
    Node* head;
};


Node* createNode(int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = nullptr;

    return temp;
}


void addNodeAtFront(singlyLinkedList &l, int value)
{
    Node* temp = createNode(value);
    temp->next = l.head;
    l.head = temp;
}

void addNodeAtTail(singlyLinkedList &l, int value)
{
    Node* temp = createNode(value);
    if (l.head == nullptr)
    {
        l.head = temp;
    }
    else
    {
        Node* phead = l.head;
        while (phead->next != nullptr) // not phead != nullptr
        {
            phead = phead->next;
        }
        phead->next = temp;
    }
}

void addNodeWithValue(int newValue, int value, singlyLinkedList &l)
{
    Node* newNode = createNode(newValue);
    if (l.head == nullptr)
    {
        std::cout << "empty list" << std::endl;
        return;
    }
    else
    {
        Node* p = l.head;
        while (p->next->data != value)
        {
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
    
}

void removeHead(singlyLinkedList &l)
{
    Node* p = l.head;
    if (p == nullptr)
    {
        return;
    }
    else
    {
        l.head = l.head->next;
        delete p;
    }
    
}

void removeTail(singlyLinkedList &l)
{
    Node* p = l.head;
    if (p == nullptr)
    {
        return;
    }
    else
    {
        while (p->next->next != nullptr)
        {
            p = p->next;
        }
        delete p->next;     
        p->next = nullptr;
    }
    
    
}

void removeNodeWithValue(int value, singlyLinkedList &l)
{
    Node* p = l.head;
    if (p == nullptr)
    {
        return;
    }
    else
    {
        while (p->next->data != value)
        {
            p = p->next;
        }
        Node* temp = p->next;
        p->next = p->next->next;
        delete temp;
    }
    
    
}

void getKthData(int position , singlyLinkedList &l)
{
    int count = 0;
    Node * p = l.head;
    while (p != nullptr)
    {
        ++count;
        if (count == position)
        {
            std::cout << p->data << std::endl;
        }
        p = p->next;
        
    }
    
}

void getKthPosition(int value, singlyLinkedList &l)
{
    Node* p = l.head;
    int position = 1;
    while (p->data != value)
    {
        p = p->next;
        ++position;
    }
    std::cout << "the position of value is :" << std::endl << position;
}

void displayLinkedList(singlyLinkedList const& l)
{
    Node *head = l.head;
    while (head != nullptr)
    {
        std::cout << head->data << "\t";
        head = head->next;
    }
    std::cout << std::endl;
}
int main()
{
    singlyLinkedList l;
    l.head = nullptr;
    addNodeAtFront(l, 2); // add more node at head
    addNodeAtFront(l, 3); // add more node at head
    addNodeAtTail(l, 1); // add more node at tail
    addNodeAtFront(l, 4); // add more node at head
    addNodeAtFront(l, 5); // add more node at head
    addNodeAtTail(l, 0); // add more node at tail
    displayLinkedList(l);
    addNodeWithValue(69, 3, l); // add node with value at any position
    displayLinkedList(l);
    removeHead(l); // remove node at head
    displayLinkedList(l);
    removeTail(l); // remove node at tail
    displayLinkedList(l);
    removeNodeWithValue(2, l); // remove node with value at any position
    displayLinkedList(l); // display
    std::cout << "K-th value is :" << std::endl;
    getKthData(1, l); // get data at k-th position
    getKthPosition(69, l); // get position with value

    return 0;
}