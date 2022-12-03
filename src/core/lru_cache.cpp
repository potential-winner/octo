#include "lru_cache.hpp"

namespace octo::core
{
LruCache::LruCache(std::size_t capacity)
    : capacity_(capacity)
{
    map.reserve(capacity);
}

int LruCache::get(int key)
{
    auto it = map.find(key);
    if (it != map.end()) {
        auto queue_it = it->second;
        order.splice(order.begin(), order, queue_it);
        return queue_it->value;
    }
    return -1;
}

void LruCache::addItem(int key, int value)
{
    order.push_front(KeyValuePair{key, value}); // put item in the queue
    auto queue_it = order.begin();              // got iterator to the previously inserted item
    map.emplace(key, std::move(queue_it));      // save iterator to previously inserted item in the hash table
}

void LruCache::put(int key, int value)
{
    auto it = map.find(key);
    if (it != map.end()) {
        auto queue_it = it->second;
        order.splice(order.begin(), order, queue_it);
        order.front().value = value;
    } else if (order.size() < capacity_) {
        addItem(key, value);
    } else {
        int least_recently_used_key = order.back().key;
        map.erase(least_recently_used_key);
        order.pop_back();

        addItem(key, value);
    }
}
} // namespace octo::core
