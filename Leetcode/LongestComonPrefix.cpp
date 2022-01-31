
#include <iostream>
#include <vector>
#include <algorithm>
std::string longestCommonPrefix(std::vector<std::string> &strs)
{
    std::string res = "";
    size_t n = strs.size();
    size_t i = 0;
    while (true)
    {
        size_t j = 0;
        for (; j < n - 1; ++j)
        {
            if (strs[j][i] != strs[j + 1][i])
            {
                return res;
            }
        }
        std::cout << strs[j].length();
        if (i == strs[j].length())
            return res;
        res += strs[j][i];
        ++i;
    }
    return res;
}
int main(int argc, char *argv[])
{
    std::vector<std::string> strs = {""};
    longestCommonPrefix(strs);
    return EXIT_SUCCESS;
}