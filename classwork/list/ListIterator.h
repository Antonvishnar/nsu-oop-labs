//
// Created by anton on 02.11.2026.
//

#ifndef OOP_NSU_LABS_LISTITERATOR_H
#define OOP_NSU_LABS_LISTITERATOR_H

#include "ListNode.h"

template <typename T>
class ListIterator {
public:
    ListIterator(ListNode<T>* node) : node_(node){}
    T& operator*() const {return node_->value;}
    ListIterator& operator++() {
        if (node_) node_ = node_->next;
        return *this;
    };
    bool operator!=(const ListIterator& other) const {
        return node_ != other.node_;
    };
private:
    ListNode<T>* node_ = nullptr;
};

#endif //OOP_NSU_LABS_LISTITERATOR_H
