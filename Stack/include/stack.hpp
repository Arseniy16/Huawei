#ifndef _INCLUDE_STACK_HPP_
#define _INCLUDE_STACK_HPP_

#include <cstdlib>

namespace stack
{

template <typename T>
class Stack
{
public:
    const size_t CAPACITY = 10;

    Stack();
    explicit Stack(size_t size);
    Stack(size_t size, const T *data);
    Stack(const Stack &other);
    Stack(Stack &&other);
    ~Stack();

    Stack &operator=(Stack other);

    bool operator==(const Stack &other) const;
    bool operator!=(const Stack &other) const;

    void push(const T value);
    void pop();
    T &top();
    const T &top() const;

    size_t size() const;
    size_t capacity() const;

    bool is_empty() const;

    void swap(Stack &other);

    void expand();

    void change_coef_expand(double coef_expand);

private:
    double coef_expand_ = 2;

    T *data_;
    size_t size_;
    size_t capacity_;
};

template <>
class Stack<bool>
{
public:
    const size_t CAPACITY = 16;

    Stack();
    explicit Stack(size_t size);
    Stack(size_t size, const bool *data);
    Stack(const Stack &other);
    Stack(Stack &&other);
    ~Stack();

    Stack &operator=(Stack other);

    bool operator==(const Stack &other) const;
    bool operator!=(const Stack &other) const;

    void push(const bool value);
    void pop();
    bool top() const;

    size_t size() const;
    size_t capacity() const;

    bool is_empty() const;

    void swap(Stack &other);

    void expand();

private:
    const double coef_expand_ = 2;
    
    unsigned char *data_;
    size_t size_;
    size_t capacity_;
};

} // namespace stack

#endif //_INCLUDE_STACK_HPP_