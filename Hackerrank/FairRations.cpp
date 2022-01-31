//See more at https://www.hackerrank.com/challenges/fair-rations/problem

#include <iostream>
#include <vector>

bool canDistribute(const std::vector<int> loavesEachPerson)
{
    int oddCount = 0;
    int size = loavesEachPerson.size();
    for(auto i = 0; i < size; ++i)
    {
        if(loavesEachPerson[i] % 2 != 0) oddCount++;

    }
    if(oddCount % 2 == 0) return true;
    return false;
}

bool checkOK(const std::vector<int> loavesEachPerson)
{
    int size = loavesEachPerson.size();
    for(auto i = 0; i < size; ++i)
    {
        if(loavesEachPerson[i] % 2 != 0) return false;
    }
    return true;
}

std::string fairRations(std::vector<int>& loavesEachPerson) 
{
    int loaves = 0;
    bool ok = false;
    if(!canDistribute(loavesEachPerson)) return "NO";
    int size = loavesEachPerson.size();
    while(true)
    {
        for(auto i = 0; i < size; ++i)
        {
            if(loavesEachPerson[i] % 2 != 0)
            {
                ++loavesEachPerson[i];
                if(i == size - 1)
                    ++loavesEachPerson[i - 1];
                else ++loavesEachPerson[i + 1];
                loaves += 2;
            }
            if(checkOK(loavesEachPerson)) {ok = true; break;}
            else {
                if(i == size - 1)
                {
                    i = -1;
                }
            }
        }
        if(ok) break;
    }
    return std::to_string(loaves);
}

int main(int argc, char* argv[])
{
    std::vector<int> arr = {2, 3, 4, 5, 6};
    std::string result = fairRations(arr);
    std::cout << result << std::endl;
    return EXIT_SUCCESS;
}