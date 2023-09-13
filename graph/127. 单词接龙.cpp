#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;

// 广搜只要搜到了终点，那么一定是最短的路径，因为广搜就是以起点中心向四周扩散的搜索。
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end()); // 用于判断是否存在，转为set查询效率更高
        if(wordSet.find(endWord) == wordSet.end()) return 0; // 如果终点不在字典中，直接返回0
        
        queue<string> que; // 用于广度优先搜索
        que.push(beginWord); // 先将起点加入队列

        unordered_map<string, int> dist; // 记录到起点的距离
        dist[beginWord] = 1; // 起点到起点的距离为1

        while(!que.empty()){
            string word = que.front(); // 取出队首单词
            que.pop();
            int path = dist[word]; // 取出到该单词的距离

            for (int i = 0; i < word.size(); ++i){
                string newWord = word; // 用于修改的新单词
                for (int j = 0; j < 26; ++j){
                    newWord[i] = j + 'a'; // 修改单词的第i个字符为a-z
                    if(newWord == endWord) return path + 1; // 如果新单词为终点，返回距离
                    if(wordSet.find(newWord) == wordSet.end() || dist.find(newWord) != dist.end())
                        continue; // 如果新单词不存在于字典中或者已经访问过，跳过
                    que.push(newWord); // 将新单词加入队列
                    dist[newWord] = path + 1; // 记录新单词到起点的距离
                }
            }
        }
        return 0; // 队列为空，无法转换到终点（这个到不了）
    }
};