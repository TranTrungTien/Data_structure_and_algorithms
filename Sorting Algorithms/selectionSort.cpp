#include <iostream>
#define N 4
void selectionSort(int* array)
{
    for (int i = 0; i < N; i++)
    {
        int j = i + 1;
        while (j < N )
        {
            
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }

            ++j;
        }
        
    }
    
}

int main()
{
    int array[N] = { 3, 4, 1, 2};
    selectionSort(array);
    for (int i = 0; i < N ; ++i)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
    return 0;
}