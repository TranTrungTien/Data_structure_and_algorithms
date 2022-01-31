#include <iostream>
#include <vector>

int s = 0;
int e = 0;

//normal
int maxSubArr(std::vector<int> &arr)
{
    int n = arr.size();
    int best = INT_MIN;
    unsigned start = 0;
    unsigned end = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if(sum >= best)
            {
                best = sum;
                end = j;
                start = i;
            }
        }
    }
    std::cout << start << " : " << end << std::endl;
    return best;
}

//work for negative // dynamic 
int maxSubArray(std::vector<int> &nums)
{
    // use kadane's agorithms

    int currentSum = 0;
    int sum = INT32_MIN;

    int start = 0;
    int end = 0;
    int mark = 0;

    for (unsigned int i = 0; i < nums.size(); ++i)
    {
        currentSum += nums[i];
        currentSum = std::max(nums[i], currentSum);
        if (currentSum == nums[i])
            mark = i;
        if (currentSum >= sum)
        {
            sum = currentSum;
            start = mark;
            end = i;
        }
    }
    std::cout << start << " : " << end << std::endl;
    return sum;
}

// divide and conquer 



#include <limits.h>
#include <stdio.h>
 
// A utility function to find maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
// A utility function to find maximum of three integers
int max(int a, int b, int c) { return max(max(a, b), c); }
 
// Find the maximum possible sum in arr[] auch that arr[m]
// is part of it
int maxCrossingSum(std::vector<int> arr, int l, int m, int h)
{
    // Include elements on left of mid.
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
 
    // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
 
    // Return sum of elements on left and right of mid
    // returning only left_sum + right_sum will fail for
    // [-2, 1]
    return max(left_sum + right_sum, left_sum, right_sum);
}
 
// Returns sum of maximum sum subarray in aa[l..h]
int maxSubArraySum(std::vector<int> arr, int l, int h)
{
    // Base Case: Only one element
    if (l == h)
        return arr[l];
 
    // Find middle point
    int m = (l + h) / 2;
 
    /* Return maximum of following three possible cases
            a) Maximum subarray sum in left half
            b) Maximum subarray sum in right half
            c) Maximum subarray sum such that the subarray
       crosses the midpoint */
    return max(maxSubArraySum(arr, l, m),
               maxSubArraySum(arr, m + 1, h),
               maxCrossingSum(arr, l, m, h));
}
 

int main(int argc, char *argv[])
{
    std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    //int result = maxSubArr(arr);
    
    int result = maxSubArraySum(arr, 0, arr.size() - 1);
    std::cout << result << std::endl;
    return EXIT_SUCCESS;
}