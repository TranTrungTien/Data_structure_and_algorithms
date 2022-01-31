#include <iostream>
#define WIDTH 3
char player = 'X';

class tictactoe
{
private:
	char board[WIDTH][WIDTH];

public:
	tictactoe(/* args */);
	~tictactoe();
	void playGame();
	bool checkWin();
	void drawFirstGame();
	void draw();
	bool checkValid(char);
	int input();
	void togglePlayer();
	bool checkOver();
};


int main()
{
	tictactoe *game = new tictactoe();
	game->drawFirstGame();
	std::cout << "You want to play first ? (Y - N)" << std::endl;
	char x;
	std::cin >> x;
	if (x == 'Y' || x == 'y')
	{
		while (true)
		{
			std::cout << "Turns of Player " << player << " : " << std::endl;
			game->playGame();
			game->draw();
			if (game->checkWin())
			{
				std::cout << "Congratulate : " << player << " Win!" << std::endl;
				break;
			}
			if (game->checkOver() && !game->checkWin())
			{
				std::cout << "Two player ties" << std::endl;	
				break;			
			}
			
			game->togglePlayer();
		}
	}
	else
	{
		while (true)
		{
			game->togglePlayer();
			std::cout << "Turns of Player " << player << " : " << std::endl;
			game->playGame();
			game->draw();
			if (game->checkWin())
			{
				std::cout <<  "Congratulate : " << player << " Win!" << std::endl;
				break;
			}
			if (game->checkOver() && !game->checkWin())
			{
				std::cout << "Two player ties" << std::endl;	
				break;			
			}
		}
	}
	system("pause");
	return 0;
}

tictactoe::tictactoe()
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			board[i][j] = ' ';
		}
	}
}

bool tictactoe::checkWin()
	{
		// check rows;
		if ((board[0][0] == player) && (board[0][1] == player) && (board[0][2] == player))
		{
			return true;
		}
		if ((board[1][0] == player) && (board[1][1] == player) && (board[1][2] == player))
		{
			return true;
		}
		if ((board[2][0] == player) && (board[2][1] == player) && (board[2][2] == player))
		{
			return true;
		}
		// check columns
		if ((board[0][0] == player) && (board[1][0] == player) && (board[2][0] == player))
		{
			return true;
		}
		if ((board[0][1] == player) && (board[1][1] == player) && (board[2][1] == player))
		{
			return true;
		}
		if ((board[0][2] == player) && (board[1][2] == player) && (board[2][2] == player))
		{
			return true;
		}
		// check diagonal
		if ((board[0][0] == player) && (board[1][1] == player) && (board[2][2] == player))
		{
			return true;
		}
		if ((board[2][0] == player) && (board[1][1] == player) && (board[0][2] == player))
		{
			return true;
		}
		return false;
	}

	void tictactoe::playGame()
	{
		int x = input();

		if (x == 1)
		{
			if (checkValid(board[0][0]))
			{
				board[0][0] = player;
			}
			else
			{
				std::cout << "You can't put here. please choose another cell" << std::endl;
				playGame();
			}
				
		}
		else if (x == 2)
		{
			if (checkValid(board[0][1]))
			{
				board[0][1] = player;
			}
			else
			{
				std::cout << "You can't put here. please choose another cell" << std::endl;
				playGame();
			}
		}
		else if (x == 3)
		{
			if (checkValid(board[0][2]))
			{
				board[0][2] = player;
			}
			else
			{
				std::cout << "You can't put here. please choose another cell" << std::endl;
				playGame();
			}
		}
		else if (x == 4)
		{
			if (checkValid(board[1][0]))
			{
				board[1][0] = player;
			}
			else
			{
				std::cout << "You can't put here. please choose another cell" << std::endl;
				playGame();
			}
		}
		else if (x == 5)
		{
			if (checkValid(board[1][1]))
			{
				board[1][1] = player;
			}
			else
			{
				std::cout << "You can't put here. please choose another cell" << std::endl;
				playGame();
			}
		}
		else if (x == 6)
		{
			if (checkValid(board[1][2]))
			{
				board[1][2] = player;
			}
			else
			{
				std::cout << "You can't put here. please choose another cell" << std::endl;
				playGame();
			}
		}
		else if (x == 7)
		{
			if (checkValid(board[2][0]))
			{
				board[2][0] = player;
			}
			else
			{
				std::cout << "You can't put here. please choose another cell" << std::endl;
				playGame();
			}
		}
		else if (x == 8)
		{
			if (checkValid(board[2][1]))
			{
				board[2][1] = player;
			}
			else
			{
				std::cout << "You can't put here. please choose another cell" << std::endl;
				playGame();
			}
		}
		else
		{
			if (checkValid(board[2][2]))
			{
				board[2][2] = player;
			}
			else
			{
				std::cout << "You can't put here. please choose another cell" << std::endl;
				playGame();
			}
		}
	}
	void tictactoe::drawFirstGame()
	{
		std::cout << "Tic Tac Toe v.1" << std::endl;
		std::cout << "---------------" << std::endl;
		int temp = 1;
		for (int i = 0; i < WIDTH; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				std::cout << " | " << temp;
				++temp;
			}
			std::cout << " | " << std::endl;
			std::cout << "---------------" << std::endl;
		}
		std::cout << std::endl;
	}
	void tictactoe::draw()
	{
		system("cls");
		std::cout << "Tic Tac Toe v.1" << std::endl;
		std::cout << "---------------" << std::endl;
		for (int i = 0; i < WIDTH; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				std::cout << " | " << board[i][j];
			}
			std::cout << " | " << std::endl;
			std::cout << "---------------" << std::endl;
		}
		std::cout << std::endl;
	}
	bool tictactoe::checkValid(char x)
	{
		if (x == 'X' || x == 'O')
		{
			return false;
		}
		return true;
	}

	int tictactoe::input()
	{
		int x;
		do
		{
			std::cout << "Press the number you want to play (must be from 1 -> 9): ";
			std::cin >> x;
		} while (x < 1 || x > 9);
		return x;
	}

	void tictactoe::togglePlayer()
	{

		if (player == 'X')
		{
			player = 'O';
		}
		else
			player = 'X';
	}
	bool tictactoe::checkOver()
	{
		for (int i = 0; i < WIDTH; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				if (board[i][j] == ' ')
				{
					return false;
				}
				
			}
			
		}
		return true;
	}