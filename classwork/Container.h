#ifndef OOP_NSU_LABS_CONTAINER_H
#define OOP_NSU_LABS_CONTAINER_H

class Container {
public:
    virtual ~Container() = default;
    virtual std::size_t size() const = 0;
};

#endif //OOP_NSU_LABS_CONTAINER_H
