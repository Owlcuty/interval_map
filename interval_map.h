#pragma once
#include <map>
#include <list>
#include <algorithm>

// Здесь можно было бы дать возможность юзеру передать компаратор
template <typename K, typename V>
// Здесь обычно предпочитаю другой codestyle (IntervalMap), мне интерсно, придерживаетесь ли вы каких-то стандартов
class interval_map
{
public:
    interval_map() {}
    ~interval_map() {}

    void insert(const K& k, const V& v)
    {
        if (map_.find(k) != map_.end())
        {
            std::list<V>& intervals = map_[k];
            insert_interval(intervals, v);
        }
        else
        {
            map_[k] = std::list<V>{v};
        }
    }

    void dump()
    {
        for (auto el = map_.begin(); el != map_.end(); el++)
        {
            std::cout << "<" << el->first << ", ";
            for (auto it = el->second.begin(); it != el->second.end(); it++)
            {
                std::cout << "(" << it->first << ", " << it->second << ")";
            }
            std::cout << ">" << std::endl;
        }
    }

private:
    void insert_interval(std::list<V>& intervals, const V& v)
    {
        V tmp_v = v;
        auto it = intervals.begin();
        while (it != intervals.end() && it->second < tmp_v.first)
        {
            it++;
        }

        auto last_it = it;
        while (it != intervals.end() && it->first <= tmp_v.second)
        {
            tmp_v.first = std::min(tmp_v.first, it->first);
            tmp_v.second = std::max(tmp_v.second, it->second);
            it++;
        }
        if (last_it != it)
        {
            it = intervals.erase(last_it, it);
            if (it == intervals.end())
            {
                intervals.push_back(tmp_v);
                return;
            }
            if (it == intervals.begin())
            {
                intervals.push_front(tmp_v);
                return;
            }
            it->first = tmp_v.first;
            it->second = tmp_v.second;
        }
        else
        {
            intervals.insert(it, tmp_v);
        }
    }

private:
    std::map<K, std::list<V>> map_;
};