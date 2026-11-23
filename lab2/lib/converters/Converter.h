//
// Created by anton on 15.10.2026.
//

#ifndef OOP_NSU_LABS_CONVERTER_H
#define OOP_NSU_LABS_CONVERTER_H

#include "SampleStream.h"

class Converter {
public:
    virtual ~Converter() = default;
    virtual void convert(SampleStream& stream) = 0;
};
#endif //OOP_NSU_LABS_CONVERTER_H
