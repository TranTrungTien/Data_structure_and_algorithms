#include <iostream>
struct Node
{
    int data;
    Node* next;
    Node* previous;

};

void freeMemory(Node* node)
{
    delete node;
}

Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->previous = nullptr;
    return newNode;
}
Node* addNodeAtFirst(Node*& first, Node*& last, int value)
{
    Node* newNode = createNode(value);
    if (first == nullptr)
    {
        first = last = newNode;
    }
    else
    {
        newNode->next = first;
        first->previous = newNode;
        first = newNode;
    }
    return first;
}

Node* addNodeAtLast(Node*& first, Node*& last, int value)
{
    Node* newNode = createNode(value);
    if (first == nullptr)
    {
        first = last = newNode;
    }
    else
    {
        newNode->previous = last;
        last->next = newNode;
        last = newNode;
    }
    return last;
}

Node* addNodeAtKthPosition(Node*& first, int position, int value)
{
    Node* newNode = createNode(value);
    if (first == nullptr)
    {
        exit(0);
    }
    else
    {
        int count = 1;
        Node* temp = first;
        while (temp->next != nullptr)
        {
            ++count;
            temp = temp->next;
            if (count == position - 1)
            {
                newNode->next = temp->next;
                temp->next = newNode;
                newNode->previous = temp;
                if (newNode->next != nullptr)
                {
                    newNode->next->previous = newNode;
                }
                
            }
            
        }
        
    }
    
    return first;
}

Node* removeNodeAtFirst(Node*& first)
{
    if (first == nullptr)
    {
        exit(0);
    }
    else
    {
        Node* temp = first;
        first = first->next;
        first->previous = nullptr;
        freeMemory(temp);
    }
    return first;
}

Node* removeNodeAtLast(Node*& last)
{
    if (last == nullptr)
    {
        exit(0);
    }
    else
    {
        Node* temp = last;
        last = last->previous;
        last->next = nullptr;
        freeMemory(temp);
    }
    return last;
}

Node* removeNodeAtKthPosition(Node*& first, int position)
{
    Node* temp = first;
    if (first == nullptr)
    {
        exit(0);
    }
    else
    {
        int count = 1;
        while (temp != nullptr)
        {
            if (count == position - 1)
            {
                Node* p = temp->next;
                temp->next = temp->next->next;
                temp->next->previous = temp;
                freeMemory(p);
            }
            temp = temp->next;
            ++count;
        }
        
    }
    return first;
}

void deleteLinkedList(Node*& first)
{
    while (first != nullptr)
    {
        Node* temp = first;
        first = first->next;
        freeMemory(temp);

    }
    
}

void displayLinkedListAtFirst(const Node* first)
{
    if (first == nullptr)
    {
        std::cout << "Linked List is empty " << std::endl;
        return;
    }
    
    while (first != nullptr)
    {
        std::cout << first->data << "\t";
        first = first->next;
    }
    std::cout << std::endl;
    
}

void displayLinkedListAtLast(const Node* last)
{
    if (last == nullptr)
    {
        std::cout << "Linked List is empty " << std::endl;
        return;
    }
    while (last != nullptr)
    {
        std::cout << last->data << "\t";
        last = last->previous;
    }
    std::cout << std::endl;
}

int main()
{
    Node* first = nullptr;
    Node* last = nullptr;

    addNodeAtFirst(first, last, 1);
    addNodeAtFirst(first, last, 2);
    addNodeAtFirst(first, last, 3);
    addNodeAtLast(first, last, 0);
    std::cout << "print value of node from first :\n";
    displayLinkedListAtFirst(first);
    std::cout << "print value of node from last :\n";
    displayLinkedListAtLast(last);
    addNodeAtKthPosition(first, 3, 69);
    std::cout << "print value of node from first after inserting :\n";
    displayLinkedListAtFirst(first);
    std::cout << "print value of node from first after removing at first :\n";
    removeNodeAtFirst(first);
    displayLinkedListAtFirst(first);
    std::cout << "print value of node from first after removing at last :\n";
    removeNodeAtLast(last);
    displayLinkedListAtFirst(first);
    std::cout << "print value of node from first after removing at k-th position :\n";
    removeNodeAtKthPosition(first, 2);
    displayLinkedListAtFirst(first);
    std::cout << "Delete Linked List : \n";
    deleteLinkedList(first);
    displayLinkedListAtFirst(first);

    return 0;
}