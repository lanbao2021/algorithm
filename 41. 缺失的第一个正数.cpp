#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size(); // 数组长度
        for (int i = 0; i < n; ++i)
        {
            // 让处于[1, n-1]闭区间上的数都处于正确的位置
            // 正确位置的含义：nums[i] == i
            while (nums[i] >= 1 && nums[i] <= n-1 && nums[nums[i]] != nums[i])
                swap(nums[i], nums[nums[i]]);
        }

        // 判断处于[1, n-1]闭区间上的数都处于正确的位置
        for (int i = 1; i <= n - 1; ++i)
            if (nums[i] != i)
                return i; // 返回第一个不在正确位置上的数

        // 如果处于[1, n-1]闭区间上的数都处于正确的位置，判断下标为0处是否藏着n
        return nums[0] == n ? n + 1 : n; // 如果nums[0] == n，说明n出现过返回n+1
    }
};