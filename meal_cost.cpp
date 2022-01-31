#include <iostream>
#include <vector>
#include <string>

int formingMagicSquare(std::vector<std::vector<int>> magicSquare)
{
	std::vector<std::vector<int>> allMagicSquare = {
		{4, 9, 2, 3, 5, 7, 8, 1, 6},
		{4, 3, 8, 9, 5, 1, 2, 7, 6},
		{2, 9, 4, 7, 5, 3, 6, 1, 8},
		{2, 7, 6, 9, 5, 1, 4, 3, 8},
		{8, 1, 6, 3, 5, 7, 4, 9, 2},
		{8, 3, 4, 1, 5, 9, 6, 7, 2},
		{6, 7, 2, 1, 5, 9, 8, 3, 4},
		{6, 1, 8, 7, 5, 3, 2, 9, 4},
	};
	int ans = 0;
	int n = magicSquare.size();
	const int magicConstant = ((n * n + 1) / 2) * n;

	return ans;
}

int main()
{
	std::vector<int> keyboards = {40, 50, 10};
	std::vector<int> drives = {20, 10, 30, 5};

	std::vector<std::vector<int>> magicSquare = {{5, 3, 4}, {1, 5, 8}, {6, 4, 2}};
	std::cout << formingMagicSquare(magicSquare) << std::endl;
	return 0;
}