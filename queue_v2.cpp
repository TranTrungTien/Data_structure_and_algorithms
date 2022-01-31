#include <iostream>
#define MAX 10

bool isFull(int n)
{
    if (n == MAX)
    {
        return true;
    }
    return false;
}

void enQueue(int* queue, int& rear, int v, int& n)
{
    if (isFull(n))
    {
        std::cout << "Queue is full" << std::endl;
        return;
    }
    else
    {
        rear %= MAX;
        queue[rear] = v;
        ++rear;
        ++n;
        return;
    }
}
bool isEmpty(int n)
{
    if(n == 0)
    {
        return true;
    }
    return false;
}

void deQueue(int* queue, int& front, int& n)
{
    if (isEmpty(n))
    {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    else
    {
        front %= MAX;
        queue[front] = 0;
        ++front;
        --n;
        return;
    }
}

int peek(int* queue, int front, int n)
{
    if (isEmpty(n))
    {
        std::cout << "Queue is empty" << std::endl;
        return -1;
    }
    return queue[front];
}

int main()
{
    int queue[MAX] = {0};
    int front = 0;
    int rear = 0;
    int n = 0;
    enQueue(queue, rear, 1, n);
    enQueue(queue, rear, 2, n);
    enQueue(queue, rear, 3, n);
    enQueue(queue, rear, 4, n);
    enQueue(queue, rear, 5, n);
    enQueue(queue, rear, 6, n);
    enQueue(queue, rear, 7, n);
    enQueue(queue, rear, 8, n);
    enQueue(queue, rear, 9, n);
    enQueue(queue, rear, 10, n);
    //std::cout << peek(queue, front, rear) << std::endl;
    deQueue(queue, front, n);
    deQueue(queue, front, n);
    deQueue(queue, front, n);
    deQueue(queue, front, n);
    deQueue(queue, front, n);
    deQueue(queue, front, n);
    deQueue(queue, front, n);
    deQueue(queue, front, n);
    deQueue(queue, front, n);
    deQueue(queue, front, n);

    enQueue(queue, rear, 11, n);
    enQueue(queue, rear, 12, n);
    enQueue(queue, rear, 13, n);
    enQueue(queue, rear, 14, n);
    enQueue(queue, rear, 15, n);

    deQueue(queue, front, n);
    deQueue(queue, front, n);
    deQueue(queue, front, n);
    deQueue(queue, front, n);
    return 0;
}