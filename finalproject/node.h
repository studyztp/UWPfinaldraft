#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;


template <typename ITEM_TYPE>
struct node
{
    node();                                                             //default
    node<ITEM_TYPE>(ITEM_TYPE item, node<ITEM_TYPE>* next = nullptr);   //2 arugment constator

    node& operator=(const node others);                                 //let one=others

    template <typename T>
    friend std::ostream& operator <<(std::ostream& outs,                //output
                                const node<T> &printMe);
    ITEM_TYPE _item;
    node<ITEM_TYPE>* _next;
};
template<typename ITEM_TYPE>
node<ITEM_TYPE>::node()
{
    _item = ITEM_TYPE();
    _next = nullptr;
}

template<typename ITEM_TYPE>
node<ITEM_TYPE>::node(ITEM_TYPE item, node<ITEM_TYPE>* next)
{
    _item = item;
    _next = next;
}

template<typename ITEM_TYPE>
node<ITEM_TYPE>& node<ITEM_TYPE>:: operator=(const node<ITEM_TYPE> others)
{
    if(this != & others)
    {
        _item = others._item;
        _next = others._next;
    }
    return *this;
}
template <typename T>
ostream& operator <<(std::ostream& outs,
                            const node<T> &printMe)
{
    outs<< printMe._item;
    return outs;
}

//=========================================== extra operation functions:
template<typename ITEM_TYPE>
void _printlist(node<ITEM_TYPE>* head_ptr);

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _searchList(node<ITEM_TYPE>* head_ptr, ITEM_TYPE key);
template<typename ITEM_TYPE>
node<ITEM_TYPE>* _insertHead(node<ITEM_TYPE>* &head_ptr, const ITEM_TYPE& item);
template<typename ITEM_TYPE>
node<ITEM_TYPE>* _insertAfter(node<ITEM_TYPE>* &afterThis, const ITEM_TYPE&item);

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _insertBefore(node<ITEM_TYPE>* head_ptr,node<ITEM_TYPE>* &beforeThis, const ITEM_TYPE& item);

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _previousNode(node<ITEM_TYPE>* head_ptr, node<ITEM_TYPE>* prevToThis);

template<typename ITEM_TYPE>
ITEM_TYPE _deleteNode(node<ITEM_TYPE>*& head_ptr, node<ITEM_TYPE>* &deleteThis);

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _copyList(node<ITEM_TYPE>* head_ptr);

template<typename ITEM_TYPE>
ITEM_TYPE& _at(node<ITEM_TYPE>* head_ptr, int index);

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _lastNode(node<ITEM_TYPE>* head_ptr);

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _timesITEM(node<ITEM_TYPE>* head_ptr,const ITEM_TYPE& item);

