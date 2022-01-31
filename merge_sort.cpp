#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

//tron


int main()
{   

    	srand(time(0));
	std::ofstream ofs;
	ofs.open("D:\\data\\data.txt", std::ios::out);
	int i = 0;
	while (i < 10000)
	{
		int x = (std::rand() % 1000) + 1;
		ofs << x << " ";
		++i;
	}

	ofs.close();

	std::vector<int> arr;

	std::ifstream ifs;
	ifs.open("D:\\data\\data.txt", std::ios::in);
	int x;
	while (ifs >> x)
	{
		arr.push_back(x);
	}
	ifs.close();


    int n = 10000;


    
    mergeSort(arr, 0 , n - 1);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}