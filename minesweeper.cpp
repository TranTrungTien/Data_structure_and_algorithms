#include <iostream>
#include <cstdlib>
#include <ctime>
#define WIDTH 9
#define HEIGHT 9
#define TOTAL_MINES 10

bool ENDGAME = false;

void usage()
{
	std::cout << "USAGE: \n ============How To Play Minesweeper v.1 !!! ============= \n";
	std::cout << "You have a board 9x9 with 10 mines. Each of turn, you can choose a cell.\n";
	std::cout << "If there is no mine, this cell will open, if there are mines around this cell. \n";
	std::cout << "it's stop. if not, continue to open adjacent cells.\n";
	std::cout << "========== Now --- How to play ========= \n You can press a number to choose latitude and longitude. \n Example : if you want to choose third cell you must press: \n Longitude : 0 Latitude : 2 \n And Good Luck \n";
}

void displayBoard(int board[][WIDTH])
{
	std::cout << "            Minesweeper v.1 \n";
	for (int i = 0; i < WIDTH; ++i)
	{
		std::cout << "   " << i;
	}
	std::cout << std::endl;
	std::cout << "  -------------------------------------" << std::endl;
	for (int i = 0; i < HEIGHT; ++i)
	{
		std::cout << i;
		for (int j = 0; j < WIDTH; ++j)
		{
			if (board[i][j] == 32 || board[i][j] == 77)
			{
				std::cout << " | " << (char)board[i][j];
			}
			else
			{
				std::cout << " | " << board[i][j];
			}
		}
		std::cout << " |" << std::endl;
		std::cout << "  -------------------------------------" << std::endl;
	}
	return;
}

bool isCorrectPos(int x, int y)
{
	if (x < 0 || x > WIDTH - 1 || x > HEIGHT - 1 || y < 0 || y > WIDTH - 1 || y > HEIGHT - 1)
	{
		return false;
	}
	return true;
}

bool isMine(char x)
{
	if (x != 'M')
	{
		return false;
	}
	return true;
}

void minesSweeper(int playBoard[][WIDTH], int minesBoard[][WIDTH], int x, int y)
{
	int countMines = 0;
	int x1, y1;

	//=================================
	//check for mines around cell
	//above of cell

	for (x1 = x - 1, y1 = y - 1; y1 < (y + 2); ++y1)
	{
		if (isCorrectPos(x1, y1))
		{
			if (isMine(minesBoard[x1][y1]))
			{
				++countMines;
			}
		}
	}

	//under of cell

	for (x1 = x + 1, y1 = y - 1; y1 < (y + 2); ++y1)
	{
		if (isCorrectPos(x1, y1))
		{
			if (isMine(minesBoard[x1][y1]))
			{
				++countMines;
			}
		}
	}

	//check left cell

	if (isCorrectPos(x, y - 1))
	{
		if (isMine(minesBoard[x][y - 1]))
		{
			++countMines;
		}
	}

	// check right cell

	if (isCorrectPos(x, y + 1))
	{
		if (isMine(minesBoard[x][y + 1]))
		{
			++countMines;
		}
	}

	///================================================
	// If there are no mines around, backtracking to check the other cell
	// if so, stop.

	if (countMines == 0)
	{
		//check top of the cell

		for (x1 = x - 1, y1 = y - 1; y1 < (y + 2); ++y1)
		{
			if (isCorrectPos(x1, y1))
			{
				if (playBoard[x1][y1] == 32)
				{
					playBoard[x1][y1] = 0;
					minesSweeper(playBoard, minesBoard, x1, y1);
				}
			}
		}

		//check below the cell

		for (x1 = x + 1, y1 = y - 1; y1 < (y + 2); ++y1)
		{
			if (isCorrectPos(x1, y1))
			{
				if (playBoard[x1][y1] == 32)
				{
					playBoard[x1][y1] = 0;
					minesSweeper(playBoard, minesBoard, x1, y1);
				}
			}
		}

		//check left cell

		if (isCorrectPos(x, y - 1))
		{
			if (playBoard[x][y - 1] == 32)
			{
				playBoard[x][y - 1] = 0;
				minesSweeper(playBoard, minesBoard, x, y - 1);
			}
		}

		// check right cell

		if (isCorrectPos(x, y + 1))
		{
			if (playBoard[x][y + 1] == 32)
			{
				playBoard[x][y + 1] = 0;
				minesSweeper(playBoard, minesBoard, x, y + 1);
			}
		}
	}
	playBoard[x][y] = countMines;
}

