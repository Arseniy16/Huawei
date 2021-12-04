#ifndef _INCLUDE_STACK_IMPL_HPP_
#define _INCLUDE_STACK_IMPL_HPP_

#include "stack.hpp"

#include <utility>

namespace stack
{

template <typename T>
Stack<T>::Stack()
{
    size_ = 0;
    capacity_ = CAPACITY;
    data_ = new T[capacity_];
}

template <typename T>
Stack<T>::Stack(size_t size)
{
    size_ = size;
    capacity_ = size;
    data_ = new T[size_];
}

template <typename T>
Stack<T>::Stack(size_t size, const T *data)
{
    size_ = size;
    capacity_ = size;
    data_ = new T[size_];

    for (size_t i = 0; i < size; ++i)
        data_[i] = data[i];
}

template <typename T>
Stack<T>::Stack(const Stack &other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new T[size_];

    for (size_t i = 0; i < size_; ++i)
        data_[i] = other.data_[i];
}

template <typename T>
Stack<T>::Stack(Stack &&other)
{
    size_ = other.size_;
    data_ = other.data_;
    capacity_ = other.capacity_;

    other.data_ = nullptr;
    other.size_ = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] data_;
}

template <typename T>
Stack<T> &Stack<T>::operator=(Stack other)
{
    this->swap(other);
    return *this;
}

template <typename T>
bool Stack<T>::operator==(const Stack &other) const
{
    if (size_ != other.size_)
    {
        return false;
    }

    for (size_t i = 0; i < size_; ++i)
    {
        if (data_[i] != other.data_[i])
        {
            return false;
        }
    }

    return true;
}

template <typename T>
bool Stack<T>::operator!=(const Stack &other) const
{
    return !(*this == other);
}

template <typename T>
void Stack<T>::push(const T value)
{
    if (size_ >= capacity_)
    {
        expand();
    }

    data_[size_++] = value;
}

template <typename T>
void Stack<T>::pop()
{
    size_--;
}

template <typename T>
T &Stack<T>::top()
{
    return data_[size_ - 1];
}

template <typename T>
const T &Stack<T>::top() const
{
    return data_[size_ - 1];
}

template <typename T>
size_t Stack<T>::size() const
{
    return size_;
}

template <typename T>
size_t Stack<T>::capacity() const
{
    return capacity_;
}

template <typename T>
bool Stack<T>::is_empty() const
{
    return (size_ == 0);
}

template <typename T>
void Stack<T>::swap(Stack &other)
{
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

template <typename T>
void Stack<T>::expand()
{
    capacity_ *= coef_expand_;

    T *new_data = new T[capacity_];

    std::move(data_, data_ + size_, new_data);

    delete[] data_;
    data_ = new_data;
}

template <typename T>
void Stack<T>::change_coef_expand(double coef_expand)
{
    coef_expand_ = coef_expand;
}

Stack<bool>::Stack()
{
    size_ = 0;
    capacity_ = CAPACITY;
    data_ = new unsigned char[capacity_ / 8 + 1];
}

Stack<bool>::Stack(size_t size)
{
    size_ = size;
    capacity_ = size;
    data_ = new unsigned char[size_ / 8 + 1];
}
Stack<bool>::Stack(size_t size, const bool *data)
{
    size_ = size;
    capacity_ = size;
    data_ = new unsigned char[size_ / 8 + 1];

    for (size_t i = 0; i < size; ++i)
    {
        if (data[i])
        {
            data_[i / 8] |= (1 << (i % 8));
        }
        else
        {
            data_[i / 8] &= ~(1 << (i % 8));
        }
    }
}

Stack<bool>::Stack(const Stack &other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new unsigned char[size_ / 8 + 1];

    for (size_t i = 0; i < (size_ / 8 + 1); ++i)
    {
        data_[i] = other.data_[i];
    }
}

Stack<bool>::Stack(Stack &&other)
{
    size_ = other.size_;
    data_ = other.data_;
    capacity_ = other.capacity_;

    other.data_ = nullptr;
    other.size_ = 0;
}

Stack<bool>::~Stack()
{
    delete[] data_;
}

Stack<bool> &Stack<bool>::operator=(Stack other)
{
    this->swap(other);
    return *this;
}

bool Stack<bool>::operator==(const Stack &other) const
{
    if (size_ != other.size_)
    {
        return false;
    }

    for (size_t i = 0; i < (size_ / 8); ++i)
    {
        if (data_[i] != other.data_[i])
        {
            return false;
        }
    }

    for (size_t i = 0; i < (size_ % 8); ++i)
    {
        if (((1 << (i % 8)) & data_[size_ / 8]) != ((1 << (i % 8)) & other.data_[size_ / 8]))
        {
            return false;
        }
    }

    return true;
}

bool Stack<bool>::operator!=(const Stack &other) const
{
    return !(*this == other);
}

void Stack<bool>::push(bool value)
{
    if (size_ >= capacity_)
    {
        expand();
    }

    if (value)
    {
        data_[size_ / 8] |= (1 << (size_ % 8));
    }
    else
    {
        data_[size_ / 8] &= ~(1 << (size_ % 8));
    }

    size_++;
}

void Stack<bool>::pop()
{
    size_--;
}

bool Stack<bool>::top() const
{
    return static_cast<bool>(data_[(size_ - 1) / 8] & (1 << ((size_ - 1) % 8)));
}

size_t Stack<bool>::size() const
{
    return size_;
}

size_t Stack<bool>::capacity() const
{
    return capacity_;
}

bool Stack<bool>::is_empty() const
{
    return (size_ == 0);
}

void Stack<bool>::swap(Stack &other)
{
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

void Stack<bool>::expand()
{
    capacity_ *= coef_expand_;

    auto *new_data = new unsigned char[capacity_ / 8 + 1];

    std::move(data_, data_ + (size_ / 8 + 1), new_data);

    delete[] data_;
    data_ = new_data;
}

} // namespace stack

#endif // _INCLUDE_STACK_IMPL_HPP_
