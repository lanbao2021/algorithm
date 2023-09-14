#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution
{
private:
    int m, n;
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int i, int j)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j])
            return;
        
        
        visited[i][j] = true;
        
        if(i - 1 >= 0 && heights[i - 1][j] >= heights[i][j]) // 上
            dfs(heights, visited, i - 1, j);
        if(i + 1 < m && heights[i + 1][j] >= heights[i][j]) // 下
            dfs(heights, visited, i + 1, j);
        if(j - 1 >= 0 && heights[i][j - 1] >= heights[i][j]) // 左
            dfs(heights, visited, i, j - 1);
        if(j + 1 < n && heights[i][j + 1] >= heights[i][j]) // 右
            dfs(heights, visited, i, j + 1);
        
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // 从pacific的左边和atlantic的右边开始dfs
        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }

        // 从pacific的上边和atlantic的下边开始dfs
        for (int j = 0; j < n; j++)
        {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }

        // 找到两个都能到达的点
        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});

        return res;
    }
};

int main()
{
    cout << "hdhaf" << endl;
    return 0;
}