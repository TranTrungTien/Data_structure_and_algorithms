//
#include <fstream>
#include <iostream>
#include <ctime>
#include <vector>
 
void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
 
int partition(std::vector<int>& array, int low, int high)
{
    int pivot  = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            ++i;
            Swap(array[i], array[j]);
        }
        
    }
    Swap(array[i + 1], array[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& array, int low, int high)
{
    if (low < high)
    {
        int pos = partition(array, low, high);
        quickSort(array, low, pos - 1);
        quickSort(array, pos + 1, high);
    }
    
}



void Show(std::vector<int> array, int size)
{
    for (int i = 0; i < size; ++i)
      std::cout << array[i] << " ";
}
 
int main()
{
    // read data

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

    //int arr[] = {4 , 5, 7, 10 , 2, 9, 8 , 34, 52, 6, 23, 5, 33 , 57, 23,34,76,4, 45,66};
    //int n = sizeof(arr)/sizeof(arr[0]);

    
    int n = arr.size();
    clock_t start = clock();
    quickSort(arr, 0, n - 1);   
    std::cout << "Sorted List: ";
    Show(arr, n);
    clock_t end = clock();
    long time = end - start;
    std::cout << "\nTime : " << time << "ms"<< std::endl;
    return 0;
}
 