#ifndef OOP_NSU_LABS_ARRAY_H
#define OOP_NSU_LABS_ARRAY_H

#include<string>

class Array {
public:
    Array();
    ~Array();

    std::size_t size() const;
    std::string get(std::size_t index) const;

    void clear();
    void put(std::size_t index, const std::string &value);

private:
    std::string* data_;
    std::size_t size_;
};


#endif //OOP_NSU_LABS_ARRAY_H
