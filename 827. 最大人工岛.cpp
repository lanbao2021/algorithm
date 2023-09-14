#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
    int m, n;
    int count;
    int number;
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0)
            return;
        
        count++;
        grid[i][j] = number; // 标记岛屿编号
        visited[i][j] = true;

        dfs(grid, visited, i - 1, j); // 上
        dfs(grid, visited, i + 1, j); // 下
        dfs(grid, visited, i, j - 1); // 左
        dfs(grid, visited, i, j + 1); // 右
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        unordered_map<int, int> mp; // <岛屿编号，岛屿面积>
        number = 2; // 岛屿编号从2开始

        // 第一遍：求出每个岛屿的面积
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    count = 0;
                    dfs(grid, visited, i, j);
                    mp[number] = count;
                    ++number; // 岛屿编号加1
                }
            }
        }

        // 第二遍：遍历每个0，看看能否连接[上、下、左、右]的岛屿
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; ++j){
                if(grid[i][j] == 0){
                    int cur = 1; // 当前0所在位置的岛屿面积
                    unordered_set<int> s; // 记录上下左右的岛屿编号

                    if(i - 1 >= 0 && grid[i - 1][j] > 1) s.insert(grid[i - 1][j]);
                    if(i + 1 < m && grid[i + 1][j] > 1) s.insert(grid[i + 1][j]);
                    if(j - 1 >= 0 && grid[i][j - 1] > 1) s.insert(grid[i][j - 1]);
                    if(j + 1 < n && grid[i][j + 1] > 1) s.insert(grid[i][j + 1]);

                    for (auto it = s.begin(); it != s.end(); ++it)
                        cur += mp[*it];

                    res = max(res, cur);
                }
            }
        }

        // 如果res为0，说明没有0，那么就返回m * n
        return res == 0 ? m * n : res;
    }
};


// int main(){
//     vector<vector<int>> grid = {{1, 0}, {0, 1}};
//     Solution sol;
//     cout << sol.largestIsland(grid) << endl;
    
//     return 0;
// }