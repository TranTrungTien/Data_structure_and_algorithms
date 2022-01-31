#include <iostream>

void backtracking(int*, int*, int, int);
void display(int*, int);
// Tired....
int main()
{
    int n = 6;
    int array[n] = {};
    int T[n] = {};
    array[0] = 1;
    T[0] = 0;
    backtracking(array, T, n , 1);
    return 0;
}

void backtracking(int* array, int* T, int n, int i)
{
    int j;
    for (j = array[i - 1]; j <= (n - T[i - 1]); ++j)
    {
        array[i] = j;
        T[i] = T[i - 1] + j;
        if (T[i] == n)
        {
            display(array, i);
        }
        backtracking(array, T, n, i + 1); 
    }
    
}

void display(int* array, int n)
{
    for (int k = 1; k <= n; ++k)
    {
        std::cout << array[k] << "  ";
    }
    std::cout << std::endl;   
}
