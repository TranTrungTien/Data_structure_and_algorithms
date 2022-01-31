#include <iostream>

void merge(int* array, int l, int r, int m)
{
    int n1 = m - l + 1;
    int n2 = r - m ;

    int subArray1[n1];
    int subArray2[n2];
    for (int i = 0; i < n1; i++)
    {
        subArray1[i] = array[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        subArray2[i] = array[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2)
    {
        if (subArray1[i] <= subArray2[j])
        {
            array[k] = subArray1[i];
            ++i;
        }
        else
        {
            array[k] = subArray2[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        array[k] = subArray1[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        array[k] = subArray2[j];
        ++j;
        ++k;
    }
    
}


void mergeSort(int* array, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, r, m);
    }
    
}

void display(const int* array, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}

int main()
{
    int n = 6;
    int array[n] = {2, 6, 4, 1, 3, 5};
    mergeSort(array, 0, n - 1);
    display(array, n);

    return 0;
}