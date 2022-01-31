
#include <iostream>
#include <vector>

// reference : Giai thuat va lap trinh - Le minh hoang....

void show(const std::vector<unsigned> &arr)
{
    size_t max = arr.size();
    for (size_t i = 0; i < max; ++i)
    {
        std::cout << arr[i] << " ";
    }
}

void permutation(std::vector<unsigned> &arr);

void combination(std::vector<unsigned> &arr, size_t n, size_t k);

void binaryGenerate(std::vector<unsigned> &arr);

void generate(std::vector<unsigned> &arr, size_t max)
{
    for (size_t i = 0; i < max; ++i)
    {
        arr.push_back(i + 1);
    }
}

int main(int argc, char *argv[])
{
    size_t n = 6;
    //std::vector<unsigned> permutations;
    //generate(permutations, n);
    //permutation(permutations);

    //std::vector<unsigned> binary(n, 0);
    //binaryGenerate(binary);
    std::vector<unsigned> arr;

    size_t k = 4;

    generate(arr, k);
    combination(arr, n, k);
    return EXIT_SUCCESS;
}

void permutation(std::vector<unsigned> &arr)
{
    show(arr);
    std::cout << std::endl;
    size_t max = arr.size();
    while (true)
    {
        size_t i = max - 1;
        while (i > 0 && arr[i] < arr[i - 1])
        {
            --i;
        }
        if (i == 0)
            break;
        for (size_t k = max - 1; k >= i; --k)
        {
            if (arr[k] > arr[i - 1])
            {
                std::swap(arr[i - 1], arr[k]);
                break;
            }
        }
        //(3, _2, 6, 5, _4, 1) →  (3, _4, .6, 5, _2, 1.) -> (3, _4, ._1, _2, _5, _6.)
        for (size_t x = max - 1; x > 0; --x)
        {
            for (size_t y = i; y < x; ++y)
            {
                if (arr[y] > arr[y + 1])
                    std::swap(arr[y], arr[y + 1]);
            }
        }
        show(arr);
        std::cout << std::endl;
    }
}

void binaryGenerate(std::vector<unsigned> &arr)
{
    // 0 0 0 0 0 -> 0 0 0 0 1 -> 0 0 0 1 0 -> 0 0 0 1 1 ... 0 1 1 1 1 -> 1 0 0 0 0
    show(arr);
    std::cout << std::endl;
    size_t n = arr.size();
    while (true)
    {
        int i = n - 1;

        while (i >= 0 && arr[i])
        {
            --i;
        }
        if (i == -1)
            break;
        arr[i] = 1;

        for (size_t x = i + 1; x < n; ++x)
        {
            arr[x] = 0;
        }
        show(arr);
        std::cout << std::endl;
    }
}

void combination(std::vector<unsigned> &arr, size_t n, size_t k)
{
    // 1234 -> 1235 -> 1236 .... 1456 -> 2345......
    // limition : n - k + i + 1;
    
    show(arr);
    std::cout << std::endl;
    while (true)
    {
        size_t i = k -1;
        while (i >= 0 && arr[i] == n - k + i + 1)
        {
            --i;
        }
        if((int)i == -1) break;
        ++arr[i];

        for (size_t j = i + 1; j <= n; ++j)
        {
            arr[j] = arr[i] + j - i;
        }
        show(arr);std::cout << std::endl;
    }
}
