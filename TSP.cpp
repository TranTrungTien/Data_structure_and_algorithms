#include <iostream>
#include <vector>
#define CITY 4

void tsp(int cityMap[][CITY], int index, int &cost,  int priceWay, std::vector<int>& bestWay, std::vector<bool>& free)
{
    if (index == CITY && (priceWay + (cityMap[index - 1][0])) < cost)
    {
        cost = (priceWay += cityMap[index - 1][0]);
    }
    for (int i = 1; i < CITY; i++)
    {
        if (free[i] && (cityMap[index - 1][i] != 0))
        {
            bestWay.push_back(i);
            priceWay += cityMap[index - 1][i];
            if (priceWay < cost)
            {
                free[i] = false;
                tsp(cityMap, index + 1, cost, priceWay, bestWay, free);
                free[i] = true;
                bestWay.pop_back();
            }else
            {
                bestWay.pop_back();
                priceWay -= cityMap[index - 1][i];
            }
            
        }
    }
}

int main()
{
    int cityMap[][CITY] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};
    std::vector<bool> freeCity(CITY);
    for (int i = 0; i < CITY; i++)
    {
        freeCity[i] = true;
    }
    freeCity[0] = false;
    std::vector<int> bestWay;
    bestWay.push_back(0);
    int cost = INT_MAX;
    tsp(cityMap, 1, cost, 0, bestWay, freeCity);
    bestWay.push_back(0);
    std::cout << "The best way is : " << std::endl;
    for (int i = 0; i < CITY + 1; i++)
    {
        std::cout << bestWay[i] << " ";
    }
    std::cout << std::endl
              << "The cost is : " << cost << std::endl;
    return 0;
}