//
// Created by anton on 17.10.2026.
//

#include "WavReader.h"
#include <stdexcept>

WavReader::WavReader(const std::string& filepath)
    : file_(filepath, std::ios::binary), filepath_(filepath)
{
    if (!file_.is_open()) {
        throw std::runtime_error("Cannot open file " + filepath);
    }
    parseHeader_();
}

void WavReader::parseHeader_() {
    file_.read(reinterpret_cast<char*>(&header_), sizeof(WavHeader));

    if (std::string(header_.riff, 4) != "RIFF") {
        throw std::runtime_error(filepath_ + ": no RIFF marker");
    }
    if (std::string(header_.wave, 4) != "WAVE") {
        throw std::runtime_error(filepath_ + ": no WAVE marker");
    }
    if (std::string(header_.fmt_chunk_marker, 4) != "fmt ") {
        throw std::runtime_error(filepath_ + ": no fmt marker");
    }

    //Skip chunks until "data"
    while (std::string(header_.data_chunk_header, 4) != "data") {
        file_.seekg(header_.data_size + header_.data_size % 2, std::ios::cur);
        file_.read(header_.data_chunk_header, sizeof(header_.data_chunk_header));
        file_.read(reinterpret_cast<char*>(&header_.data_size), sizeof(header_.data_size));
        if (!file_) {
            throw std::runtime_error(filepath_ + ": no data marker");
        }
    }
    remainingDataBytes_ = header_.data_size;

    if (header_.format_type != 1) {
        throw std::runtime_error(filepath_ + ": only uncompressed is supported");
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

    std::size_t samplesCnt = SAMPLE_RATE * deltaTime;
    std::size_t bytesToRead = std::min<std::size_t>(
        remainingDataBytes_, samplesCnt * sizeof(int16_t));

    if (bytesToRead == 0) {
        buffer.clear();
        return false;
    }

    buffer.resize(bytesToRead / sizeof(int16_t));
    file_.read(reinterpret_cast<char*>(buffer.data()), buffer.size() * sizeof(int16_t));

    std::size_t actualBytesRead = static_cast<std::size_t>(file_.gcount());
    buffer.resize(actualBytesRead / sizeof(int16_t));
    remainingDataBytes_ -= actualBytesRead;

    return !buffer.empty();
}