#include "ConverterFactory.h"

#include "MixConverter.h"
#include "MuteConverter.h"
#include <stdexcept>

#include "DelayConverter.h"

ConverterAction createConverter(const Command& command) {
    if (command.name == "mute") {
        if (command.args.size() != 2) {
            throw std::invalid_argument("mute requires start and end times");
        }
        ConverterAction action;
        action.converter = std::make_unique<MuteConverter>();
        action.startSecond = std::stoul(command.args[0]);
        action.endSecond = std::stoul(command.args[1]);
        if (action.endSecond < action.startSecond) {
            throw std::invalid_argument("mute end time must be after start time");
        }
        action.inputIndex = std::nullopt;
        return action;
    }
    if (command.name == "mix") {
        if (command.args.size() != 2 || command.args[0].size() < 2 || command.args[0][0] != '$') {
            throw std::invalid_argument("mix requires another input and start time");
        }
        ConverterAction action;
        action.converter = std::make_unique<MixConverter>();
        action.startSecond = std::stoul(command.args[1]);
        action.endSecond = std::nullopt;
        const std::size_t inputNumber = std::stoul(command.args[0].substr(1));
        if (inputNumber == 0) {
            throw std::invalid_argument("mix input number must start from 1");
        }
        action.inputIndex = inputNumber - 1;
        return action;
    }
    if (command.name == "delay") {
        if (command.args.size() != 4) {
            throw std::invalid_argument("delay requires start, end, delayMs and delayVolume");
        }
        ConverterAction action;
        action.startSecond = std::stoul(command.args[0]);
        action.endSecond = std::stoul(command.args[1]);
        const std::size_t delayMs = std::stoul(command.args[2]);
        const double delayVolume = std::stod(command.args[3]);
        if (action.endSecond < action.startSecond || delayMs == 0 || delayVolume < 0 || delayVolume > 1) {
            throw std::invalid_argument("Invalid delay parameters");
        }
        action.converter = std::make_unique<DelayConverter>(delayMs, delayVolume);
        action.inputIndex = std::nullopt;
        return action;
    }
    throw std::invalid_argument("Unknown converter: " + command.name);
}
