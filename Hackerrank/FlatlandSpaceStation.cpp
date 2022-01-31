// See more at https://www.hackerrank.com/challenges/flatland-space-stations/problem


#include <iostream>
#include <vector>

int calculateDistance(int city, std::vector<int> c)
{
    int distance = INT32_MAX;
    for(int i  =0 ; i < c.size(); ++i)
    {
        if(std::abs(c[i] - city) < distance)
        {
            distance = std::abs(c[i] - city);
        }
    }
    return distance;
}

int flatlandSpaceStations(int n, std::vector<int> c) {
    int maxDistance = 0;
    int i = 0;
    for(int city = 0; city < n; ++city)
    {
        if(c[i] != city)
        {
            int distance = calculateDistance(city, c);
            if(distance > maxDistance)
            {
                maxDistance = distance;
            }
        }
        else ++i;
    }
    
    return maxDistance;
}

int main(int argc, char* argv[])
{
    std::vector<int> c= {0,4};
    flatlandSpaceStations(5, c);
    return EXIT_SUCCESS;
}