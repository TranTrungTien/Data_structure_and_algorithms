#include <iostream>
#include <vector>

int minimumTheNumberOfCurrencyNotes(std::vector<unsigned> money, unsigned moneyNeedToWithdraw)
{
    unsigned amountOfCurrency = 0;
    unsigned i = money.size() - 1;
    while(moneyNeedToWithdraw >= money[0])
    {
        if(moneyNeedToWithdraw < money[i])
            --i;
        else
        {
            moneyNeedToWithdraw -= money[i];
            ++amountOfCurrency;
        }
    }
    return amountOfCurrency;
}

int main(int argc, char* argv[])
{
    std::vector<unsigned> money = {1, 2, 5, 10, 50, 100, 200, 500};
    std::cout << minimumTheNumberOfCurrencyNotes(money, 1000);
    return EXIT_SUCCESS;
}