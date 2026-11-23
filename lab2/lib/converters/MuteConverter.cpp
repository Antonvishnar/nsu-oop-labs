//
// Created by anton on 15.10.2026.
//
#include "MuteConverter.h"

#include <algorithm>
#include "../core/SampleStream.h"

void MuteConverter::convert(SampleStream& stream) {
    for (std::size_t i = 0; i < stream.size(); ++i) {
        stream[i] = 0;
    }
}
