#include "ConfigReader.h"
#include <sstream>
#include <stdexcept>

ConfigReader::ConfigReader(const std::string& filepath) {
    file_.open(filepath);
    if (!file_.is_open()) {
        throw std::runtime_error("Cannot open config file");
    }
}

std::optional<Command> ConfigReader::ReadNextCommand() {
    std::string line;
    while (std::getline(file_, line)) {
        auto command = parseLineIntoCommand(line);
        if (command) {
            return command;
        }
    }
    return std::nullopt;
}

std::optional<Command> ConfigReader::parseLineIntoCommand(const std::string& line) {
    std::istringstream iss(line);
    Command command;
    iss >> command.name;
    if (command.name.empty() || command.name[0] == '#') return std::nullopt;
    std::string arg;
    while (iss >> arg) {
        if (arg[0] == '#') break;
        command.args.push_back(arg);
    }
    return command;
}