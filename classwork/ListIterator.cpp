//
// Created by anton on 02.11.2026.
//

#include "ListIterator.h"

ListIterator::ListIterator(ListNode *node) : node_(node) {}

std::string& ListIterator::operator*() const {
    return node_->value;
}

ListIterator& ListIterator::operator++() {
    if (node_) {
        node_ = node_->next;
    }
    return *this;
}

bool ListIterator::operator!=(const ListIterator &other) const {
    return node_ != other.node_;
}

