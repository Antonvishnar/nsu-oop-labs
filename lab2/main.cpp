#include <iostream>
#include <string>
#include <vector>

#include "lib/core/ConfigReader.h"
#include "lib/core/SoundProcessor.h"

int main(int argc, char* argv[]) {

    if (argc < 4) {
        std::cerr << "Files: config.txt output.wav input1.wav [input2.wav ...]\n";
        return 1;
    }

    const std::string configFile = argv[1];
    const std::string outputFile = argv[2];

    std::vector<std::string> inputFiles;
    for (int i = 3; i < argc; ++i) {
        inputFiles.emplace_back(argv[i]);
    }

    try {
        ConfigReader configReader(configFile);
        SoundProcessor processor(outputFile, inputFiles);
        while (auto command = configReader.ReadNextCommand()) {
            processor.ExecCommand(command.value());
        }
        processor.WriteOutput();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
