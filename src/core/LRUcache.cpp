#include <list>
#include <unordered_map>
using namespace std;

class LRUCache
{
  public:
    unordered_map<int, int> map;
    int cap;
    list<int> q;
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (map.count(key) != 0) {
            q.remove(key);
            q.push_back(key);
            return map[key];
        } else {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (map.size() < cap) {
            map[key] = value;
            q.remove(key);
            q.push_back(key);
        } else if (map.count(key) == 0) {
            map.erase(q.front());
            q.pop_front();
            map[key] = value;
            q.push_back(key);
        } else {
            map[key] = value;
            q.remove(key);
            q.push_back(key);
        }
    }
};

int main()
{
    LRUCache lru = LRUCache(2);
    lru.get(2);
    lru.put(2, 6);
    lru.get(1);
    lru.put(1, 5);
    lru.put(1, 2);
    lru.get(1);
    lru.get(2);
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */