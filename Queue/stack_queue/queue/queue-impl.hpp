#ifndef _INCLUDE_QUEUE_QUEUE_IMPL_HPP
#define _INCLUDE_QUEUE_QUEUE_IMPL_HPP

#include "queue.hpp"

// #include <utility>
#include <algorithm>
// #include <iostream>

namespace queue
{

template<typename T>
Queue<T>::Queue() : left_stk_(0) {}

template<typename T>
Queue<T>::Queue(size_t size, const T *data): left_stk_(size, data) {}

template<typename T>
Queue<T>::Queue(Queue &&other)
{
    right_stk_(std::move(other.right_stk_));
    left_stk_(std::move(other.left_stk_));
}

template<typename T>
Queue<T>::~Queue() {}

template<typename T>
Queue<T> &Queue<T>::operator=(Queue other)
{
    this->swap(other);
    return *this;
}

template<typename T>
bool Queue<T>::operator==(const Queue &other) const
{
    return (right_stk_ == other.right_stk_) && (left_stk_ == other.left_stk_);
}

template<typename T>
bool Queue<T>::operator!=(const Queue &other) const
{
    return (right_stk_ != other.right_stk_) || (left_stk_ != other.left_stk_);
}

template<typename T>
void Queue<T>::push(const T &value)
{
    left_stk_.push(value);
}

template<typename T>
void Queue<T>::pop()
{
/*
    if (right_stk_.is_empty() && (left_stk_.size() == 1))
    {
        left_stk_.pop();
        return;
    }
*/
    move_data();
    if (right_stk_.is_empty()) return;
    right_stk_.pop();
}

template<typename T>
T &Queue<T>::front()
{
/*
    if (right_stk_.is_empty() && (left_stk_.size() == 1))
    {
        return left_stk_.top();
    }
*/
    move_data();
    return right_stk_.top();
}

template<typename T>
T &Queue<T>::back()
{
    return left_stk_.top();
}

template<typename T>
const T &Queue<T>::back() const
{
    return left_stk_.top();
}

template<typename T>
void Queue<T>::swap(Queue &other)
{
    std::swap(left_stk_, other.left_stk_);
    std::swap(right_stk_, other.right_stk_);
}
/*
template<typename T>
void Queue<T>::swap(Queue *other)
{
    Queue<T> temp = std::move(*this);
    *this = std::move(*other);
    *other = std::move(temp);
}
*/
template<typename T>
size_t Queue<T>::size() const
{
    return (right_stk_.size() + left_stk_.size());
}

template<typename T>
bool Queue<T>::is_empty() const
{
    return ((right_stk_.size() + left_stk_.size()) == 0);
}

template<typename T>
void Queue<T>::move_data()
{
    if (right_stk_.is_empty())
    {
        while(!left_stk_.is_empty())
        {
            right_stk_.push(left_stk_.top());
            left_stk_.pop();
        }
    }    
}

//----------------------------------------------------

Queue<bool>::Queue() : left_stk_(0) {}

Queue<bool>::Queue(size_t size, const bool *data) : left_stk_(size, data) {}

Queue<bool>::Queue(Queue &&other)
{
    right_stk_ = std::move(other.right_stk_);
    left_stk_ = std::move(other.left_stk_);
}

Queue<bool> &Queue<bool>::operator=(Queue other)
{
    this->swap(other);
    return *this;
}

bool Queue<bool>::operator==(const Queue &other) const
{
    return (right_stk_ == other.right_stk_) && (left_stk_ == other.left_stk_);
}

bool Queue<bool>::operator!=(const Queue &other) const
{
    return (right_stk_ != other.right_stk_) || (left_stk_ != other.left_stk_);
}

void Queue<bool>::push(bool value)
{
    left_stk_.push(value);
}

void Queue<bool>::pop()
{
/*    
    if (right_stk_.is_empty() && (left_stk_.size() == 1))
    {
        left_stk_.pop();
        return;
    }
*/
    move_data();
    if (right_stk_.is_empty()) return;
    right_stk_.pop();
}

bool Queue<bool>::front()
{
/*
    if (right_stk_.is_empty() && (left_stk_.size() == 1))
    {
        return left_stk_.top();
    }
*/
    move_data();
    return right_stk_.top();
}

bool Queue<bool>::back() const
{
    return left_stk_.top();
}

void Queue<bool>::swap(Queue &other)
{
    std::swap(left_stk_, other.left_stk_);
    std::swap(right_stk_, other.right_stk_);
}

size_t Queue<bool>::size() const
{
    return (right_stk_.size() + left_stk_.size());
}

bool Queue<bool>::is_empty() const
{
    return ((right_stk_.size() + left_stk_.size()) == 0);
}

void Queue<bool>::move_data()
{
    if (right_stk_.is_empty())
    {
        while(!left_stk_.is_empty())
        {
            right_stk_.push(left_stk_.top());
            left_stk_.pop();
        }
    }    
}

} // namespace queue

#endif // _INCLUDE_QUEUE_QUEUE_IMPL_HPP