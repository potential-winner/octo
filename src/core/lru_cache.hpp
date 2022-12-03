#pragma once

#include <cstddef>
#include <list>
#include <unordered_map>

namespace octo::core
{
class LruCache
{
  private:
    struct KeyValuePair {
        int key;
        int value;
    };
    using Order = std::list<KeyValuePair>;

  private:
    Order order;
    std::unordered_map<int, Order::iterator> map;
    std::size_t capacity_;

  private:
    void addItem(int key, int value);

  public:
    LruCache(std::size_t capacity);

    int get(int key);
    void put(int key, int value);
};
} // namespace octo::core
