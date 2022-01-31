#include <vector>
#include <iostream>

int diagonalDifference(std::vector<std::vector<int>> arr) {
    int i = 0;
    int j = 0;
    int sumLTR = 0;
    int n = arr.size();
    while(i < n && j < n)
    {
        sumLTR += arr[i][j];
        ++i;
        ++j;
    }
    i = n - 1;
    j = 0;
    int sumRTL = 0;
    while(i >= 0 && j < n)
    {
        sumRTL += arr[i][j];
        --i;
        ++j;
    }
    int res = abs(sumLTR - sumRTL);
    return res;
}


int main()
{
    std::vector<std::vector<int>> arr = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int res = diagonalDifference(arr);
    std::cout << "Result" << res << std::endl;
    return 0;
}