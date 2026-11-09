//
// Created by anton on 19.10.2026.
//

#ifndef OOP_NSU_LABS_WAVWRITER_H
#define OOP_NSU_LABS_WAVWRITER_H
#include <fstream>
#include <string>
#include <vector>
#include "WavHeader.h"

class WavWriter {
public:
    WavWriter(const std::string& filepath, const WavHeader& header);
    void writeSamples(const std::vector<int16_t>& samples);
private:
    std::ofstream file_;
};


#endif //OOP_NSU_LABS_WAVWRITER_H
