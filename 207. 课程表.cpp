#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);   // 记录每个节点的入度
        unordered_map<int, vector<int>> graph; // 记录每个节点的后继节点
        for (auto edge : prerequisites)
        {
            ++indegree[edge[0]];               // 统计每个节点的入度
            graph[edge[1]].push_back(edge[0]); // 记录每个节点的后继节点
        }

        queue<int> que; // 用于广度优先搜索
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
                que.push(i); // 将入度为0的节点加入队列
        }

        int cnt = 0; // 记录可以学完的课程数量
        while (!que.empty())
        {
            int u = que.front(); // 取出队首节点
            que.pop();           // 弹出队首节点
            ++cnt;               // 学完一门课程
            for (auto v : graph[u])
            {
                --indegree[v];        // 将u的后继节点的入度减一
                if (indegree[v] == 0) // 如果入度为0，加入队列
                    que.push(v);
            }
        }
        return cnt == numCourses; // 如果学完的课程数量等于总课程数量，返回true
    }
};