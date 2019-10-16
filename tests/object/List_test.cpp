#include <gtest/gtest.h>

#include <object/List.hpp>

using namespace lazyant;

TEST(TracedList, push_back)
{
    object::TracedList<int> list;
    ASSERT_TRUE(list.empty());

    list.push_back(10);
    ASSERT_EQ(list.size(), 1);
}

TEST(TracedList, push_back_several_time)
{
    object::TracedList<int> list;
    ASSERT_TRUE(list.empty());

    constexpr auto target_size = 100;
    for (int i = 0; i < target_size; ++i) {
        list.push_back(target_size);
    }

    ASSERT_EQ(list.size(), target_size);
}

