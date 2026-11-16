//
// Created by anton on 15.10.2026.
//
#include "MuteConverter.h"
#include <cstdint>

void MuteConverter::convert(std::vector<std::vector<int16_t>>& samples) {
    for (auto& sample : samples[0]) {
        sample = 0;
    }
}
