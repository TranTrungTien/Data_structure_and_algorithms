//sort by translating into 1d array and sort 1d array, finally reverse translation

#include <iostream>


int* into1d(int array[][4],int rows, int cols)
{
    int* tempArr = new int[rows * cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            tempArr[i * cols + j] = array[i][j];
        }
        
    }
    return tempArr;

}

int** into2d(int *array, int rows, int cols)
{
    int** tempArr = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        tempArr[i] = new int[cols];
    }
    
    /*for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            tempArr[i][j] = array[i * cols + j];
        }
        
    }*/

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            tempArr[i][j] = array[i * cols + j]; 
        }
        
    }
    
    return tempArr;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sorting(int* array, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if(array[i] > array[j])
            {
                swap(array[i], array[j]);
            }
        }
        
    }
    
}

void display2D(int** array, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout<< array[i][j] <<"\t";
        }
        std::cout << std::endl;
    }  
}

void display1D(const int* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}

void sorting(int array[][4], int rows, int cols)
{
    int* arr = into1d(array, rows, cols);
    sorting(arr, rows * cols);
    int** arr2d = into2d(arr, rows, cols);
    display2D(arr2d, rows, cols);
}


int main()
{
    int m[][4] = {{9, 8, 7, 1},
                  {7, 3, 0, 2},
                  {9, 5, 3, 2},
                  {6, 3, 1, 2}};
    int r = sizeof(m[0]) / sizeof(m[0][0]);
    int c = sizeof(m) / sizeof(m[0]);
    sorting(m, r, c);
    return 0;
}

// This code is contributed by Rutvik_56
