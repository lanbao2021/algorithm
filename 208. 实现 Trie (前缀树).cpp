#include <vector>
#include <string>
using namespace std;

class Trie
{
    bool isEnd;
    Trie *next[26];

public:
    Trie()
    {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }

    void insert(string word)
    {
        Trie *node = this; // 从根节点开始插入
        for(char c : word){
            if(node->next[c - 'a'] == nullptr){
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a']; // 插入下一个节点
        }
        node->isEnd = true; // 标记为单词结尾
    }

    bool search(string word)
    {
        Trie *node = this;
        for(char c : word){
            node = node->next[c - 'a'];
            if(node == nullptr){
                return false;
            }
        }
        return node->isEnd;
    }

    bool startsWith(string prefix)
    {
        Trie *node = this;
        for(char c : prefix){
            node = node->next[c - 'a'];
            if(node == nullptr){
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */