#pragma once

#include <list>
#include <unordered_map>

namespace octo::core
{
class LRUcache
{
  public:
    struct KeyValuePair {
        int key;
        int value;
    };
    using Queue = std::list<KeyValuePair>;

    Queue q;
    std::unordered_map<int, Queue::iterator> map;
    std::size_t capacity_;

    LRUcache(int capacity)
        : capacity_(capacity)
    {
        map.reserve(capacity);
    }

    int get(int key);
    void AddItem(int key, int value);
    void put(int key, int value);
};
} // namespace octo::core
