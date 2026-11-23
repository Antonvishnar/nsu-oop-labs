#ifndef OOP_NSU_LABS_SOUNDPROCESSOR_H
#define OOP_NSU_LABS_SOUNDPROCESSOR_H

#include <string>
#include <memory>
#include <vector>

#include "ConfigReader.h"
#include "../converters/SampleStream.h"
#include "../WAV/WavReader.h"

class SoundProcessor {
public:
    SoundProcessor(const std::string& outputFile, const std::vector<std::string>& wavFiles);

    void ExecCommand(const Command& command);
    void WriteOutput() const;
private:
    std::string outputPath_;
    WavHeader outputHeader_{};
    std::vector<std::vector<int16_t>> inputSamples_;
    std::vector<std::unique_ptr<SampleStream>> inputStreams_;
    std::vector<int16_t> outputSamples_;
};


#endif //OOP_NSU_LABS_SOUNDPROCESSOR_H
