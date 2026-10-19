//
// Created by anton on 17.10.2026.
//

#ifndef OOP_NSU_LABS_WAVREADER_H
#define OOP_NSU_LABS_WAVREADER_H
#include <fstream>
#include <string>
#include <vector>

class WavReader {
public:
    static const int bits = 16;
    static const int rate = 44100;

    WavReader(const std::string& filepath);

    std::vector<int16_t> readNextSamples(double deltaTime);
    std::vector<int16_t> readHeader();
private:
    std::ifstream file_;
};


#endif //OOP_NSU_LABS_WAVREADER_H
