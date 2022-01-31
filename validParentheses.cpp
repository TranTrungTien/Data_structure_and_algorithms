#include <iostream>
#include <stack>

int main()
{
    int n = 8;
    const char* parenthese = new char[n] {'{', '[', '{', '}', ']', '(', ')','}'};
    std::stack<char> parentheses;
    for (int i = 0; i < n; i++)
    {
        if (parenthese[i] == '{' || parenthese[i] == '(' || parenthese[i] == '[')
        {
            parentheses.push(parenthese[i]);
        }
        else
        {
            if(parentheses.empty())
            {                                                                                                                
                std::cout << "Invalid Parentheses \n";
                return 0;
            }
            else
            {
                char openingBracket = parentheses.top();
                if((openingBracket == '{' && parenthese[i] == '}') || (openingBracket == '(' && parenthese[i] == ')') || (openingBracket == '[' && parenthese[i] == ']'))
                {
                    parentheses.pop();
                }
                else
                {
                    std::cout <<"Invalid Parentheses \n";
                    return 0;
                }
                
            }
        }
    }
    if (parentheses.empty())
    {
        std::cout << "Valid Parentheses \n";
    }
    else
    {
        std::cout << "Invalid Parentheses \n";
    }
    return 0;
}