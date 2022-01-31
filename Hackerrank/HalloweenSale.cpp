// See more at https://www.hackerrank.com/challenges/halloween-sale/problem


#include <iostream>
#include <vector>


int howManyGames(const int firstGamePrice, const int discount, const int minimumMoney, int budget)
{
    // Return the number of games you can buy
    int maxGame = 0;
    int nextGamePrice = firstGamePrice;

    while (budget >= minimumMoney && budget >= nextGamePrice)
    {
        ++maxGame;
        if (nextGamePrice - discount < minimumMoney)
        {
            if (budget > minimumMoney)
            {
                budget -= nextGamePrice;
                nextGamePrice = minimumMoney;
            }
            else
            {
                budget -= minimumMoney;
                nextGamePrice = minimumMoney;
            }
        }
        else
        {
            budget -= nextGamePrice;
            nextGamePrice -= discount;
        }
    }
    return maxGame;
}

int main(int argc, char *argv[])
{
    howManyGames(100, 19, 1, 180);
    return EXIT_SUCCESS;
}