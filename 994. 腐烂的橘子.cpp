#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 方向数组
        int m = grid.size(), n = grid[0].size();                          // 行数和列数
        queue<pair<int, int>> que;                                        // 存放腐烂的橘子

        int minute = 0; // 经过的分钟数
        int fresh = 0;  // 新鲜橘子的数量

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 将所有腐烂的橘子加入队列
                if (grid[i][j] == 2)
                    que.push({i, j});
                // 统计新鲜橘子的数量
                if (grid[i][j] == 1)
                    ++fresh;
            }
        }

        if (que.empty() && fresh > 0)
            return -1; // 如果没有腐烂的橘子，且有新鲜橘子，返回-1
        else if(que.empty() && fresh == 0)
            return 0; // 如果没有腐烂的橘子，且没有新鲜橘子，返回0

        while (!que.empty())
        {
            int size = que.size(); // 当前分钟数的腐烂橘子数量
            int flag = false;      // 标记是否有新腐烂的橘子
            for (int i = 0; i < size; ++i)
            {
                int x = que.front().first, y = que.front().second; // 取出队首橘子
                que.pop();
                for (auto dir : dirs)
                {
                    int xx = x + dir.first, yy = y + dir.second; // 遍历四个方向
                    if (xx < 0 || xx >= m || yy < 0 || yy >= n || grid[xx][yy] != 1)
                        continue;       // 如果超出边界或者不是新鲜橘子，跳过
                    grid[xx][yy] = 2;   // 将新鲜橘子变为腐烂橘子
                    --fresh;            // 新鲜橘子数量减一
                    que.push({xx, yy}); // 将新腐烂的橘子加入队列
                    flag = true;
                }
            }
            if (flag)
                ++minute; // 有新腐烂的橘子分钟数才会+1
        }

        if (fresh > 0)
            return -1; // 如果还有新鲜橘子，返回-1

        return minute; // 返回分钟数
    }
};