//===========================================sorted list

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sort_unique(node<ITEM_TYPE>*& head_ptr, const ITEM_TYPE & item, bool order);

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sort_and_add(node<ITEM_TYPE>*& head_ptr, const ITEM_TYPE & item, bool order);

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _where_it_goes(node<ITEM_TYPE>* head_ptr, const ITEM_TYPE & item, bool order);

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _clearList(node<ITEM_TYPE>*& head_ptr);
//=============================================
template<typename ITEM_TYPE>
void _printlist(node<ITEM_TYPE>* head_ptr)
{
    cout<< "H ->";
    for(node<ITEM_TYPE>* w = head_ptr; w!= nullptr; w = w->_next)
    {
        cout<<"[";
        cout<<*w;
        cout<<"]->";
    }
    cout<<"|||";
}

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _searchList(node<ITEM_TYPE>* head_ptr, ITEM_TYPE key)
{
    for(node<ITEM_TYPE>* w = head_ptr; w != nullptr; w= w->_next)
    {
        if(w->_item==key)
            return w;
    }
    return nullptr;
}
template<typename ITEM_TYPE>
node<ITEM_TYPE>* _insertHead(node<ITEM_TYPE>* &head_ptr, const ITEM_TYPE& item)
{

    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(item,head_ptr);
    head_ptr = temp;
    return head_ptr;
}
template<typename ITEM_TYPE>
node<ITEM_TYPE>* _insertAfter(node<ITEM_TYPE>* &afterThis, const ITEM_TYPE& item)
{
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE> (item, afterThis->_next);
    afterThis->_next = temp;
    return temp;
}
template<typename ITEM_TYPE>
node<ITEM_TYPE>* _insertBefore(node<ITEM_TYPE>* head_ptr,node<ITEM_TYPE>* &beforeThis, const ITEM_TYPE& item)
{
    node<ITEM_TYPE>* temp;
    if(beforeThis !=head_ptr)
    {
        temp = new node<ITEM_TYPE>(item,beforeThis);
        node<ITEM_TYPE>* prev_to_beforeThis = _previousNode(head_ptr,beforeThis);
        prev_to_beforeThis->_next = temp;
    }
    else
    {
        temp = _insertHead(head_ptr,item);
    }
    return temp;
}
template<typename ITEM_TYPE>
node<ITEM_TYPE>* _previousNode(node<ITEM_TYPE>* head_ptr, node<ITEM_TYPE>* prevToThis)
{
    for(node<ITEM_TYPE>* w = head_ptr; w!=nullptr;w=w->_next)
    {
        if(w->_next == prevToThis)
            return w;
    }
    return nullptr;
}
template<typename ITEM_TYPE>
ITEM_TYPE _deleteNode(node<ITEM_TYPE>*& head_ptr, node<ITEM_TYPE>*& deleteThis)
{
    ITEM_TYPE temp = deleteThis->_item;

    if(deleteThis != head_ptr)
    {
        node<ITEM_TYPE>* prev_deleteThis = _previousNode(head_ptr,deleteThis);
        prev_deleteThis->_next = deleteThis->_next;
        delete deleteThis;
    }
    else {
        head_ptr=head_ptr->_next;
        delete deleteThis;
    }
    return temp;
}
template<typename ITEM_TYPE>
node<ITEM_TYPE>* _copyList(node<ITEM_TYPE>* head_ptr)
{

    node<ITEM_TYPE>* w = new node<ITEM_TYPE>;
    w = _insertHead(w,head_ptr->_item);
    node<ITEM_TYPE>* whead= w;
    head_ptr= head_ptr ->_next;
    for(head_ptr; head_ptr != nullptr; head_ptr = head_ptr->_next)
    {
        w = _insertAfter(w,head_ptr->_item);
    }
    w->_next = nullptr;
    return whead;
}
template<typename ITEM_TYPE>
ITEM_TYPE& _at(node<ITEM_TYPE>* head_ptr, int index)
{
    int i = 0;
    for(node<ITEM_TYPE>* w = head_ptr; w != nullptr; w = w->_next)
    {
        if(i == index)
            return w->_item;
        i ++;
    }
    return head_ptr->_item;
}

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _lastNode(node<ITEM_TYPE>* head_ptr)
{
    node<ITEM_TYPE>* w = head_ptr;
    for(w; w->_next!=nullptr&&w!=nullptr;w = w->_next)
    {}
    return w;
}

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _clearList(node<ITEM_TYPE>*& head_ptr)
{
    if(head_ptr != nullptr)
    {
        node<ITEM_TYPE>* next = head_ptr->_next;
        for(node<ITEM_TYPE>* w = head_ptr; w != nullptr;)
        {
            delete w;
            w = next;
            if(next != nullptr)
                next = next->_next;
        }
    }

    head_ptr = nullptr;
    return head_ptr;
}

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _timesITEM(node<ITEM_TYPE>* head_ptr,const ITEM_TYPE& item)
{
    node <ITEM_TYPE>* w = head_ptr;
    for(w; w!=nullptr;w= w->_next)
    {
        w->_item = w->_item*item;
    }
    return head_ptr;
}
//============================================================================
template<typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sort_unique(node<ITEM_TYPE>* &head_ptr, const ITEM_TYPE & item, bool order)
{
    if(_searchList(head_ptr,item)==nullptr)
    {
        node<ITEM_TYPE>* temp = _where_it_goes(head_ptr,item,order);

        if(temp!= head_ptr)
            _insertBefore(head_ptr,temp,item);
        else
            _insertHead(head_ptr,item);
        return temp;
    }
    return nullptr;
}

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sort_and_add(node<ITEM_TYPE>* &head_ptr, const ITEM_TYPE & item, bool order)
{

    if(_searchList(head_ptr,item)== nullptr)
    {
        node<ITEM_TYPE>* temp = _where_it_goes(head_ptr,item,order);

        if(temp!= head_ptr)
            _insertBefore(head_ptr,temp,item);
        else
            _insertHead(head_ptr,item);
        return temp;
    }
    else
    {
         node<ITEM_TYPE>* where_dup = _searchList(head_ptr,item);
         _deleteNode(head_ptr,where_dup);
         ITEM_TYPE newitem = item + item;
         return _insert_sort_and_add(head_ptr,newitem,order);

    }
}

template<typename ITEM_TYPE>
node<ITEM_TYPE>* _where_it_goes(node<ITEM_TYPE>* head_ptr, const ITEM_TYPE & item, bool order)
{
    node<ITEM_TYPE>* w = head_ptr;
    for(w;w!=nullptr;w=w->_next)
    {
        if(order)
        {
            if(item< w->_item)
                return w;
        }
        else
        {
            if(item>w->_item)
                return w;
        }
    }
    return nullptr;
}
#endif // NODE_H
