#include <vector>
using namespace std;
void dfs(vector<vector<int>> &rooms, int cur, vector<bool> &visited)
{
    if (visited[cur]) // 如果已经访问过，直接返回
        return;
    visited[cur] = true; // 标记为已访问
    for (auto next : rooms[cur])
    { // 遍历当前房间的钥匙
        dfs(rooms, next, visited);
    }
}

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {                                              // 本质上是图的遍历
        vector<bool> visited(rooms.size(), false); // 记录是否访问过
        dfs(rooms, 0, visited);                    // 从0号房间开始遍历
        for (auto v : visited)
        { // 遍历visited，如果有false，说明有房间没访问到
            if (!v)
                return false;
        }
        return true;
    }
};