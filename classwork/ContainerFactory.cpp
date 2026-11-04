//
// Created by anton on 02.11.2026.
//

#include <string>

#include "Container.h"
#include "array/Array.h"
#include "list/List.h"
#include "ContainerFactory.h"
#include <memory>

std::unique_ptr<Container> createContainer(const std::string& name) {
    if (name == "list") return std::make_unique<List>();
    if (name == "array") return std::make_unique<Array>();
    return nullptr;
}
