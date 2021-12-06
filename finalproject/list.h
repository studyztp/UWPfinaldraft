#ifndef LIST_H
#define LIST_H
#include "node.h"
/*
 * Linked List Class with only two insert function: inserthead and insertafter
 * Iterator well set
*/
template <typename ITEM_TYPE>
class List
{
public:
    class Iterator{
    public:
        friend class List;
        Iterator(){
            _ptr = nullptr;
        }
        Iterator& operator=(const Iterator& it)
        {
            if(this != &it)
                _ptr = it._ptr;
            return *this;
        }
        Iterator(node<ITEM_TYPE>* ptr)
        {
            _ptr = ptr;
        }
        ITEM_TYPE& operator*()                                               //return item
        {
            return _ptr->_item;
        }
        const ITEM_TYPE operator*() const                                   //const version
        {
            ITEM_TYPE temp = _ptr->_item;
            return temp;
        }
        ITEM_TYPE* &operator->()                                             //return address of item
        {
            return &(_ptr->_item);
        }
        const ITEM_TYPE* operator->()const                                  //const version
        {
            return &(_ptr->_item);
        }
        friend bool operator!=(const Iterator& left, const node<ITEM_TYPE>& right)
        {
            if(left._ptr!=right)
                return true;
            return false;
        }
        friend bool operator==(const Iterator& left, const Iterator& right)//return true if
                                                                           //left==right
        {
            if(left._ptr==right._ptr)
                return true;
            return false;
        }
        friend bool operator!=(const Iterator& left, const Iterator& right)//return true if
                                                                           //left==right
        {
            if(left._ptr!=right._ptr)
                return true;
            return false;
        }
        friend bool is_null(const Iterator& theI)
        {
            if(theI._ptr == nullptr)
                return true;
            return false;
        }

        friend Iterator operator +(const Iterator& it, int index)
        {
            node<ITEM_TYPE>* temp = it._ptr;
            for(int i = 0; i < index; i++)
            {
                temp = temp->_next;
            }
            Iterator ptr(temp);
            return ptr;
        }

        Iterator& operator ++()                                             //profix
        {
            _ptr = _ptr->_next;
            return *this;
        }
        friend Iterator operator++(Iterator& it)                            //prefix
        {
            Iterator hold = it;
            it= it+1;
            return hold;
        }
        ~Iterator(){}
    private:
        node<ITEM_TYPE>* _ptr;
    };
    List();                                                               //defult constrtor
    List(bool order, bool unique);                                         //two argument
    List(const List<ITEM_TYPE> &others);                                  //big three
    List& operator =(const List<ITEM_TYPE> &others);
    ~List();

    void clear_list()//Note:06/04/2020 implement for tokenizer
    {
        _head_ptr = _clearList(_head_ptr);
    }
    Iterator listInsertAfter(Iterator thePlace,const ITEM_TYPE& item);    //insert after a given locaiton
    Iterator listInsertBefore(Iterator thePlace, const ITEM_TYPE& item);
    Iterator listInsertHead(const ITEM_TYPE& item);                       //insert after head-ptr
    Iterator ListInsertSort(const ITEM_TYPE& item);
    ITEM_TYPE listDeleteNode(Iterator thePlace);                          //delete node in given location
    Iterator listSearch(const ITEM_TYPE& key)const;                       //search and return the location of the given item in the list
                                                                          //return nullptr if not found
    Iterator listPrev(Iterator thePlace);
    const ITEM_TYPE& operator[](int index) const;                         //const version
    ITEM_TYPE& operator[](int index);                                     //return the item in the given index
    Iterator listBegin()const;                                            //return the head_ptr in Iterator
    Iterator listEnd()const;
    void listPrint() const;                                               //print function


