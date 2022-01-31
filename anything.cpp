#include <iostream>
#include <vector>

int findDigits(int n) {
    int countDivisor = 0;
    int tmpN = n;
    while(tmpN > 0)
    {
        int divisor = tmpN % 10;
        if(n % divisor == 0 && divisor != 0)
            ++countDivisor;
        tmpN /= 10; 
    }
    return countDivisor;
}


int main()
{
    std::vector<int> arr = {1, 1, 1, 0, 1, 1, 0, 0, 0, 0};
    std::cout << findDigits(1012);
    //     std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    //     int d = 2;
    //     int n = arr.size();
    // //std::vector<int> array;

    //     arrayRotation(arr, d, n);
    // std::vector<std::vector<int>> arr = {
    //     {-1, -1, 0, -9, -2, -2},
    //     {-2, -1, -6, -8, -2, -5},
    //     {-1, -1, -1, -2, -3, -4},
    //     {-1, -9, -2, -4, -4, -5},
    //     {-7, -3, -3, -2, -9, -9},
    //     {-1, -3, -1, -2, -4, -5}};
    return 0;
}