#ifndef OOP_NSU_LABS_SOUNDPROCESSOR_H
#define OOP_NSU_LABS_SOUNDPROCESSOR_H
#include <memory>

#include "ConfigReader.h"
#include "WavReader.h"
#include "WavWriter.h"
#include "converters/Converter.h"


class SoundProcessor {
public:
    SoundProcessor(
        const std::string& configFile,
        const std::string& outputFile,
        const std::vector<std::string>& wavFiles,
    ) : configReader_(configFile) {
        for (const auto& wavFile : wavFiles) {
            readers_.emplace_back(wavFile);
        }
    }

    void ExecAllCommands();
private:
    ConfigReader configReader_;
    std::vector<WavReader> readers_;
    std::vector<WavWriter> writers_;
    std::vector<std::unique_ptr<Converter>> converters_;
};


#endif //OOP_NSU_LABS_SOUNDPROCESSOR_H
