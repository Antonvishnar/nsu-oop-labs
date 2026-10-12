#include<iostream>

#include "Array.h"

int main() {

    Array arr;
    arr.put(1, "150");
    arr.put(2, "200");

    for (int i = 1; i <= arr.size(); ++i) {
        std::cout<<arr.get(i)<<'\n';
    }

    return 0;
}
