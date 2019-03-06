#include "time.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(Time, AddMinutes)
{
    Time t(1, 50, 20);

    std::string str;

    t = t + 5;
    str << t;
    ASSERT_EQ(str, "1:55:20");

    t = t + 10;
    str << t;
    ASSERT_EQ(str, "2:5:20");

    t = t + 180;
    str << t;
    ASSERT_EQ(str, "5:5:20");
}

TEST(Time, MinTime)
{
    Time first(0, 0, 0);
    Time second(1, 5, 10);

    std::string str;

    first = first - second;
    str << first;
    ASSERT_EQ(str, "-1:5:10");

    std::string("-0:5:10") >> first;
    std::string("-2:50:45") >> second;
    first = first - second;
    str << first;
    ASSERT_EQ(str, "2:45:35");

    std::string("-0:5:10") >> first;
    std::string("-2:50:45") >> second;
    first = second - first;
    str << first;
    ASSERT_EQ(str, "-2:45:35");

    std::string("3:5:10") >> first;
    std::string("-2:50:45") >> second;
    first = first - second;
    str << first;
    ASSERT_EQ(str, "5:55:55");

    std::string("3:5:10") >> first;
    std::string("-2:50:45") >> second;
    first = second - first;
    str << first;
    ASSERT_EQ(str, "-5:55:55");

    std::string("1:30:20") >> first;
    std::string("0:50:10") >> second;
    first = first - second;
    str << first;
    ASSERT_EQ(str, "0:40:10");

    std::string("0:50:10") >> first;
    std::string("1:30:20") >> second;
    first = first - second;
    str << first;
    ASSERT_EQ(str, "-0:40:10");
}

TEST(Time, operatorCompare)
{
    Time first(0, 0, 0);
    Time second(1, 5, 10);

    std::string("-0:5:10") >> first;
    std::string("-2:50:45") >> second;
    ASSERT_TRUE(first > second);
    ASSERT_FALSE(second > first);

    std::string("0:5:10") >> first;
    std::string("-2:50:45") >> second;
    ASSERT_TRUE(first > second);
    ASSERT_FALSE(second > first);

    std::string("-2:50:10") >> first;
    std::string("-2:50:45") >> second;
    ASSERT_TRUE(first > second);
    ASSERT_FALSE(second > first);

    std::string("3:5:10") >> first;
    std::string("3:0:45") >> second;
    ASSERT_TRUE(first > second);
    ASSERT_FALSE(second > first);
}

TEST(Time, operatorIvers)
{
    Time first(0, 0, 0);
    Time second(1, 5, 10);

    std::string("-0:5:10") >> first;
    std::string("-2:50:45") >> second;
    std::string test;
    test << -first;
    ASSERT_EQ(test, "0:5:10");
    test << -second;
    ASSERT_EQ(test, "2:50:45");

    std::string("3:5:10") >> first;
    std::string("3:0:45") >> second;
    test << -first;
    ASSERT_EQ(test, "-3:5:10");
    test << -second;
    ASSERT_EQ(test, "-3:0:45");
}
