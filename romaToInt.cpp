#include <iostream>

int main()
{
    std::string s = "MCMXCIX";
    int n = s.length();
    int res = 0;
    int i = 0;
    while (i < n)
    {
        if (s[i] == 'I')
        {
            if (s[i + 1] == 'V')
            {
                res += 4;
                i += 2;
            }
            else if (s[i + 1] == 'X')
            {
                res += 9;
                i += 2;
            }
            else
            {
                res += 1;
                i += 1;
            }
        }
        else if (s[i] == 'V')
        {
            res += 5;
            i += 1;
        }
        else if (s[i] == 'X')
        {
            if (s[i + 1] == 'L')
            {
                res += 40;
                i += 2;
            }
            else if (s[i + 1] == 'C')
            {
                res += 90;
                i += 2;
            }
            else
            {
                res += 10;
                i += 1;
            }
        }
        else if (s[i] == 'L')
        {
            res += 50;
            i += 1;
        }
        else if (s[i] == 'C')
        {
            if (s[i + 1] == 'D')
            {
                res += 400;
                i += 2;
            }
            else if (s[i + 1] == 'M')
            {
                res += 900;
                i += 2;
            }
            else
            {
                res += 100;
                i += 1;
            }
        }
        else if (s[i] == 'D')
        {
            res += 500;
            i += 1;
        }
        else
        {
            res += 1000;
            i += 1;
        }
    }
    std::cout << res << std::endl;

    return 0;
}