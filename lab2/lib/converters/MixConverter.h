//
// Created by anton on 02.11.2026.
//

#ifndef OOP_NSU_LABS_MIXCONVERTER_H
#define OOP_NSU_LABS_MIXCONVERTER_H
#include <cstdint>
#include <vector>

#include "Converter.h"

class MixConverter : public Converter{
public:
    void convert(std::vector<std::vector<int16_t>>& samples) override;
};


#endif //OOP_NSU_LABS_MIXCONVERTER_H
