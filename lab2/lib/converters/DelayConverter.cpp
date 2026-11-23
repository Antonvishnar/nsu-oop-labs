//
// Created by anton on 09.11.2026.
//

#include "DelayConverter.h"

void DelayConverter::convert(SampleStream& stream) {
    std::size_t offset = (delayMs_ * 44100) / 1000;
    if (offset >= stream.size()) return;

    for (std::size_t i = offset; i < stream.size(); ++i) {
        int16_t value = stream[i] + stream[i - offset] * delayVolume_;
        stream[i] = value;
    }
}
