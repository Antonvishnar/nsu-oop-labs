//
// Created by anton on 15.10.2026.
//

#ifndef OOP_NSU_LABS_MUTECONVERTER_H
#define OOP_NSU_LABS_MUTECONVERTER_H
#include <vector>
#include "Converter.h"

class MuteConverter : public Converter{
public:
    void convert(std::vector<std::vector<int16_t>>& samples) override;
};


#endif //OOP_NSU_LABS_MUTECONVERTER_H
