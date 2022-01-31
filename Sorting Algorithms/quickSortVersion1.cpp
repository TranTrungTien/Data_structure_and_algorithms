#include <iostream>
#include <ctime>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && array[left] < pivot)
        {
            left++;
        }
        while (right >= left && array[right] > pivot)
        {
            --right;
        }
        if (left >= right) break;
        swap(array[left], array[right]);
        ++left;
        --right;
    }
    swap(array[left], array[high]);
    return left;
}

void quickSort(int *array, int low, int high)
{
    if (low < high)
    {
        int result = partition(array, low, high);
        quickSort(array, low, result - 1);
        quickSort(array, result + 1, high);
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

// 4 , 5, 3, 7, 10 , 1 , 2, 9, 8
int main()
{
    clock_t start = clock();
    int array[] = {4 , 5, 7, 10 , 2, 9, 8 , 34, 52, 6, 23, 5, 33 , 57, 23,34,76,4, 45,66};
    int n = sizeof(array) / sizeof(int);
    quickSort(array, 0, n - 1);
    display(array, n);
    clock_t end = clock();
    long time = end - start;
    std::cout << "Time needed:" << time << std::endl;
}