#include <iostream>
#include <string>

void show(const std::string res)
{
    std::cout << "longest character is the same : " << res << std::endl;
    std::cout << "length : " << res.length() << std::endl;
}

std::string sameCharacters(std::string str1, std::string str2)
{
    std::string result = "";

    unsigned startCheck = 0;
    for(auto i = 0; i < str1.length(); ++i)
    {
        for(auto j = startCheck; j < str2.length(); ++j)
        {
            if(str1[i] == str2[j])
            {
                result += str1[i];
                startCheck = j + 1;
                break;
            }
        }
        
    }
    return result;
}


int main(int argc, char* argv[])
{
    std::string str1 = "fxzet";
    std::string str2 = "sfzfffft";
    std::string result = sameCharacters(str1, str2);
    show(result);
    return EXIT_SUCCESS;
}