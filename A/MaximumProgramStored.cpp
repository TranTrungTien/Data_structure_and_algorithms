
#include <iostream>
#include <vector>
#include <algorithm>

bool writeProgramToDrive(std::vector<unsigned>& programs, unsigned& drive)
{
    auto size = programs.size();
    unsigned i = 0;
    for(; i < size; ++i)
    {
        if(programs[i] <= drive)
        {
            drive -= programs[i];
        }
        else break;
    }
    programs.erase(programs.begin(), programs.begin() + i);
    return true;
}

int main(int argc, char* argv[])
{
    std::vector<unsigned> programs = {3, 4, 1, 6, 5, 7, 2};
    unsigned L = 10;
    unsigned drive1 = L;
    unsigned drive2 = L;

    std::sort(programs.begin(), programs.end());

    if( writeProgramToDrive(programs, drive1))
    {
        std::cout <<"program after stored in drive1 :" << std::endl;
        for(const auto& i : programs)
        {
            std::cout << i << "   ";
        }
        std::cout << std::endl << "Drive 1: " << drive1 << std::endl;
    }
    if(writeProgramToDrive(programs, drive2))
    {
        std::cout <<"program after stored in drive2 :" << std::endl;
        for(const auto& i : programs)
        {
            std::cout <<  i << "   ";
        }
        std::cout << std::endl << "Drive 2 :" << drive2 << std::endl;
    }

    return EXIT_SUCCESS;
}