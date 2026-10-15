#include "ConfigReader.h"
#include <iostream>

ConfigReader::ConfigReader(const std::string &filepath) {
    file_.open(filepath);
}

std::optional<Command> ConfigReader::ReadNextLine() {
    try {
        std::string line;
        std::getline(file_, line);

        lineNumber_++;
        return std::nullopt;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return std::nullopt;
}
