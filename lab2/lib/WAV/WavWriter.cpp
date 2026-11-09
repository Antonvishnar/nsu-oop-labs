//
// Created by anton on 19.10.2026.
//

#include "WavWriter.h"
#include <stdexcept>

WavWriter::WavWriter(const std::string& filepath, const WavHeader& header)
    : file_(filepath, std::ios::binary | std::ios::trunc)
{
    if (!file_.is_open()) {
        throw std::runtime_error("Cannot create output WAV " + filepath);
    }
    file_.write(reinterpret_cast<const char*>(&header), sizeof(WavHeader));
}

void WavWriter::writeSamples(const std::vector<int16_t>& buffer) {
    file_.write(reinterpret_cast<const char*>(buffer.data()), buffer.size() * sizeof(int16_t));
}
