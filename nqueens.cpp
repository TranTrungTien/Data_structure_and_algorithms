#include <iostream>
#define N 8

bool check(int board[], int col, int row)
{
    for (int i = 0; i < col; i++)
    {
        if (board[i] == row || abs(i - col) == abs(board[row] - col))
        {
            return false;
        }
        
    }
    return true;
}

void display(int board[])
{
    for (int i = 0; i < N; i++)
    {
        std::cout << board[i];
    }
    std::cout << std::endl;
    
}

void backtracking(int i, int board[])
{
    if (i >= N)
    {
        display(board);
    }
    else
    {
        for (int j = 0; j < N; ++j)
        {
            if (check(board, i, j))
            {
                board[j] = j;
                backtracking(i + 1, board);
            }
            
        }
        
    }
    
}



int main()
{
    int board[N] = {0};
    backtracking(0, board);
    return 0;
}