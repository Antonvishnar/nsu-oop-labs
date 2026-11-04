//
// Created by anton on 04.11.2026.
//

#ifndef OOP_NSU_LABS_CONTAINERFACTORY_H
#define OOP_NSU_LABS_CONTAINERFACTORY_H
#include <memory>
#include <string>
#include "Container.h"

std::unique_ptr<Container> createContainer(const std::string& name);

#endif //OOP_NSU_LABS_CONTAINERFACTORY_H
