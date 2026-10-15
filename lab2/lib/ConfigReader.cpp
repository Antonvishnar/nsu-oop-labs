#include "ConfigReader.h"
#include <iostream>

ConfigReader::ConfigReader(const std::string &filepath) {
    file_.open(filepath);
    if (!file_.is_open()) {
        throw std::runtime_error("Cannot open config file");
    }
}

std::optional<Command> ConfigReader::ReadNextLine() {
    try {
        std::string line;
        std::getline(file_, line);

        lineNumber_++;
        return std::nullopt;
    } catch (std::exception &e) {
        std::cout<<lineNumber_<<'\n';
        std::cerr << e.what() << '\n';
    }
    return std::nullopt;
}

