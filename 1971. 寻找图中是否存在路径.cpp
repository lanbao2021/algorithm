#include<vector>
using namespace std;

class Solution {
    int n = 200005;
    vector<int> father = vector<int>(n, 0);

    void init(){ // 初始化并查集
        for (int i = 0; i < n; ++i){
            father[i] = i;
        }
    }

    int find(int u){ // 查找u的根节点, 递归查找
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    bool isSame(int u, int v){ // 判断u和v是否在同一个集合中
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v){ 
        u = find(u);
        v = find(v);
        if(u == v)
            return; // 如果已经在同一个集合中，直接返回
        father[v] = u; // 将v的根节点指向u的根节点
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        init();
        for (int i = 0; i < edges.size(); ++i){
            join(edges[i][0], edges[i][1]); // 将边的两个节点合并
        }
        return isSame(source, destination); // 判断起点和终点是否在同一个集合中
    }
};