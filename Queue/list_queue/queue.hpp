#ifndef _INCLUDE_QUEUE_HPP_
#define _INCLUDE_QUEUE_HPP_

#include <cstdlib>
#include <utility>

namespace queue 
{

template<typename T>
class Queue
{
public:
    Queue();
    // explicit Queue(size_t size);
    Queue(size_t size, const T *data);
    Queue(const Queue &other);
    Queue(Queue &&other);
    ~Queue();

    Queue &operator=(Queue other);

    bool operator==(const Queue &other) const;
    bool operator!=(const Queue &other) const;

    void push(const T &value);
    void pop();

    const T &front() const;
    const T &back() const;
    T &front();
    T &back();

    void swap(Queue &other);
    bool is_empty() const;
    size_t size() const;

private:
    size_t size_;

    struct Node
    {
        T elem;
        Node *next;
    };
    
    Node *head_, *tail_;
};

} // namespace queue_list

#endif // _INCLUDE_QUEUE_HPP_