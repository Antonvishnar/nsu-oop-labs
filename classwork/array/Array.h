#ifndef OOP_NSU_LABS_ARRAY_H
#define OOP_NSU_LABS_ARRAY_H

#include "../Container.h"
#include <memory>
#include <utility>
#include <cstddef>

template<typename T>
class Array : public Container{
public:
    Array();
    Array(const Array& other);

    Array& operator=(const Array& other);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    bool operator==(const Array& other) const;
    bool operator!=(const Array& other) const;

    T get(std::size_t index) const;

    void clear();
    void put(std::size_t index, const T& value);

    std::size_t size() const override;

    T* begin();
    T* end();

private:
    std::unique_ptr<T[]> data_;
    std::size_t size_;
};

template<typename T>
Array<T>::Array() : data_(nullptr), size_(0) {}

template<typename T>
Array<T>::Array(const Array<T>& other) : data_(nullptr), size_(0) {
    if (other.size_ > 0) {
        auto temp_data = std::make_unique<T[]>(other.size_);
        for (std::size_t i = 0; i < other.size_; ++i) {
            temp_data[i] = other.data_[i];
        }
        data_ = std::move(temp_data);
        size_ = other.size_;
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this == &other) {
        return *this;
    }
    std::unique_ptr<T[]> temp_data;
    if (other.size_ > 0) {
        temp_data = std::make_unique<T[]>(other.size_);
        for (std::size_t i = 0; i < other.size_; ++i) {
            temp_data[i] = other.data_[i];
        }
    }
    data_ = std::move(temp_data);
    size_ = other.size_;
    return *this;
}

template<typename T>
T& Array<T>::operator[](size_t index) {
    return data_[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const {
    return data_[index];
}

template<typename T>
bool Array<T>::operator==(const Array<T>& other) const {
    if (size_ != other.size_) return false;
    for (std::size_t i = 0; i < size_; ++i) {
        if (data_[i] != other.data_[i]) return false;
    }
    return true;
}

template<typename T>
bool Array<T>::operator!=(const Array<T>& other) const {
    return !(*this == other);
}

template<typename T>
void Array<T>::clear() {
    data_.reset();
    size_ = 0;
}

template<typename T>
void Array<T>::put(std::size_t index, const T& value) {
    if (index >= size_) {
        const std::size_t new_size = index + 1;
        auto new_data = std::make_unique<T[]>(new_size);
        for (std::size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        new_data[index] = value;
        data_ = std::move(new_data);
        size_ = new_size;
    } else {
        T temp(value);
        data_[index] = std::move(temp);
    }
}

template<typename T>
std::size_t Array<T>::size() const {
    return size_;
}

template<typename T>
T* Array<T>::begin(){
    return data_.get();
}

template<typename T>
T* Array<T>::end() {
    return data_.get() + size_;
}

template<typename T>
T Array<T>::get(std::size_t index) const{
    if (index >= size_) {
        return T{};
    }
    return data_[index];
}


#endif //OOP_NSU_LABS_ARRAY_H
