#include "ConverterFactory.h"

#include "MixConverter.h"
#include "MuteConverter.h"
#include <stdexcept>
#include <vector>

#include "DelayConverter.h"

ConverterAction createConverter(const Command& command, const std::vector<std::unique_ptr<SampleStream>>& streams) {
    if (command.name == "mute") {
        if (command.args.size() != 2) {
            throw std::invalid_argument("mute requires start and end times");
        }
        ConverterAction action;
        action.startSecond = std::stoul(command.args[0]);
        action.endSecond = std::stoul(command.args[1]);
        if (action.endSecond < action.startSecond) {
            throw std::invalid_argument("end time < start time");
        }
        action.converter = std::make_unique<MuteConverter>();
        return action;
    }
    if (command.name == "mix") {
        if (command.args.size() != 2 || command.args[0].size() < 2 || command.args[0][0] != '$') {
            throw std::invalid_argument("mix requires another input and start time");
        }
        std::size_t inputNumber = std::stoul(command.args[0].substr(1));
        ConverterAction action;
        action.converter = std::make_unique<MixConverter>(*streams[inputNumber - 1]);
        action.startSecond = std::stoul(command.args[1]);
        action.endSecond = std::nullopt;

        return action;
    }
    if (command.name == "delay") {
        if (command.args.size() != 4) {
            throw std::invalid_argument("delay requires start, end, delayMs and delayVolume");
        }
        ConverterAction action;
        action.startSecond = std::stoul(command.args[0]);
        action.endSecond = std::stoul(command.args[1]);
        std::size_t delayMs = std::stoul(command.args[2]);
        double delayVolume = std::stod(command.args[3]);
        if (action.endSecond < action.startSecond || delayMs == 0 || delayVolume < 0 || delayVolume > 1) {
            throw std::invalid_argument("Invalid delay parameters");
        }
        action.converter = std::make_unique<DelayConverter>(delayMs, delayVolume);
        return action;
    }
    throw std::invalid_argument("Unknown converter: " + command.name);
}
