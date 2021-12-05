#ifndef _INCLUDE_QUEUE_QUEUE_HPP_
#define _INCLUDE_QUEUE_QUEUE_HPP_

#include "../stack/stack-impl.hpp"

namespace queue 
{

template<typename T>
class Queue
{
public:
    Queue();
    Queue(size_t size, const T *data);
    Queue(const Queue &other);
    Queue(Queue &&other);
    ~Queue();

    Queue &operator=(Queue other);

    bool operator==(const Queue &other) const;
    bool operator!=(const Queue &other) const;

    void push(const T &value);
    void pop();

    const T &back() const;
    T &back();
    T &front();

    void swap(Queue &other); //?+
    bool is_empty() const;
    size_t size() const;

private:
    void move_data();

    Stack<T> right_stk_;
    Stack<T> left_stk_;
};

template<>
class Queue<bool>
{
public:
    Queue();
    Queue(size_t size, const bool *data);
    Queue(const Queue &other);
    Queue(Queue &&other);
    ~Queue();

    Queue &operator=(Queue other);

    bool operator==(const Queue &other) const;
    bool operator!=(const Queue &other) const;

    void push(bool value); //?+
    void pop();

    bool front();
    bool back() const;

    void swap(Queue &other); //?+
    bool is_empty() const;
    size_t size() const;

private:
    void move_data();

    // stack::Stack<bool> right_stk_;
    Stack<bool> right_stk_;
    Stack<bool> left_stk_;
    // stack::Stack<bool> left_stk_;
};

} // namespace queue

#endif //_INCLUDE_QUEUE_QUEUE_HPP