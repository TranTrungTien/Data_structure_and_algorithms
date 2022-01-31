#include <iostream>
#define N 4

void insertionSort(int* array)
{
    for (int i = 1; i <= N; i++)
    {
        int x = array[i];
        int j = i - 1;
        for ( ; j >= 0 && x < array[j]; --j)
        {
            array[j + 1] = array[j];

        }
        array[j + 1] = x;
    }
}

int main()
{
    int array[N] = { 3, 4, 1, 2};
    insertionSort(array);
    for (int i = 0; i < N ; ++i)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
    return 0;
}