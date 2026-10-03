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

Array& Array::operator=(const Array &other) {
    if (this == &other) {
        return *this;
    }
    delete[] data_;
    data_ = nullptr;
    size_ = other.size_;
    if (size_ > 0) {
        data_ = new std::string[size_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

std::string &Array::operator[](size_t index) {
    return data_[index];
}

const std::string &Array::operator[](size_t index) const {
    return data_[index];
}

bool Array::operator==(const Array &other) const {
    if (size_ != other.size_) return false;
    for (size_t i = 0; i < size_; ++i) {
        if (data_[i] != other.data_[i]) return false;
    }
    return true;
}

bool Array::operator!=(const Array &other) const {
    return !(*this == other);
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

//Сравнение как отдельные функции
/*
bool operator==(const Array& array1, const Array& array2) {
    if (array1.size() != array2.size()) return false;
    for (std::size_t i = 0; i < array1.size(); ++i) {
        if (array1[i] != array2[i]) return false;
    }
    return true;
}

bool operator!=(const Array& array1, const Array& array2) {
    return !(array1 == array2);
}
*/

