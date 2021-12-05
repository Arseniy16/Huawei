#include <gtest/gtest.h>

#include "queue-impl.hpp"

template<typename T>
class QueueTest : public testing::Test
{
public:
    using MyType = T;
    const size_t TEST_SIZE = 1000000;

    T val1 = static_cast<T>(9);
    T val2 = static_cast<T>(0);
    queue::Queue<T> queue_one;    
    queue::Queue<T> queue_two;
};

using MyTypes = testing::Types<char, int, long long, float, double, bool>;

TYPED_TEST_SUITE(QueueTest, MyTypes);

TYPED_TEST(QueueTest, IsEmpty)
{
    EXPECT_TRUE(this->queue_one.is_empty());
    EXPECT_TRUE(this->queue_two.is_empty());
}

TYPED_TEST(QueueTest, QueuePush)
{
    for (size_t i = 1; i < this->TEST_SIZE; ++i)
    {
        this->queue_one.push(this->val1);
        this->queue_one.push(this->val1 + i);
        this->queue_two.push(this->val1);
        this->queue_two.push(this->val1 + i);

        EXPECT_TRUE(this->queue_one.front() != this->queue_one.back());
        EXPECT_TRUE(this->queue_two.front() != this->queue_two.back());
        EXPECT_TRUE(this->queue_one.front() == this->queue_two.front());
        EXPECT_TRUE(this->queue_one.back() == this->queue_two.back());
    }
}

TYPED_TEST(QueueTest, QueuePop)
{
    this->queue_one.push(this->val1);
    for (size_t i = 0; i < this->TEST_SIZE; i++)
    {
        this->queue_one.push(this->val2);
        EXPECT_TRUE(this->queue_one.front() != this->queue_one.back());
        this->queue_one.pop();
        EXPECT_TRUE(this->queue_one.front() == this->queue_one.back());
        this->queue_one.pop();
        this->queue_one.push(this->val1);
    }
}

TYPED_TEST(QueueTest, QueuePushSize)
{
    for (size_t i = 1; i < this->TEST_SIZE; i++)
    {
        this->queue_one.push(this->val1);
        EXPECT_TRUE(this->queue_one.size() == i);
    }
}

TYPED_TEST(QueueTest, QueuePopSize)
{
    for (size_t i = 1; i <= this->TEST_SIZE; i++) 
    { 
        this->queue_one.push(this->val1); 
    }
    EXPECT_TRUE(this->queue_one.size() == this->TEST_SIZE);

    for (size_t i = this->TEST_SIZE; i >= 0; --i)
    {
        EXPECT_TRUE(this->queue_one.size() == i);
        
        if (i > 0)
            this->queue_one.pop();
    }
}

TYPED_TEST(QueueTest, OperatorEqual)
{
    EXPECT_TRUE(this->queue_one == this->queue_two);

    this->queue_one.push(this->val1);
    this->queue_two.push(this->val2);
    EXPECT_FALSE(this->queue_one == this->queue_two);
    this->queue_one.pop();
    this->queue_two.pop();

    for (size_t i = 0; i < this->TEST_SIZE; i++)
    {
        this->queue_one.push(this->val1);
        this->queue_two.push(this->val2);
    }
    EXPECT_FALSE(this->queue_one == this->queue_two);
}

TYPED_TEST(QueueTest, OperatorNotEqual)
{
    EXPECT_FALSE(this->queue_one != this->queue_two);

    this->queue_one.push(this->val1);
    this->queue_two.push(this->val2);
    EXPECT_TRUE(this->queue_one != this->queue_two);
    this->queue_one.pop();
    this->queue_two.pop();

    for (size_t i = 0; i < this->TEST_SIZE; i++)
    {
        this->queue_one.push(this->val1);
        this->queue_two.push(this->val2);
    }
    EXPECT_TRUE(this->queue_one != this->queue_two);
}

TYPED_TEST(QueueTest, OperatorAssign)
{
    for (size_t i = 0; i < this->TEST_SIZE; i++)
    {
        this->queue_one.push(i);
    }
    this->queue_two = this->queue_one;
    EXPECT_TRUE(this->queue_one == this->queue_two);
}

TYPED_TEST(QueueTest, DefaultCtor)
{
    EXPECT_TRUE(this->queue_one.is_empty());
    EXPECT_TRUE(this->queue_two.is_empty());
}

TYPED_TEST(QueueTest, Initialize)
{
    using T = typename TestFixture::MyType;
    T *data = new T[this->TEST_SIZE];

    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        data[i] = static_cast<T>(i);
    }

    queue::Queue<T> new_queue(this->TEST_SIZE, data);
    
    EXPECT_TRUE(new_queue.size() == this->TEST_SIZE);

    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        EXPECT_TRUE(new_queue.front() == data[i]);
        new_queue.pop();
    }

    delete[] data;
}

TYPED_TEST(QueueTest, CopyCtor)
{
    using T = typename TestFixture::MyType;
    for (size_t i = 0; i < this->TEST_SIZE; i++)
    {
        this->queue_one.push(i);
    }
    queue::Queue<T> new_queue(this->queue_one);
    EXPECT_TRUE(this->queue_one == new_queue);
}

TYPED_TEST(QueueTest, Swap)
{
    using T = typename TestFixture::MyType;
    for (size_t i = 0; i < this->TEST_SIZE; i++)
    {
        this->queue_one.push(this->val1);
        this->queue_one.push(this->val2);
        this->queue_two.push(this->val2);
        this->queue_two.push(this->val1);
    }
    queue::Queue<T> queue1(this->queue_one);
    queue::Queue<T> queue2(this->queue_two);
    this->queue_one.swap(this->queue_two);
    EXPECT_TRUE((this->queue_two == queue1) && (this->queue_one == queue2));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}