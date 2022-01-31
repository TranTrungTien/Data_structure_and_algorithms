//sort by column using insertion sort.


#include <iostream>

void swap(int& a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

}

void sorting(int array[][4], int rows, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 1; j < rows; j++)
        {
            int temp = array[j][i];
            int k = j;
            while (temp < array[k - 1][i] && k > 0)
            {
                swap(array[k][i], array[k - 1][i]);
                --k;
            }
            swap(array[k][i], temp);
            
        }
        
    }
    
}

void display2D(int array[][4], int rows, int cols)
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


int main()
{
    int m[][4] = {{9, 8, 7, 1},
                  {7, 3, 0, 2},
                  {9, 5, 3, 2},
                  {6, 3, 1, 2}};
    int r = sizeof(m[0]) / sizeof(m[0][0]);
    int c = sizeof(m) / sizeof(m[0]);
    sorting(m, r, c);
    display2D(m, r, c);
    return 0;
}