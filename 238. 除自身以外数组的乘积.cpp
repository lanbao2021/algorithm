#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size(); // 数组长度
        if (n == 0)          // 空数组
            return {};
        vector<int> res(n, 1);      // 结果数组
        int left = 1, right = 1;    // 左右乘积
        for (int i = 0; i < n; i++) // 从左到右遍历
        {
            res[i] *= left;           // 乘以左边的乘积
            left *= nums[i];          // 更新左边的乘积
            res[n - 1 - i] *= right;  // 乘以右边的乘积
            right *= nums[n - 1 - i]; // 更新右边的乘积
        }
        return res; // 返回结果数组
    }
};