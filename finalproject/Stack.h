#ifndef STACK_H
#define STACK_H
#include "list.h"

template<typename ITEM_TYPE>
class Stack
{
public:
    Stack();
    Stack(const Stack<ITEM_TYPE>&others);
    Stack& operator=(const Stack<ITEM_TYPE>& others);
    ~Stack();
    ITEM_TYPE operator[](const int index) const;
    typename List<ITEM_TYPE>::Iterator front();
    ITEM_TYPE pop();
    void push(const ITEM_TYPE& item);
    bool empty() const;
    void print() const;
    friend ostream& operator<<(ostream& outs, const Stack & item)
    {
        outs<< item._stack;
        return outs;
    }
private:
    List<ITEM_TYPE> _stack;
    int _size ;
};

template<typename ITEM_TYPE>
Stack<ITEM_TYPE>::Stack()
{
    _size = 0;
}

template<typename ITEM_TYPE>
Stack<ITEM_TYPE>::Stack(const Stack<ITEM_TYPE>& others)
{
    if(this!=&others)
    {
        _stack = others._stack;
        _size = others._size;
    }
}
template<typename ITEM_TYPE>
Stack<ITEM_TYPE>& Stack<ITEM_TYPE>::operator=(const Stack<ITEM_TYPE>& others)
{
    if(this!=&others)
    {
        _stack = others._stack;
        _size = others._size;
    }
    return *this;
}
template<typename ITEM_TYPE>
Stack<ITEM_TYPE>::~Stack()
{}
template<typename ITEM_TYPE>
ITEM_TYPE Stack<ITEM_TYPE>::operator[](const int index) const
{
    return _stack[index];
}
template<typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator Stack<ITEM_TYPE>:: front()
{
    return _stack.listBegin();
}
template<typename ITEM_TYPE>
ITEM_TYPE Stack<ITEM_TYPE>::pop()
{
    if(!empty())
    {
        ITEM_TYPE temp = _stack.listDeleteNode(front());
        _size --;
        return temp;
    }
    return ITEM_TYPE();
}
template<typename ITEM_TYPE>
void Stack<ITEM_TYPE>::push(const ITEM_TYPE& item)
{
    _stack.listInsertHead(item);
    _size++;
}
template<typename ITEM_TYPE>
bool Stack<ITEM_TYPE>::empty() const
{
    if(_size ==0)
    {
        return true;
    }
    return false;
}
template<typename ITEM_TYPE>
void Stack<ITEM_TYPE>::print() const
{
    _stack.listPrint();
}





#endif // STACK_H
