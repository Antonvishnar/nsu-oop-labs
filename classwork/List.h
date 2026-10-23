//
// Created by anton on 19.10.2026.
//

#ifndef OOP_NSU_LABS_LIST_H
#define OOP_NSU_LABS_LIST_H
#include <cstddef>
#include <string>

#include "Container.h"

struct ListNode {
    std::string value;
    ListNode* next;
};

class List : public Container {
public:
    List();
    ~List() override;
    std::size_t size() const override;
    void add(const std::size_t& index, const std::string& value);
private:
    std::size_t size_;
    ListNode* head_;
};


#endif //OOP_NSU_LABS_LIST_H
