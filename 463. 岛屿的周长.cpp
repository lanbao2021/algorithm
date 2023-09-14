#include<vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    // 上
                    if(i == 0 || grid[i - 1][j] == 0)
                        ++res;
                    // 下
                    if(i == m - 1 || grid[i + 1][j] == 0)
                        ++res;
                    // 左
                    if(j == 0 || grid[i][j - 1] == 0)
                        ++res;
                    // 右
                    if(j == n - 1 || grid[i][j + 1] == 0)
                        ++res;
                }
            }
        }
        return res;
    }
};