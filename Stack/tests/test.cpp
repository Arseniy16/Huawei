#include <gtest/gtest.h>

#include "stack-impl.hpp"
#include "stack.hpp"

template <typename T>
class StackTest : public testing::Test
{
public:
    using MyType = T;
    const size_t TEST_SIZE = 1000000;

    T val1 = static_cast<T>(4);
    T val2 = static_cast<T>(2);
    stack::Stack<T> stk_one;
    stack::Stack<T> stk_two;
};

using MyTypes = testing::Types<char, int, long long, float, double, bool>;

TYPED_TEST_SUITE(StackTest, MyTypes);

TYPED_TEST(StackTest, IsEmpty)
{
    EXPECT_TRUE(this->stk_one.is_empty());
    EXPECT_TRUE(this->stk_two.is_empty());
}

TYPED_TEST(StackTest, StackPush)
{
    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        this->stk_one.push(this->val1);
        this->stk_two.push(this->val2);
        EXPECT_TRUE(this->stk_one.top() == this->val1);
        EXPECT_TRUE(this->stk_two.top() == this->val2);
    }
}

TYPED_TEST(StackTest, StackPop)
{
    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        this->stk_one.push(this->val1);
        this->stk_one.push(this->val2);

        auto new_val1 = this->stk_one.top();
        this->stk_one.pop();
        auto new_val2 = this->stk_one.top();

        EXPECT_TRUE((new_val1 == this->val2) && (new_val2 == this->val1));
    }
}

TYPED_TEST(StackTest, OperatorEqual)
{
    EXPECT_TRUE(this->stk_one == this->stk_two);

    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        this->stk_one.push(i);
        this->stk_two.push(i);
    }
    EXPECT_TRUE(this->stk_one == this->stk_two);
}

TYPED_TEST(StackTest, OperatorNotEqual)
{
    EXPECT_FALSE(this->stk_one != this->stk_two);

    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        this->stk_one.push(i);
        this->stk_two.push(this->val2);
    }
    EXPECT_TRUE(this->stk_one != this->stk_two);
}

TYPED_TEST(StackTest, OperatorAssign)
{
    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        this->stk_one.push(this->val1);
        this->stk_two.push(this->val2);
    }

    this->stk_two = this->stk_one;

    EXPECT_TRUE(this->stk_one == this->stk_two);

    this->stk_two.pop();

    this->stk_one = this->stk_two;

    EXPECT_TRUE(this->stk_two == this->stk_one);
}

TYPED_TEST(StackTest, DefaultCtor)
{
    EXPECT_TRUE(this->stk_one.is_empty());
    EXPECT_TRUE(this->stk_one.capacity() == this->stk_one.CAPACITY);
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
        this->stk_one.push(i);
    }

    using T = typename TestFixture::MyType;
    stack::Stack<T> new_stk(this->stk_one);

    EXPECT_TRUE(new_stk == this->stk_one);
}

TYPED_TEST(StackTest, MoveCtor)
{
    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        this->stk_one.push(i);
    }

    this->stk_two = this->stk_one;

    using T = typename TestFixture::MyType;
    stack::Stack<T> new_stk(std::move(this->stk_one));

    EXPECT_TRUE(this->stk_one.size() == 0);
    EXPECT_TRUE(new_stk == this->stk_two);
}

TYPED_TEST(StackTest, StackSwap)
{
    for (size_t i = 0; i < this->TEST_SIZE; ++i)
    {
        this->stk_one.push(this->val1);
        this->stk_two.push(this->val2);
    }

    using T = typename TestFixture::MyType;
    stack::Stack<T> temp_stk1 = this->stk_one;
    stack::Stack<T> temp_stk2 = this->stk_two;

    this->stk_one.swap(this->stk_two);
    EXPECT_TRUE(this->stk_one == temp_stk2);
    EXPECT_TRUE(this->stk_two == temp_stk1);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

