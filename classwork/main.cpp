#include<iostream>
#include <memory>

#include "ContainerFactory.h"
#include "array/Array.h"
#include "list/List.h"

void printContainerSize(Container* container) {
    std::cout<<container->size()<<'\n';
}

int main() {

    auto arr = createContainer("array");
    auto list = createContainer("list");

    printContainerSize(arr.get());
    printContainerSize(list.get());

    List list1;
    Array arr1;

    arr1.put(0, "100");
    arr1.put(1, "150");
    arr1.put(2, "200");
    arr1.put(3, "300");

    list1.add(0, "100");
    list1.add(1, "150");
    list1.add(2, "200");
    list1.add(3, "300");

    for (auto it = arr1.begin(); it != arr1.end(); ++it) {
        std::cout << *it <<'\n';
    }

    for (auto it = list1.begin(); it != list1.end(); ++it) {
        std::cout << *it <<'\n';
    }

    return 0;
}
