#ifndef OOP_NSU_LABS_SOUNDPROCESSOR_H
#define OOP_NSU_LABS_SOUNDPROCESSOR_H
#include "ConfigReader.h"
#include "WavReader.h"


class SoundProcessor {
public:
    SoundProcessor();
    void ExecCommand();
    void ExecAllCommands();
private:
    std::size_t currentCommand_ = 0;
    std::vector<WavReader> reader_;
    ConfigReader configReader_;
};


#endif //OOP_NSU_LABS_SOUNDPROCESSOR_H
