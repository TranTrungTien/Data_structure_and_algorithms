// See more at https://leetcode.com/problems/plus-one/

#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int> &digits)
{
    size_t max = digits.size() - 1;
    int digit = digits[max] + 1;
    if (digit < 10)
    {
        ++digits[max];
        return digits;
    }
    else
    {
        //999 -> 1000 979 -> 980 799 ->800 896 -> 897
        for (size_t i = max; i >= 0; --i)
        {
            if (digits[i] + 1 == 10)
            {
                if (i == 0)
                {
                    digits[0] = 1;
                    digits.push_back(0);
                    return digits;
                }
                digits[i] = 0;
            }
            else
            {
                ++digits[i];
                return digits;
            }
        }
    }
    return digits;
}

int main(int argc, char * argv[])
{
    std::vector<int> digits = { 9 , 9 ,9 ,9 };
    plusOne(digits);
    return EXIT_SUCCESS;
}