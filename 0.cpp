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
        Trie *node = this;
        for (auto c : word)
        {
            if (node->next[c - 'a'] == nullptr)
                node->next[c - 'a'] = new Trie();
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        Trie *node = this;
        for (auto c : word)
        {
            if (node->next[c - 'a'] == nullptr)
                return false;
            node = node->next[c - 'a'];
        }
        return node->isEnd;
    }

    bool startWith(string prefix)
    {
        Trie *node = this;
        for (auto c : prefix)
        {
            if (node->next[c - 'a'] == nullptr)
                return false;
            node->next[c - 'a'];
        }
        return true;
    }
};