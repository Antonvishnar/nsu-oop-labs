//
// Created by anton on 19.10.2026.
//

#ifndef OOP_NSU_LABS_LIST_H
#define OOP_NSU_LABS_LIST_H
#include <cstddef>
#include "../Container.h"
#include "ListIterator.h"
#include "ListNode.h"

template <typename T>
class List : public Container {
public:
    List();
    ~List() override;
    std::size_t size() const override;
    void add(const std::size_t& index, const T& value);

    ListIterator<T> begin() {
        return ListIterator<T>{head_};
    }

    static ListIterator<T> end() {
        return ListIterator<T>{nullptr};
    }
private:
    std::size_t size_;
    ListNode<T>* head_;
};

template <typename T>
List<T>::List() : size_(0), head_(nullptr) {}

template <typename T>
List<T>::~List() {
    while (head_ != nullptr) {
        ListNode<T>* next = head_->next;
        delete head_;
        head_ = next;
    }
}

template <typename T>
std::size_t List<T>::size() const {
    return size_;
}

template <typename T>
void List<T>::add(const std::size_t &index, const T& value) {

    if (index == 0) {
        head_ = new ListNode<T>{value, head_};
        ++size_;
        return;
    }

    if (index <= size_) {
        ListNode<T>* curr = head_;
        for (std::size_t i = 0; i < index - 1; ++i) {
            curr = curr->next;
        }
        curr->next = new ListNode<T>{value, curr->next};
        ++size_;
        return;
    }

    if (head_ == nullptr) {
        head_ = new ListNode<T>{T{}, nullptr};
        ++size_;
    }

    ListNode<T>* curr = head_;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    while (size_ < index) {
        curr->next = new ListNode<T>{T{}, nullptr};
        curr = curr->next;
        ++size_;
    }

    curr->next = new ListNode<T>{value, nullptr};
    ++size_;
}



#endif //OOP_NSU_LABS_LIST_H
