#include "ConfigReader.h"
#include <iostream>

ConfigReader::ConfigReader(const std::string& filepath) {
    file_.open(filepath);
    if (!file_.is_open()) {
        throw std::runtime_error("Cannot open config file");
    }
}

std::optional<Command> ConfigReader::ReadNextLine() {
    try {
        std::string line;
        std::getline(file_, line);
        Command command = parseLineIntoCommand(line);
        lineNumber_++;
        return command;
    } catch (std::exception& e) {
        std::cout<<lineNumber_<<'\n';
        std::cerr << e.what() << '\n';
    }
    return std::nullopt;
}

Command ConfigReader::parseLineIntoCommand(const std::string& line) {
    Command command;
    std::size_t arg = 0;
    for (std::size_t i = 0; i < line.length(); ++i) {
        if (line[i] == ' ') continue;
        if (command.name.empty()) {
            while (line[i] != ' ') {
                command.name.push_back(line[i]);
                ++i;
            }
        }
        while (line[i] != ' ') {
            command.args[i].push_back(line[i]);
            ++i;
        }
    }
    return command;
}



