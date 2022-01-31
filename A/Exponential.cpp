#include <iostream>
#include <vector>

unsigned long pow(int value,int exponent)
{
    if(exponent == 0) return 1;
    return (exponent % 2) == 0 ? (pow(value, exponent / 2) * pow(value, exponent / 2)) : value * (pow(value, exponent / 2) * pow(value, exponent / 2));
}


int power(int x, unsigned int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

int main(int argc, char* argv[])
{
    unsigned result = pow(4, 4);
    std::cout << result << std::endl;
    return EXIT_SUCCESS;
}