    template<typename T>
    friend ostream& operator <<(ostream& outs, const List<T>& PrintList); //print function



private:
    node<ITEM_TYPE>* _head_ptr;
    bool _order;            //true:ascending, false:decending
    bool _unique;           //true:unique,false:dups are allowed
};
template<typename ITEM_TYPE>
List<ITEM_TYPE>::List()
{
    _head_ptr = nullptr;
    _order = false;
    _unique = false;
}
template<typename ITEM_TYPE>
List<ITEM_TYPE>::List(bool order, bool unique)
{
    _head_ptr = nullptr;
    _order = order;
    _unique = unique;
}
template<typename ITEM_TYPE>
List<ITEM_TYPE>::List(const List<ITEM_TYPE> &others)
{
    if(this != &others)
    {
        _head_ptr = _copyList(others._head_ptr);                           //copy list
        _order = others._order;
        _unique = others._unique;
    }
}
template<typename ITEM_TYPE>
List<ITEM_TYPE>& List<ITEM_TYPE>::operator =(const List<ITEM_TYPE> &others)
{
    if(this != &others)
    {
        bool debug = false;
        if(debug)
        {
            cout<<endl;
            //cout<<"other._head: "<<*others.listBegin();
            if(_head_ptr!= nullptr)
                cout<<endl<<"head:"<<*_head_ptr;
        }

        _head_ptr=_clearList(_head_ptr);
        _head_ptr = _copyList(others._head_ptr);                            //copy list
        _order = others._order;
        _unique = others._unique;
        if(debug)
        {
            cout<<endl;
            cout<<"new head:"<<*_head_ptr;
        }
    }
    return *this;
}
template<typename ITEM_TYPE>
List<ITEM_TYPE>::~List()
{
    _head_ptr = _clearList(_head_ptr);                                                  //clear list
}

template<typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::listInsertAfter(typename List<ITEM_TYPE>::Iterator thePlace,const ITEM_TYPE& item)
{
    return Iterator(_insertAfter(thePlace._ptr,item));
}
template<typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>:: listInsertBefore(Iterator thePlace, const ITEM_TYPE& item)
{
    return Iterator(_insertBefore(_head_ptr,thePlace._ptr,item));
}
template<typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::listInsertHead(const ITEM_TYPE& item)
{
    return Iterator(_insertHead(_head_ptr,item));
}
template<typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::ListInsertSort(const ITEM_TYPE& item)
{

    if(_unique)
        return Iterator(_insert_sort_unique(_head_ptr,item,_order));
    else
        return Iterator(_insert_sort_and_add(_head_ptr,item,_order));
}
template<typename ITEM_TYPE>
ITEM_TYPE List<ITEM_TYPE>::listDeleteNode(Iterator thePlace)
{
    return _deleteNode(_head_ptr,thePlace._ptr);
}

template<typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::listSearch(const ITEM_TYPE& key)const
{
    return Iterator(_searchList(_head_ptr,key));
}
template<typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::listPrev(Iterator thePlace)
{
    return _previousNode(_head_ptr,thePlace._ptr);
}
template<typename ITEM_TYPE>
const ITEM_TYPE& List<ITEM_TYPE>::operator[](int index) const
{
    return _at(_head_ptr,index);
}

template<typename ITEM_TYPE>
ITEM_TYPE& List<ITEM_TYPE>::operator[](int index)
{
    return _at(_head_ptr,index);
}
template<typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::listBegin()const
{
    return Iterator(_head_ptr);
}
template<typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::listEnd()const
{
    return Iterator(_lastNode(_head_ptr));
}

template<typename ITEM_TYPE>
void List<ITEM_TYPE>:: listPrint() const
{
    _printlist(_head_ptr);
}

template<typename T>
ostream& operator <<(ostream& outs, const List<T>& PrintList)
{
    outs << "[";
    typename List<T>:: Iterator w = PrintList.listBegin();
    for(w; !is_null(w); w = w+1)
    {
        outs<<" ";
        outs<<*w;
        outs<<" ";
    }
    outs<<"]";
    return  outs;
}
#endif // LIST_H
