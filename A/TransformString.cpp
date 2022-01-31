#include <iostream>
#include <string>

// example : cat => cut => 1;
unsigned stepNeedToTransform(std::string source, std::string target)
{
    unsigned res = 0;
    for(unsigned i = 0, j = 0; i < source.length() && j < target.length(); ++i, ++j)
    {
        if(source[i] != target[j]) ++res;
    }
    res += abs(source.length() - target.length());
    return res;
}

int main(int argc, char* argv[])
{
    std::string source = "catzzzzz";
    std::string target = "cut";

    std::cout << "Number of step to transform from \"" << source << "\" into \"" << target << "\" : " << stepNeedToTransform(source, target) << std::endl;
    return EXIT_SUCCESS;
}