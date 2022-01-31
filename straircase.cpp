#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void sort(std::vector<int> &arr)
{
    int i, key, j;
    int n = arr.size();
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int invese(std::vector<int> arr, int x)
{
    for(int i = 0; i < arr.size(); ++i)
    {
        if(x == arr[i])
        {
            return i + 1;
        }
    }
}

vector<int> permutationEquation(vector<int> p)
{
    //4 3 5 1 2

    // x == 1 == p[3] + 1
    //x == 4 == p[0]
    //p[p[0]] == 1

    std::vector<int> ans;
    int x = 1;
    int position;
    for (int i = 0; i < p.size(); i++)
    {
        if (x == p[i])
        {
            position = i + 1;
            ans.push_back(invese(p, position));
            ++x;
            i = -1;
        }
    }

    return ans;
}

int main()
{
    
    std::vector<int> arr;
    //std::vector<int> queries;
    std::ifstream ifs1;
    ifs1.open("D:\\data\\data.txt", std::ios::in);
    int x;
    while (ifs1 >> x)
    {
        arr.push_back(x);
    }
    ifs1.close();

    /*
    std::ifstream ifs2;
    ifs2.open("D:\\data\\data2.txt", std::ios::in);
    int y;
    while (ifs2 >> y)
    {
        queries.push_back(y);
    }
    ifs2.close();
*/
    std::vector<int> ans = permutationEquation(arr);

    for (int i = 0; i < (signed)ans.size(); ++i)
    {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
