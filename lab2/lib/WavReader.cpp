//
// Created by anton on 17.10.2026.
//

#include "WavReader.h"
#include <stdexcept>

WavReader::WavReader(const std::string& filepath)
    : file_(filepath)
{
    if (!file_.is_open()) {
        throw std::runtime_error("Cannot open WAV file " + filepath);
    }
    file_.seekg(44, std::ios::beg);
}

std::vector<int16_t> WavReader::readNextSamples(double deltaTime) {
    std::size_t numSamples = deltaTime * rate;
    std::vector<int16_t> newSamples(numSamples);
    file_.read(reinterpret_cast<char*>(newSamples.data()), numSamples * bits);

    std::streamsize bytesRead = file_.gcount();
    newSamples.resize(bytesRead / bits);
    return newSamples;
}
