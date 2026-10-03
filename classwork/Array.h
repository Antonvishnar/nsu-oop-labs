#ifndef OOP_NSU_LABS_ARRAY_H
#define OOP_NSU_LABS_ARRAY_H

#include<string>

class Array {
public:
    Array();
    ~Array();
    Array(const Array &other);

    Array& operator=(const Array &other);
    std::string& operator[](size_t index);
    const std::string& operator[](size_t index) const;
    bool operator==(const Array &other) const;
    bool operator!=(const Array &other) const;

    std::size_t size() const;
    std::string get(std::size_t index) const;

    void clear();
    void put(std::size_t index, const std::string &value);

private:
    std::string* data_;
    std::size_t size_;
};

//Сравнение как отдельные функции
/*
bool operator==(const Array &array1, const Array &array2);
bool operator!=(const Array &array1, const Array &array2);
*/


#endif //OOP_NSU_LABS_ARRAY_H
