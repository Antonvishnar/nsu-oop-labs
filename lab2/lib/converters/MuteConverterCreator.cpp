#include "MuteConverterCreator.h"

#include "../ConfigReader.h"


Converter* MuteConverterCreator::createConverter(const Command& command) {
    if (command.args.size != 2) throw std::invalid_argument("wrong number of arguments");
    
}
