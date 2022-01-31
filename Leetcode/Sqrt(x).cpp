// See more at https://leetcode.com/problems/sqrtx
#include <iostream>
#include <cmath>

int mySqrt(int x)
{
    if (x == 2 || x == 1)
        return 1;
    for (size_t i = 1; i <= std::ceil((float)x / 2); ++i)
    {
        if (i * i == x)
            return i;
        else if (i * i > x)
            return i - 1;
    }
    return 0;
}
int main(int argc, char* argv[])
{
    mySqrt(2);
    return EXIT_SUCCESS;
}