#ifndef OOP_NSU_LABS_ARRAY_H
#define OOP_NSU_LABS_ARRAY_H

#include "../Container.h"

template<typename T>
class Array : public Container{
public:
    Array();
    ~Array();
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
    T* data_;
    std::size_t size_;
};

template<typename T>
Array<T>::Array() : data_(nullptr), size_(0) {}

template<typename T>
Array<T>::~Array() {
    clear();
}

template<typename T>
Array<T>::Array(const Array<T> &other) : size_(other.size_), data_(nullptr) {
    if (size_ > 0) {
        data_ = new T[size_];
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this == &other) {
        return *this;
    }
    delete[] data_;
    data_ = nullptr;
    size_ = other.size_;
    if (size_ > 0) {
        data_ = new T[size_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
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
    for (size_t i = 0; i < size_; ++i) {
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
    if (data_) {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
    }
}

template<typename T>
void Array<T>::put(std::size_t index, const T& value) {
    if (index >= size_) {
        auto* new_data = new T[index + 1];
        for (std::size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        size_ = index + 1;
    }
    data_[index] = value;
}

template<typename T>
std::size_t Array<T>::size() const {
    return size_;
}

template<typename T>
T* Array<T>::begin(){
    return data_;
}

template<typename T>
T* Array<T>::end() {
    return data_ + size_;
}

template<typename T>
T Array<T>::get(std::size_t index) const{
    if (index >= size_) {
        return T{};
    }
    return data_[index];
}


#endif //OOP_NSU_LABS_ARRAY_H
