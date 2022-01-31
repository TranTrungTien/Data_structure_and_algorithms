#include <iostream>
#include <vector>


unsigned getIndexOfPair(int index, std::vector<int> arr)
{
    int max = arr.size();
    for(int i = max - 1; i > index ; --i)
    {
        if(arr[index] == arr[i])
            return i; 
    }
    return 0;
}


int minimumDistances(std::vector<int> arr) {
    int minimumDistance = INT32_MAX;
    int max  = arr.size();
    for(int i = 0; i < max; ++i)
    {
        int index = getIndexOfPair(i, arr);
        if(index)
        {
            int res = std::abs(i - index);
            minimumDistance = std::min(minimumDistance, res);
        }
    }
    
    return minimumDistance == INT32_MAX ? -1 : minimumDistance;
}

int main(int argc, char* argv[])
{
    std::vector<int> arr = {7, 1, 2, 2, 1 , 7};
    auto res = minimumDistances(arr);
    return EXIT_SUCCESS;
}