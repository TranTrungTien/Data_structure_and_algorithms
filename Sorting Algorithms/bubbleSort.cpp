#include <iostream>
#define N 4

void bubbleSort(int* array)
{
    for (int i = N - 1; i >= 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;

            }
            
        }
        
    }
    
}

int main()
{
    int array[N] = { 3, 4, 1, 2};
    bubbleSort(array);
    for (int i = 0; i < N ; ++i)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
    return 0;
}