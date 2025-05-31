#include <gtest/gtest.h>
#include "list.h"

using namespace std;

template class CircularList<int>; 

TEST(CircularListTest, ConstructorDestructor) {
    CircularList<int> list;
    EXPECT_TRUE(list.IsEmpty());
    EXPECT_EQ(list.GetSize(), 0);
}

TEST(CircularListTest, IsEmpty) {
    CircularList<int> list;
    EXPECT_TRUE(list.IsEmpty());
    list.PushFront(1);
    EXPECT_FALSE(list.IsEmpty());
    list.PopFront();
    EXPECT_TRUE(list.IsEmpty());
}

TEST(CircularListTest, GetSize) {
    CircularList<int> list;
    EXPECT_EQ(list.GetSize(), 0);
    list.PushBack(10);
    EXPECT_EQ(list.GetSize(), 1);
    list.PushFront(20);
    EXPECT_EQ(list.GetSize(), 2);
    list.PopBack();
    EXPECT_EQ(list.GetSize(), 1);
}

TEST(CircularListTest, PushBack) {
    CircularList<int> list;
    list.PushBack(10);
    EXPECT_EQ(list.GetSize(), 1);
    EXPECT_EQ(list.get(0), 10);

    list.PushBack(20);
    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_EQ(list.get(1), 20);
}

TEST(CircularListTest, PushFront) {
    CircularList<int> list;
    list.PushFront(10);
    EXPECT_EQ(list.GetSize(), 1);
    EXPECT_EQ(list.get(0), 10);

    list.PushFront(20);
    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_EQ(list.get(0), 20);
    EXPECT_EQ(list.get(1), 10);
}

TEST(CircularListTest, PopFront) {
    CircularList<int> list;
    list.PushBack(10);
    list.PushBack(20);

    list.PopFront();
    EXPECT_EQ(list.GetSize(), 1);
    EXPECT_EQ(list.get(0), 20);

    list.PopFront();
    EXPECT_TRUE(list.IsEmpty());
}

TEST(CircularListTest, PopFrontEmpty) {
    CircularList<int> list;
    EXPECT_THROW(list.PopFront(), out_of_range);
}

TEST(CircularListTest, PopBack) {
    CircularList<int> list;
    list.PushBack(10);
    list.PushBack(20);

    list.PopBack();
    EXPECT_EQ(list.GetSize(), 1);
    EXPECT_EQ(list.get(0), 10);

    list.PopBack();
    EXPECT_TRUE(list.IsEmpty());
}

TEST(CircularListTest, PopBackEmpty) {
    CircularList<int> list;
    EXPECT_THROW(list.PopBack(), out_of_range);
}

TEST(CircularListTest, Clear) {
    CircularList<int> list;
    list.PushBack(10);
    list.PushBack(20);
    list.PushBack(30);

    list.clear();
    EXPECT_TRUE(list.IsEmpty());
    EXPECT_EQ(list.GetSize(), 0);
}

TEST(CircularListTest, Insert) {
    CircularList<int> list;
    list.insert(0, 10); 
    list.insert(1, 30); 
    list.insert(1, 20); 

    EXPECT_EQ(list.GetSize(), 3);
    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 20);
    EXPECT_EQ(list.get(2), 30);
}

TEST(CircularListTest, InsertInvalidIndex) {
    CircularList<int> list;
    EXPECT_THROW(list.insert(-1, 10), out_of_range);
    EXPECT_THROW(list.insert(1, 10), out_of_range);
}

TEST(CircularListTest, Remove) {
    CircularList<int> list;
    list.PushBack(10);
    list.PushBack(20);
    list.PushBack(30);

    list.remove(1); 
    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 30);

    list.remove(0); 
    EXPECT_EQ(list.GetSize(), 1);

    list.remove(0); 
    EXPECT_TRUE(list.IsEmpty());
}

TEST(CircularListTest, RemoveInvalidIndex) {
    CircularList<int> list;
    EXPECT_THROW(list.remove(-1), out_of_range);
    EXPECT_THROW(list.remove(0), out_of_range);
}

TEST(CircularListTest, Get) {
    CircularList<int> list;
    list.PushBack(10);
    list.PushBack(20);

    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 20);
}

TEST(CircularListTest, GetInvalidIndex) {
    CircularList<int> list;
    EXPECT_THROW(list.get(-1), out_of_range);
    EXPECT_THROW(list.get(0), out_of_range);

    list.PushBack(10);
    EXPECT_THROW(list.get(1), out_of_range);
}

TEST(CircularListTest, Circularity) {
    CircularList<int> list;
    list.PushBack(10);
    list.PushBack(20);
    list.PushBack(30);

    
    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(2), 30);

    list.PopFront();
    EXPECT_EQ(list.get(0), 20);
    EXPECT_EQ(list.get(1), 30);

    list.PushFront(5);
    EXPECT_EQ(list.get(0), 5);
    EXPECT_EQ(list.get(2), 30);
}

TEST(CircularListTest, PrintEmpty) {
    CircularList<int> list;
    testing::internal::CaptureStdout();
    list.print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "()");
}

TEST(CircularListTest, PrintNonEmpty) {
    CircularList<int> list;
    list.PushBack(10);
    list.PushBack(20);

    testing::internal::CaptureStdout();
    list.print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("10") != string::npos);
    EXPECT_TRUE(output.find("20") != string::npos);
    EXPECT_TRUE(output.find("()") != string::npos);
}

TEST(CircularListTest, StressTest) {
    CircularList<int> list;
    const int COUNT = 1000;

    for (int i = 0; i < COUNT; ++i) {
        list.PushBack(i);
    }
    EXPECT_EQ(list.GetSize(), COUNT);

    for (int i = 0; i < COUNT; ++i) {
        EXPECT_EQ(list.get(i), i);
    }

    for (int i = 0; i < COUNT; ++i) {
        list.PopFront();
    }
    EXPECT_TRUE(list.IsEmpty());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}