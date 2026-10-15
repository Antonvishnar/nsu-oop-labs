//
// Created by anton on 15.10.2026.
//

#ifndef OOP_NSU_LABS_CONVERTERCREATOR_H
#define OOP_NSU_LABS_CONVERTERCREATOR_H
#include "Converter.h"

class ConverterCreator {
public:
    virtual ~ConverterCreator() = default;
    virtual Converter* createConverter() = 0;
};
#endif //OOP_NSU_LABS_CONVERTERCREATOR_H