//=========================================================================
bool Win(int pBoard[][WIDTH], int mBoard[][WIDTH])
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			if (pBoard[i][j] == 32 && mBoard[i][j] != 77)
			{
				return false;
			}
		}
	}
	return true;
}

void playGame(int playBoard[][WIDTH], int minesBoard[][WIDTH])
{
	int x, y;
	std::cout << "Choose the cell you want to play: " << std::endl;
	std::cout << "Longitude X: ";
	std::cin >> x;
	std::cout << "\nLatitude Y: ";
	std::cin >> y;
	if (isMine(minesBoard[x][y]))
	{
		system("cls");
		std::cout << "You just chose Longitude : " << x << " Latitude : " << y << "\nYou lost!!!!" << std::endl;
		displayBoard(minesBoard);
		ENDGAME = true;
		return;
	}
	else
	{
		playBoard[x][y] = 0;
		minesSweeper(playBoard, minesBoard, x, y);
		system("cls");
		displayBoard(playBoard);
		if (Win(playBoard, minesBoard))
		{
			std::cout << "Congratulation !!!!! You won !!!!!!!" << std::endl;
			ENDGAME = true;
			return;
		}
	}
	return;
}

void initialBoard(int playBoard[][WIDTH], int minesBoard[][WIDTH])
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			playBoard[i][j] = 32;
			minesBoard[i][j] = 32;
		}
	}
	return;
}

void placeMines(int board[][WIDTH])
{
	srand((unsigned)time(0));
	int x, x1;
	int y, y1, countMines = 0;
	int totalMines = 0;
	do
	{
		do
		{
			x = rand() % WIDTH;
			y = rand() % HEIGHT;
		} while (board[x][y] != 32);

		for (x1 = x - 1, y1 = y - 1; y1 < (y + 2); ++y1)
		{
			if (isCorrectPos(x1, y1))
			{
				if (isMine(board[x1][y1]))
				{
					++countMines;
				}
			}
		}

		//under of cell

		for (x1 = x + 1, y1 = y - 1; y1 < (y + 2); ++y1)
		{
			if (isCorrectPos(x1, y1))
			{
				if (isMine(board[x1][y1]))
				{
					++countMines;
				}
			}
		}

		//check left cell

		if (isCorrectPos(x, y - 1))
		{
			if (isMine(board[x][y - 1]))
			{
				++countMines;
			}
		}

		// check right cell

		if (isCorrectPos(x, y + 1))
		{
			if (isMine(board[x][y + 1]))
			{
				++countMines;
			}
		}
		if (countMines < 4)
		{
			board[x][y] = 'M';
			++totalMines;
		}
		countMines = 0;
	} while (totalMines < 10);
	return;
}

int main()
{
	int playBoard[HEIGHT][WIDTH];
	int minesBoard[HEIGHT][WIDTH];
	initialBoard(playBoard, minesBoard);
	placeMines(minesBoard);
	usage();
	displayBoard(playBoard);
	char start;
	std::cout << "Start now ---> (Y/N) : " << std::endl;
	std::cin >> start;
	if (start == 'y' || start == 'Y')
	{
		while (!ENDGAME)
		{
			playGame(playBoard, minesBoard);
		}
	}
	else
	{
		exit(0);
	}
	
	system("pause");
	return 0;
}