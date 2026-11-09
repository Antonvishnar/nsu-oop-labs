//
// Created by anton on 09.11.2026.
//

#include "DelayConverter.h"
#include <algorithm>

void DelayConverter::convert(std::vector<std::vector<int16_t>>& samples) {
    if (samples.empty()) return;
    auto& track = samples[0];

    std::size_t offset = (delayMs_ * 44100) / 1000;
    if (offset == 0 || offset >= track.size()) return;

    for (std::size_t i = offset; i < track.size(); ++i) {
        int16_t value = track[i] + track[i - offset] * delayVolume_;
        track[i] = value;
    }
}
