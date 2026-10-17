//
// Created by anton on 15.10.2026.
//

#ifndef OOP_NSU_LABS_MUTECONVERTERCREATOR_H
#define OOP_NSU_LABS_MUTECONVERTERCREATOR_H
#include "ConverterCreator.h"

class MuteConverterCreator : public ConverterCreator{
public:
    Converter* createConverter(const Command& command) override;
};


#endif //OOP_NSU_LABS_MUTECONVERTERCREATOR_H
