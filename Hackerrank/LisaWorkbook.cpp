//See more at https://www.hackerrank.com/challenges/lisa-workbook/problem

#include <iostream>
#include <vector>


int workbook(int chapters, int k, std::vector<int> problems)
{
    int specialProblems = 0;
    
    int currentPage = 1;

    for(int i = 0; i < chapters; ++i)
    {
        int problemsInPage = problems[i];
        int startProblem = 1;
        while(startProblem <= problemsInPage)
        {
            int endProblem = startProblem + k;
            if(endProblem > problemsInPage)
            {
                endProblem = problemsInPage + 1;
            }

            if(currentPage >= startProblem && currentPage < endProblem)
            {
                ++specialProblems;
            }
            startProblem += k;
            ++currentPage;
        }
    }
    return specialProblems;
}

int main(int argc, char* argv[])
{
    std::vector<int> arr = {4, 2};
    int res = workbook(2, 3, arr);
    std::cout << res << "\n";
    return EXIT_SUCCESS;
}