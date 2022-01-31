#include <iostream>
#include <vector>

std::vector<unsigned> bloomingDay(std::vector<unsigned>& seeds)
{
    for(unsigned i = 0 ; i < seeds.size(); ++i)
    {
        seeds[i] += i;
    }
    return seeds;
}

unsigned allFlowerBloomAfter(std::vector<unsigned> seeds)
{
    std::vector<unsigned> bloomingDays = bloomingDay(seeds);
    unsigned res = 0;
    for(auto i : bloomingDays)
    {
        if(res < i)
        {
            res = i;
        }
    }
    return res;
}

int main(int argc, char* argv[])
{

    std::vector<unsigned> seeds = {4, 2, 10, 4, 5, 7, 1};
    auto res = allFlowerBloomAfter(seeds);
    std::cout << res << std::endl;
    return EXIT_SUCCESS;
}