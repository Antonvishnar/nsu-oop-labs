//
// Created by anton on 19.10.2026.
//

#include "List.h"

List::List() : size_(0), head_(nullptr) {

}

List::~List() {
    while (head_ != nullptr) {
        ListNode* next = head_->next;
        delete head_;
        head_ = next;
    }
}

std::size_t List::size() const {
    return size_;
}

void List::add(const std::size_t &index, const std::string &value) {

    if (index == 0) {
        head_ = new ListNode{value, head_};
        ++size_;
        return;
    }

    if (index <= size_) {
        ListNode* curr = head_;
        for (std::size_t i = 0; i < index - 1; ++i) {
            curr = curr->next;
        }
        curr->next = new ListNode{value, curr->next};
        ++size_;
        return;
    }

    if (head_ == nullptr) {
        head_ = new ListNode{"", nullptr};
        ++size_;
    }

    ListNode* curr = head_;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    while (size_ < index) {
        curr->next = new ListNode{"", nullptr};
        curr = curr->next;
        ++size_;
    }

    curr->next = new ListNode{value, nullptr};
    ++size_;
}
