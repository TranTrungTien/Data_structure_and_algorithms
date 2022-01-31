#include <iostream>
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, i);
    }    
}
void heapSort(int* arr, int n)
{
    for (int i = n / 2; i >= 0; --i)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; --i)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    
}
void display(const int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] <<" ";
    }
    std::cout << std::endl;
    
}

int main()
{
    int* arr = new int[6] {4, 8, 2, 1, 3, 5};
    int n = 6;
    std::cout << "before sorting:" << std::endl;
    display(arr, n);
    heapSort(arr, n);
    std::cout << "after sorting:" << std::endl;
    display(arr, n);
    delete arr;
    return 0;
}