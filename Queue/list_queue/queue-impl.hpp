#ifndef QUEUE_QUEUE_IMPL_H
#define QUEUE_QUEUE_IMPL_H

#include "queue.hpp"

#include <utility>

namespace queue_list 
{

template<typename T>
Queue<T>::Queue() : head_(nullptr), tail_(nullptr), size_(0) {}

template<typename T>
Queue<T>::Queue(size_t size, const T *data)
{
    head_ = new Node;
    Node *current = head_;

    for (size_t i = 0; i < size; i++)
    {
        current->elem = data[i];
        if (i < (size - 1))
        {
            current->next = new Node;
            current = current->next;
        }
    }
    tail_ = current;
    size_ = size;
}

template<typename T>
Queue<T>::Queue(const Queue &other) : Queue()
{
    size_ = other.size_;

    for (Node *ptr = other.head_->next; ptr != nullptr; ptr = ptr->next) 
    {
        push(ptr->value);
    }
}

template<typename T>
Queue<T>::Queue(Queue &&other) : Queue()
{
    this->swap(other);
}

template<typename T>
Queue<T>::~Queue()
{
    while (!is_empty()) 
    {
        pop();
    }

    delete head_;
}

template<typename T>
Queue<T> &Queue<T>::operator=(Queue other)
{
    this->swap(other);
    return *this;
}

template<typename T>
bool Queue<T>::operator==(const Queue &other) const
{
    if (size_ != other.size_)
    {
        return false;
    }
    if (is_empty())
    {
        return true;
    }

    Node *current = head_;
    Node *other_ptr = other.head_;

    while (other_ptr != other.tail_)
    {
        if (current->elem != other_ptr->elem)
        {
            return false;
        }
        current = current->next;
        other_ptr = other_ptr->next;
    }

    return (current->elem == other_ptr->elem);
}

template<typename T>
bool Queue<T>::operator!=(const Queue &other) const
{
    return !(*this == other);
}

template<typename T>
void Queue<T>::push(const T &value)
{
    if (is_empty())
    {
        head_ = tail_ = new Node;
    }
    else
    {
        tail_->next = new Node;
        tail_ = tail_->next;
    }
    tail_->elem = value;
    size_++;
}

template<typename T>
void Queue<T>::pop() 
{
    if (is_empty())
        return;

    Node* temp = head_->next;
    head_->next = head_->next->next;
    delete temp;
    size_--;
}

template<typename T>
const T &Queue<T>::front() const
{
    return head_->elem;
}

template<typename T>
T &Queue<T>::front()
{
    return head_->elem;
}

template<typename T>
const T &Queue<T>::back() const
{
    return tail_->elem;
}

template<typename T>
T &Queue<T>::back()
{
    return tail_->elem;
}

template<typename T>
void Queue<T>::swap(Queue &other) //verify 
{
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(size_, other.size_);
}

template<typename T>
size_t Queue<T>::size() const
{
    return size_;
}

template<typename T>
bool Queue<T>::is_empty() const
{
    return (size_ == 0);
}

} // namespace queue_list

#endif // QUEUE_QUEUE_IMPL_H