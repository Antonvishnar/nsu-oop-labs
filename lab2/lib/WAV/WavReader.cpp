//
// Created by anton on 17.10.2026.
//

#include "WavReader.h"
#include <stdexcept>

WavReader::WavReader(const std::string& filepath)
    : file_(filepath, std::ios::binary), filepath_(filepath)
{
    if (!file_.is_open()) {
        throw std::runtime_error("Cannot open WAV file " + filepath);
    }
    parseHeader_();
}

void WavReader::parseHeader_() {
    file_.read(reinterpret_cast<char*>(&header_), sizeof(WavHeader));

    if (std::string(header_.riff, 4) != "RIFF") {
        throw std::runtime_error(filepath_ + ": missing 'RIFF' marker");
    }
    if (std::string(header_.wave, 4) != "WAVE") {
        throw std::runtime_error(filepath_ + ": missing 'WAVE' marker");
    }
    if (std::string(header_.fmt_chunk_marker, 4) != "fmt ") {
        throw std::runtime_error(filepath_ + ": missing 'fmt ' marker");
    }

    //Skip chunks until "data"
    while (std::string(header_.data_chunk_header, 4) != "data") {
        file_.seekg(header_.data_size + header_.data_size % 2, std::ios::cur);
        file_.read(header_.data_chunk_header, sizeof(header_.data_chunk_header));
        file_.read(reinterpret_cast<char*>(&header_.data_size), sizeof(header_.data_size));
        if (!file_) {
            throw std::runtime_error(filepath_ + ": missing 'data' marker");
        }
    }
    remainingDataBytes_ = header_.data_size;

    if (header_.format_type != 1) {
        throw std::runtime_error(filepath_ + ": only uncompressed PCM is supported");
    }
    if (header_.channels != 1) {
        throw std::runtime_error(filepath_ + ": only mono is supported");
    }
    if (header_.sample_rate != SAMPLE_RATE) {
        throw std::runtime_error(filepath_ + ": only 44100 sample rate is supported");
    }
    if (header_.bits_per_sample != BITS) {
        throw std::runtime_error(filepath_ + ": only 16 bit audio is supported");
    }
}

bool WavReader::readNextSamples(std::vector<int16_t>& buffer, double deltaTime) {
    if (deltaTime <= 0) {
        throw std::invalid_argument("Read duration must be >0");
    }
    if (remainingDataBytes_ == 0) {
        buffer.clear();
        return false;
    }
    std::size_t samplesWanted = SAMPLE_RATE * deltaTime;
    std::size_t samplesAvailable = remainingDataBytes_ / sizeof(int16_t);
    std::size_t samplesToRead = std::min(samplesWanted, samplesAvailable);

    buffer.resize(samplesToRead);
    file_.read(reinterpret_cast<char*>(buffer.data()), samplesToRead * sizeof(int16_t));

    remainingDataBytes_ -= samplesToRead* sizeof(int16_t);
    buffer.resize(samplesToRead);

    return samplesToRead > 0;
}