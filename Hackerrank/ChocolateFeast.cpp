// See more at https://www.hackerrank.com/challenges/chocolate-feast/problem

#include <iostream>

int chocolateFeast(int money, int cost, int wrappers) {
    int totalFreeChocolates = 0;
    int chocolates = money / cost;
    totalFreeChocolates = chocolates;
    int ticket = chocolates;
    while(ticket >= wrappers)
    {
        int freeChocolates = ticket / wrappers;
        ticket = ticket - (freeChocolates * wrappers) + freeChocolates;
        totalFreeChocolates += freeChocolates;
    }
    return totalFreeChocolates;
}


int main(int argc, char* argv[])
{
    int res = chocolateFeast(15, 3, 2);
    std::cout << res;
    return EXIT_SUCCESS;
}