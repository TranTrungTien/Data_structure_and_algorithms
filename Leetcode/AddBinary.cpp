//See more at https://leetcode.com/problems/add-binary

#include <iostream>
#include <vector>
#include <algorithm>

std::string addBinary(std::string a, std::string b)
{
    std::string res = "";
    size_t size1 = a.length() - 1;
    size_t size2 = b.length() - 1;
    int i = size1;
    int j = size2;
    int remainder = 0;
    while (i >= 0 && j >= 0)
    {
        if (a[i] == '1' && b[j] == '1')
        {
            if (remainder)
            {
                res += '1';
            }
            else
            {
                res += '0';
                remainder = 1;
            }
        }
        else if (a[i] == '1' || b[j] == '1')
        {
            if (remainder)
            {
                res += '0';
            }
            else
            {
                res += '1';
            }
        }
        else
        {
            if (remainder)
            {
                res += '1';
                remainder = 0;
            }
            else
            {
                res += '0';
            }
        }
        --i;
        --j;
    }

    while (i >= 0)
    {
        if (remainder)
        {
            if (a[i] == '1')
            {
                res += '0';
            }
            else
            {
                res += '1';
                remainder = 0;
            }
        }
        else
        {
            if (a[i] == '1')
            {
                res += '1';
            }
            else
            {
                res += '0';
            }
        }
        --i;
    }

    while (j >= 0)
    {
        if (remainder)
        {
            if (b[j] == '1')
            {
                res += '0';
            }
            else
            {
                res += '1';
                remainder = 0;
            }
        }
        else
        {
            if (b[j] == '1')
            {
                res += '1';
            }
            else
            {
                res += '0';
            }
        }
        --j;
    }

    if (i <= -1 && j <= -1)
    {
        if (remainder)
            res += '1';
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main(int argc, char *argv[])
{
    std::string str1 = "1011";
    std::string str2 = "1010"; // 10101
    std::cout << addBinary(str1, str2) << std::endl;
    return EXIT_SUCCESS;
}