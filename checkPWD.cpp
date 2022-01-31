#include <iostream>
#include <string>

bool checkPass(const std::string passWords)
{
    int length = passWords.length();
    int checkUpper = 0;
    int checkLower = 0;
    int checkDigit = 0;
    int specialCharacter = 0;
    for (int i = 0; i < length; i++)
    {
        if (isupper(passWords[i]))
        {
            ++checkUpper;
        }
        else if (islower(passWords[i]))
        {
            ++checkLower;
        }
        else if (isdigit(passWords[i]))
        {
            ++checkDigit;
        }
        else
        {
            ++specialCharacter;
        }
        
    }
    if (checkUpper && checkLower && checkDigit && !specialCharacter)
    {
        return true;
    }
    return false;
}

int main()
{
    const std::string passWords = "Matkhau12345@";
    if (checkPass(passWords))
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }
    
    
    return 0;
}