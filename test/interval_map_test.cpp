#include <gtest/gtest.h>
#include "../interval_map.h"

TEST(oneKey, addFirstOne)
{
    interval_map<int, std::pair<int, int>> intervals;

    intervals.insert(1, {1, 5});

    std::string expectation = "<1, (1, 5)>\n";

    testing::internal::CaptureStdout();
    intervals.dump();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(expectation == output);
}

TEST(oneKey, addIndividual)
{
    interval_map<int, std::pair<int, int>> intervals;

    intervals.insert(1, {1, 5});
    intervals.insert(1, {10, 50});

    std::string expectation = "<1, (1, 5)(10, 50)>\n";

    testing::internal::CaptureStdout();
    intervals.dump();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(expectation == output);
}

TEST(oneKey, addInInterval)
{
    interval_map<int, std::pair<int, int>> intervals;

    intervals.insert(1, {3, 6});
    intervals.insert(1, {6, 9});

    std::string expectation = "<1, (3, 9)>\n";

    testing::internal::CaptureStdout();
    intervals.dump();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(expectation == output);
}

TEST(oneKey, addToInterval)
{
    interval_map<int, std::pair<int, int>> intervals;

    intervals.insert(1, {3, 6});
    intervals.insert(1, {6, 9});
    intervals.insert(1, {24, 30});

    std::string expectation = "<1, (3, 9)(24, 30)>\n";

    testing::internal::CaptureStdout();
    intervals.dump();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(expectation == output);
}

TEST(oneKey, changeIntervalMiddle)
{
    interval_map<int, std::pair<int, int>> intervals;

    intervals.insert(1, {3, 6});
    intervals.insert(1, {6, 9});
    intervals.insert(1, {24, 30});
    intervals.insert(1, {15, 22});

    std::string expectation = "<1, (3, 9)(15, 22)(24, 30)>\n";

    testing::internal::CaptureStdout();
    intervals.dump();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(expectation == output);
}

TEST(oneKey, addToBegin)
{
    interval_map<int, std::pair<int, int>> intervals;

    intervals.insert(1, {3, 6});
    intervals.insert(1, {6, 9});
    intervals.insert(1, {24, 30});
    intervals.insert(1, {15, 22});
    intervals.insert(1, {-10, -2});

    std::string expectation = "<1, (-10, -2)(3, 9)(15, 22)(24, 30)>\n";

    testing::internal::CaptureStdout();
    intervals.dump();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(expectation == output);
}
    