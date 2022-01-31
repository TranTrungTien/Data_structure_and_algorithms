#include <iostream>
#include <vector>

std::string compareStr(std::string s1, std::string s2)
{
    std::string res = "";
    int n1 = s1.length();
    int n2 = s2.length();
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        if (s1[i] != s2[j])
        {
            return res;
        }
        else
        {
            res += s1[i];
        }
    }
    return res;
}

int main()
{
    std::string arr[] = {"love", "loves", "loveyou"};
    std::string res = "";
    int n = 3;
    res += compareStr(arr[0], arr[n - 1]);
    for (int i = 1; i < n - 1; i++)
    {
        res += compareStr(res, arr[i]);
    }
    
    return 0;
}