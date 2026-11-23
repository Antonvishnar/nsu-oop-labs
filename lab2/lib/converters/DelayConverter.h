//
// Created by anton on 09.11.2026.
//

#ifndef OOP_NSU_LABS_DELAYCONVERTER_H
#define OOP_NSU_LABS_DELAYCONVERTER_H
#include <cstddef>

#include "Converter.h"


class DelayConverter : public Converter{
public:
    DelayConverter(std::size_t delayMs, double delayVolume) : delayMs_(delayMs), delayVolume_(delayVolume) {}
    void convert(SampleStream& stream) override;
private:
    std::size_t delayMs_;
    double delayVolume_;
};


#endif //OOP_NSU_LABS_DELAYCONVERTER_H
