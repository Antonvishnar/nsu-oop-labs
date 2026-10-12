#ifndef OOP_NSU_LABS_CONTAINER_H
#define OOP_NSU_LABS_CONTAINER_H

class Container {
public:
    Container(std::size_t size): size_(size) {}
    Container() : Container(0) {}

    std::size_t size() const {return size_;};
protected:
    std::size_t size_;
};

#endif //OOP_NSU_LABS_CONTAINER_H
