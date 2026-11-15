//
// Created by anton on 04.11.2026.
//

#ifndef OOP_NSU_LABS_CONTAINERFACTORY_H
#define OOP_NSU_LABS_CONTAINERFACTORY_H
#include <memory>
#include <string>
#include "Container.h"
#include "array/Array.h"
#include "list/List.h"

template <typename T>
std::unique_ptr<Container> createContainer(const std::string& name) {
    if (name == "list") return std::make_unique<List<T>>();
    if (name == "array") return std::make_unique<Array<T>>();
    return nullptr;
}

#endif //OOP_NSU_LABS_CONTAINERFACTORY_H
