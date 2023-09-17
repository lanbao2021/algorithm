#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        // 判断第一行和第一列是否要置为0
        bool zero_row = false;
        bool zero_col = false;

        // 判断第一列是否要置为0
        for (int i = 0; i < m; ++i)
        {
            if (matrix[i][0] == 0)
            {
                zero_col = true;
                break;
            }
        }

        // 判断第一列是否要置为0
        for (int j = 0; j < n; ++j)
        {
            if (matrix[0][j] == 0)
            {
                zero_row = true;
                break;
            }
        }

        // 留出第一行和第一列用于记录某行某列是否要置为0
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // 从第二行第二列开始，如果某行或某列的第一个元素为0，则将该行或该列置为0
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // 置第一行和第一列为0
        if (zero_col)
        {
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        }

        // 置第一列为0
        if (zero_row)
        {
            for (int j = 0; j < n; ++j)
                matrix[0][j] = 0;
        }
    }
};