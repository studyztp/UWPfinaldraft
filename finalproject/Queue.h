#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"

template<typename ITEM_TYPE>
class Queue
{
public:
    Queue();
    Queue(const Queue<ITEM_TYPE>& others);
    Queue& operator=(const Queue<ITEM_TYPE>& others);
    ~Queue();
    ITEM_TYPE operator[](const int index) const;
    typename List<ITEM_TYPE>::Iterator front();
    ITEM_TYPE pop();
    void push(const ITEM_TYPE& item);
    bool empty() const;
    int length() const//Note:06/04/2020 implemented for tokenizer
    {
        return _count;
    }
    void clear()//Note:06/04/2020 implemented for tokenizer
    {
        _count = 0;
        _queue.clear_list();
        _rear = _queue.listBegin();
    }
    void print() const;
    friend ostream& operator<<(ostream& outs, const Queue & item)
    {
        outs<< item._queue;
        return outs;
    }
private:
    List<ITEM_TYPE> _queue;
    typename List<ITEM_TYPE>::Iterator _rear;
    int _count;
};
template<typename ITEM_TYPE>
Queue<ITEM_TYPE>::Queue()
{
    _rear = _queue.listBegin();
    _count = 0;
}
template<typename ITEM_TYPE>
Queue<ITEM_TYPE>::Queue(const Queue<ITEM_TYPE>& others)
{
    if(this != &others)
    {
        _queue = others._queue;
        _rear = _queue.listBegin();
        _count = others._count;
    }
}
template<typename ITEM_TYPE>
Queue<ITEM_TYPE>& Queue<ITEM_TYPE>::operator=(const Queue<ITEM_TYPE>& others)
{
    if(this != &others)
    {
        _queue = others._queue;
        _rear = _queue.listBegin();
        _count = others._count;
    }
}
template<typename ITEM_TYPE>
Queue<ITEM_TYPE>::~Queue()
{

}
template<typename ITEM_TYPE>
ITEM_TYPE Queue<ITEM_TYPE>:: operator[](const int index) const
{
    return _queue[index];
}
template<typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator Queue<ITEM_TYPE>:: front()
{
    return _queue.listBegin();
}
template<typename ITEM_TYPE>
ITEM_TYPE Queue<ITEM_TYPE>::pop()
{
    if(!empty())
    {
        _count--;
        return _queue.listDeleteNode(front());
    }
    _rear = NULL;
    return ITEM_TYPE();
}
template<typename ITEM_TYPE>
void Queue<ITEM_TYPE>::push(const ITEM_TYPE& item)
{
    if(!empty())
        _rear = _queue.listInsertAfter(_rear,item);
    else
        _rear = _queue.listInsertHead(item);
    _count ++;
}
template<typename ITEM_TYPE>
bool Queue<ITEM_TYPE>:: empty() const
{
    if(_count ==0)
        return true;
    else
        return false;
}
template<typename ITEM_TYPE>
void Queue<ITEM_TYPE>::print() const
{
    _queue.listPrint();
}
#endif // QUEUE_H
