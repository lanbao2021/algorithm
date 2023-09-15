#include <vector>
#include <utility>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache
{
    size_t m_capacity;
    list<pair<int, int>> m_list;
    unordered_map<int, list<pair<int, int>>::iterator> m_map;

public:
    LRUCache(int capacity) : m_capacity(capacity) {}
    int get(int key)
    {
        auto iter = m_map.find(key); // 查找key
        if (iter == m_map.end())     // 如果key不存在，返回-1
            return -1;
        m_list.splice(m_list.begin(), m_list, iter->second); // 将key对应的节点移动到链表头部
        return iter->second->second;                         // 返回key对应的value
    }

    void put(int key, int value)
    {
        auto iter = m_map.find(key);
        if (iter != m_map.end())
        {
            iter->second->second = value;                        // 如果key存在，修改value
            m_list.splice(m_list.begin(), m_list, iter->second); // 将key对应的节点移动到链表头部
            return;
        }
        if (m_map.size() == m_capacity)
        {                                     // 如果容量已满
            m_map.erase(m_list.back().first); // 删除链表尾部节点
            m_list.pop_back();
        }

        m_list.emplace_front(key, value); // 将新节点插入链表头部
        m_map[key] = m_list.begin();      // 更新key对应的迭代器
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */