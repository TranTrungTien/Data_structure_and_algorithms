#include <iostream>
#include <vector>

void swap(int &a, int &a1, int& p, int& p1)
{
    int tmp = a; a = a1; a1 = tmp;
    int tmp1 = p; p = p1; p1 = tmp1;
}

void sort(std::vector<int>& a, std::vector<int> &p)
{
    for(int i = 0; i < (signed)a.size() - 1; ++i)
    {
        for(int j = i + 1; j < (signed)p.size(); ++j)
        {
            
            if(((float)p[i] / a[i]) < ((float)p[j] / a[j]))
            {
                swap(a[i], a[j], p[i], p[j]);
            }
        }
    }
}

std::vector<int> greedy(std::vector<int>& a , std::vector<int>& p, int b)
{
    sort(a, p);
    std::vector<int> ans;
    int i = 0;
    while (b > a[(signed)a.size() - 1])
    {
        int tmp = b / a[i];
        if(tmp > 0)
        {
            ans.push_back(tmp);
            b -= tmp * a[i];
        }
        ++i;
    }
    return ans;
}
