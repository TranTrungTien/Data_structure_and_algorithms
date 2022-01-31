// See more at https://www.hackerrank.com/challenges/acm-icpc-team/problem


#include <iostream>
#include <vector>


std::vector<int> acmTeam(std::vector<std::string> topic)
{
    int maxTopicsTeamKnown = 0;
    int maxTeamCanKnown = 0;

    size_t n = topic.size();

    for (size_t i = 0; i < n - 1; ++i)
    {
        for (size_t j = i + 1; j < n; ++j)
        {
            int maxTopics = 0;
            for (size_t k = 0; k < topic[j].length(); ++k)
            {
                if (topic[i][k] == '1' || topic[j][k] == '1')
                {
                    ++maxTopics;
                }
            }
            if (maxTopicsTeamKnown == maxTopics)
            {
                ++maxTeamCanKnown;
            }
            else if (maxTopicsTeamKnown < maxTopics)
            {
                maxTeamCanKnown = 1;
                maxTopicsTeamKnown = maxTopics;
            }
        }
    }
    std::vector<int> result;
    result.push_back(maxTopicsTeamKnown);
    result.push_back(maxTeamCanKnown);
    return result;
}


int main(int argc, char *argv[])
{
    std::vector<std::string> topics = {"10101", "11100" ,"11010", "00101"};
    std::vector<int> res = acmTeam(topics);
    std::cout << "max topics : " << res[0] << "max team : " << res[1] << std::endl;
    return EXIT_SUCCESS;
}
