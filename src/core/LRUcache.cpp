#include "LRUcache.hpp"

namespace octo::core
{
int LRUcache::get(int key)
{
    auto it = map.find(key);
    if (it != map.end()) {
        auto queue_it = it->second;
        q.splice(q.begin(), q, queue_it);
        return queue_it->value;
    }
    return -1;
}

void LRUcache::AddItem(int key, int value)
{
    q.push_front(KeyValuePair{key, value}); // put item in the queue
    auto queue_it = q.begin();              // got iterator to the previously inserted item
    map.emplace(key, std::move(queue_it));  // save iterator to previously inserted item in the hash table
}

void LRUcache::put(int key, int value)
{
    auto it = map.find(key);
    if (it != map.end()) {
        auto queue_it = it->second;
        q.splice(q.begin(), q, queue_it);
        q.front().value = value;
    } else if (q.size() < capacity_) {
        AddItem(key, value);
    } else {
        int least_recently_used_key = q.back().key;
        map.erase(least_recently_used_key);
        q.pop_back();

        AddItem(key, value);
    }
}
} // namespace octo::core
