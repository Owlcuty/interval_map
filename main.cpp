#include <iostream>

#include "interval_map.h"


int main()
{
    interval_map<int, std::pair<int, int>> intervals;

    intervals.insert(10, {3, 6});
    intervals.insert(10, {6, 9});
    intervals.insert(10, {24, 30});
    intervals.insert(10, {15, 22});
    intervals.insert(10, {4, 20});
    intervals.insert(10, {40, 62});
    intervals.insert(10, {-10, -2});
    intervals.insert(10, {-3, 2});
    intervals.insert(10, {2, 60});

    intervals.dump();

    return 0;
}