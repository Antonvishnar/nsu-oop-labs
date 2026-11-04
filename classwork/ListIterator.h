//
// Created by anton on 02.11.2026.
//

#ifndef OOP_NSU_LABS_LISTITERATOR_H
#define OOP_NSU_LABS_LISTITERATOR_H
#include <string>
#include "list/ListNode.h"

class ListIterator {
public:
    ListIterator(ListNode* node);
    std::string& operator*() const;
    ListIterator& operator++();
    bool operator!=(const ListIterator& other) const;
private:
    ListNode* node_ = nullptr;
};


#endif //OOP_NSU_LABS_LISTITERATOR_H
