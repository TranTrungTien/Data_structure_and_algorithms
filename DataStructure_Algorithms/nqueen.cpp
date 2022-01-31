#define N 8
#include <stdbool.h> 
#include <stdio.h> 
  

void printSolution(int board[N][N]) 
{
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n"); 
    }
    printf("\n"); 
} 
  

bool isSafe(int board[N][N], int row, int col) 
{ 
    int i, j; 
  

    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 

    for (i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 
  

void solveNQUtil(int board[N][N], int col) 
{ 

    if (col == N) 
        printSolution(board);
  
    for (int i = 0; i < N; i++) { 

        if (isSafe(board, i, col)) { 

            board[i][col] = 1; 
            solveNQUtil(board, col + 1);
            board[i][col] = 0; // BACKTRACK 
        } 
       
    } 

    return; 
} 
  
void solveNQ() 
{ 
    int board[N][N] = { { 0, 0, 0, 0, 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 }
                        }; 
  
solveNQUtil(board, 0);
    
    return; 
} 
  
int main() 
{ 
    solveNQ(); 
    return 0; 
} 