//
// Created by anton on 15.10.2026.
//

#ifndef OOP_NSU_LABS_CONVERTER_H
#define OOP_NSU_LABS_CONVERTER_H

#include<vector>
#include<cstdint>

class Converter {
public:
    virtual ~Converter() = default;
    virtual void convert(std::vector<std::vector<int16_t>>& samples) = 0;
};
#endif //OOP_NSU_LABS_CONVERTER_H
