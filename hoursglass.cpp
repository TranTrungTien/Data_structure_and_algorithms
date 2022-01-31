#include <iostream>

int main()
{
    int rows = 6;
    int cols = 6;
    int arr[rows][cols] = {
        {1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {0, 0, 2, 4, 4, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 1, 2, 4, 0}};
    int maxSum = -64;
    int sum = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            sum = arr[i + 1][j + 1] + arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }
    }
    // for (int i = 0; i < rows; i += 3)
    // {
    //     for (int j = 0; j < cols; j += 3)
    //     {
    //         int k1 = i + 3;
    //         for (int k = i; k < k1; ++k)
    //         {
    //             int h1 = j + 3;
    //             for (int h = j; h < h1; ++h)
    //             {
    //                 sum += arr[k][h];
    //             }
    //         }
    //         if(sum > maxSum)
    //         {
    //             maxSum = sum;
    //         }
    //         sum = 0;
    //     }

    // }

    std::cout << "Result : " << maxSum << std::endl;

    return 0;
}