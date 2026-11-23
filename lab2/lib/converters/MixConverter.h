//
// Created by anton on 02.11.2026.
//

#ifndef OOP_NSU_LABS_MIXCONVERTER_H
#define OOP_NSU_LABS_MIXCONVERTER_H

#include "Converter.h"

class MixConverter : public Converter{
public:
    MixConverter(const SampleStream& secondStream);
    void convert(SampleStream& stream) override;
private:
    const SampleStream& secondStream_;
};


#endif //OOP_NSU_LABS_MIXCONVERTER_H
