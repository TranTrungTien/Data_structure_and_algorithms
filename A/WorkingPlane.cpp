#include <iostream>
#include <vector>

// find the longest working plane. longest working plane if the start time of current work must be larger than
// the end  time of previous work
// based on kadane's algorithms
// see more at https://en.wikipedia.org/wiki/Maximum_subarray_problem 

struct Plane
{
    unsigned startTime;
    unsigned endTime;
    Plane(unsigned start, unsigned end)
    {
        startTime = start;
        endTime = end;
    }
};

std::vector<Plane> longestWorkingPlane(std::vector<Plane> workingPlane)
{
    std::vector<Plane> result = {};
    unsigned start = 0;
    unsigned end = 0;
    unsigned longestCurrent = 1;
    unsigned longestOverall = 1;
    unsigned tick = 0;
    for (unsigned i = 0; i < workingPlane.size() - 1; ++i)
    {

        if (workingPlane[i].endTime > workingPlane[i + 1].startTime)
        {
            longestCurrent = 1;
            ++tick;
        }
        else if (workingPlane[i].endTime <= workingPlane[i + 1].startTime)
        {
            ++longestCurrent;
        }
        if (longestOverall < longestCurrent)
        {
            start = tick;
            end = i + 1;
            longestOverall = longestCurrent;
        }
    }

    for (unsigned i = start; i <= end; ++i)
    {
        result.push_back(workingPlane[i]);
    }
    return result;
}

int main(int argc, char *argv[])
{
    std::vector<Plane> workingPlane = {
        Plane(1, 3),
        Plane(2, 5),
        Plane(5, 6),
        Plane(6, 8),
        Plane(8, 9),
    };

    auto result = longestWorkingPlane(workingPlane);

    for (auto i : result)
    {
        std::cout << "start time : " << i.startTime << " - end time :" << i.endTime << "\n";
    }
    return EXIT_SUCCESS;
}