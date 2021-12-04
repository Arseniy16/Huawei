#include <gtest/gtest.h>

#include "../include/stack-impl.hpp"
#include "../include/stack.hpp"

namespace
{
template <typename T>
class StackTest : public testing::Test
{
protected:
    using MyType = T;
    const size_t TEST_SIZE = 1000000;

    T val1 = static_cast<T>(4);
    T val2 = static_cast<T>(2);
    stack::Stack<T> test_stk[2];
};

using MyTypes = testing::Types<char, int, long long, float, double, bool>;

TYPED_TEST_SUITE(StackTest, MyTypes);

TYPED_TEST(StackTest, IsEmpty)
{
    EXPECT_TRUE(this->test_stk[0].is_empty());
    EXPECT_TRUE(this->test_stk[1].is_empty());
}

TYPED_TEST(StackTest, StackPush)
{
    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        this->test_stk[0].push(this->val1);
        this->test_stk[1].push(this->val2);
        EXPECT_TRUE(this->test_stk[0].top() == this->val1);
        EXPECT_TRUE(this->test_stk[1].top() == this->val2);
    }
}

TYPED_TEST(StackTest, StackPop)
{
    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        this->test_stk[0].push(this->val1);
        this->test_stk[0].push(this->val2);

        auto new_val1 = this->test_stk[0].top();
        this->test_stk[0].pop();
        auto new_val2 = this->test_stk[0].top();

        EXPECT_TRUE((new_val1 == this->val2) && (new_val2 == this->val1));
    }
}

TYPED_TEST(StackTest, OperatorEqual)
{
    EXPECT_TRUE(this->test_stk[0] == this->test_stk[1]);

    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        this->test_stk[0].push(i);
        this->test_stk[1].push(i);
    }
    EXPECT_TRUE(this->test_stk[0] == this->test_stk[1]);
}

TYPED_TEST(StackTest, OperatorNotEqual)
{
    EXPECT_FALSE(this->test_stk[0] != this->test_stk[1]);

    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        this->test_stk[0].push(i);
        this->test_stk[1].push(this->val2);
    }
    EXPECT_TRUE(this->test_stk[0] != this->test_stk[1]);
}

TYPED_TEST(StackTest, OperatorAssign)
{
    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        this->test_stk[0].push(this->val1);
        this->test_stk[1].push(this->val2);
    }

    this->test_stk[1] = this->test_stk[0];

    EXPECT_TRUE(this->test_stk[0] == this->test_stk[1]);

    this->test_stk[1].pop();

    this->test_stk[0] = this->test_stk[1];

    EXPECT_TRUE(this->test_stk[1] == this->test_stk[0]);
}

TYPED_TEST(StackTest, DefaultCtor)
{
    EXPECT_TRUE(this->test_stk[0].is_empty());
    EXPECT_TRUE(this->test_stk[0].capacity() == this->test_stk[0].CAPACITY);
}

TYPED_TEST(StackTest, CtorOneParam)
{
    using T = typename TestFixture::MyType;

    stack::Stack<T> new_stk(this->TEST_SIZE);
    
    EXPECT_TRUE(new_stk.size() == this->TEST_SIZE);
    EXPECT_TRUE(new_stk.capacity() == this->TEST_SIZE);
}

TYPED_TEST(StackTest, Initialize)
{
    using T = typename TestFixture::MyType;

    T *data = new T[this->TEST_SIZE];

    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        data[i] = static_cast<T>(i);
    }

    stack::Stack<T> new_stk(this->TEST_SIZE, data);

    EXPECT_TRUE(new_stk.size() == this->TEST_SIZE);
    EXPECT_TRUE(new_stk.capacity() == this->TEST_SIZE);

    for (int i = this->TEST_SIZE - 1; i >= 0; --i)
    {
        EXPECT_TRUE(new_stk.top() == data[i]);
        if (i > 0)
            new_stk.pop();
    }

    delete[] data;
}

TYPED_TEST(StackTest, CopyCtor)
{
    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        this->test_stk[0].push(i);
    }

    using T = typename TestFixture::MyType;
    stack::Stack<T> new_stk(this->test_stk[0]);

    EXPECT_TRUE(new_stk == this->test_stk[0]);
}

TYPED_TEST(StackTest, MoveCtor)
{
    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        this->test_stk[0].push(i);
    }

    this->test_stk[1] = this->test_stk[0];

    using T = typename TestFixture::MyType;
    stack::Stack<T> new_stk(std::move(this->test_stk[0]));

    EXPECT_TRUE(this->test_stk[0].size() == 0);
    EXPECT_TRUE(new_stk == this->test_stk[1]);
}

TYPED_TEST(StackTest, StackSwap)
{
    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        this->test_stk[0].push(this->val1);
        this->test_stk[1].push(this->val2);
    }

    using T = typename TestFixture::MyType;
    stack::Stack<T> temp_stk1 = this->test_stk[0];
    stack::Stack<T> temp_stk2 = this->test_stk[1];

    this->test_stk[0].swap(this->test_stk[1]);
    EXPECT_TRUE(this->test_stk[0] == temp_stk2);
    EXPECT_TRUE(this->test_stk[1] == temp_stk1);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

} // namespace