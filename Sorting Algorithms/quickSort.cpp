#include <iostream>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int* array, int low, int high)
{
    int pivot = array[low];
    int i = (high - 1);
    for (int j = high; j > low; --j)
    {
        if (array[j] > pivot)
        {
            --i;
            swap(array[j], array[i]);
        }
        
    }
    swap(array[i - 1], low);
    return (i - 1);
}


void quickSort(int* array, int low, int high)
{
    if (low < high)
    {
        int pos = partition(array, low, high);
        quickSort(array, pos + 1, high);
        quickSort(array, low, pos - 1);
    }
    
}
void display( const int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}

int main()
{
    int array[] = {4 , 5, 7, 10 , 2, 9, 8 , 34, 52, 6, 23, 5, 33 , 57, 23,34,76,4, 45,66};
    int n = sizeof(array) / sizeof(int);
    quickSort(array, 0, n - 1);
    display(array, n);
}