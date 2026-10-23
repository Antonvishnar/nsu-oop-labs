#include<iostream>
#include <memory>

#include "Array.h"

void printContainerSize(Container* container) {
    std::cout<<container->size()<<'\n';
}

int main() {
    std::unique_ptr<Array> arr = std::make_unique<Array>();
    arr->put(0, "150");
    arr->put(1, "200");

    for (int i = 1; i <= arr->size(); ++i) {
        std::cout<<arr->get(i)<<'\n';
    }

    printContainerSize(arr.get());

    return 0;
}
