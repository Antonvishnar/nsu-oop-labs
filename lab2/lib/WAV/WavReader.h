//
// Created by anton on 17.10.2026.
//

#ifndef OOP_NSU_LABS_WAVREADER_H
#define OOP_NSU_LABS_WAVREADER_H
#include <fstream>
#include <string>
#include <vector>
#include "WavHeader.h"

class WavReader{
public:
    static const int BITS = 16;
    static const int SAMPLE_RATE = 44100;

    WavReader(const std::string& filepath);
    bool readNextSamples(std::vector<int16_t>& buffer, double deltaTime = 1.0);

    const WavHeader& getHeader() const {return header_;}

private:
    std::ifstream file_;
    std::string filepath_;
    WavHeader header_{};
    uint32_t remainingDataBytes_ = 0;

    void parseHeader_();
};


#endif //OOP_NSU_LABS_WAVREADER_H
