#include "Array.h"

Array::Array() : data_(nullptr), size_(0) {}

Array::~Array() {
    clear();
}

Array::Array(const Array &other) : data_(nullptr), size_(other.size_){
    if (size_ > 0) {
        data_ = new std::string[size_];
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
}

std::size_t Array::size() const {
    return size_;
}

void Array::clear() {
    if (data_) {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
    }
}

void Array::put(std::size_t index, const std::string &value) {
    if (index >= size_) {
        auto* new_data = new std::string[index + 1];
        for (std::size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        size_ = index + 1;
    }
    data_[index] = value;
}

std::string Array::get(std::size_t index) const{
    if (index >= size_) {
        return "";
    }
    return data_[index];
}

