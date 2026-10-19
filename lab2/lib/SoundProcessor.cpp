//
// Created by anton on 17.10.2026.
//

#include "SoundProcessor.h"

void SoundProcessor::ExecCommand() {
    configReader_.ReadNextLine();
    
}

void SoundProcessor::ExecAllCommands() {
    while () {
        ExecCommand();
    }
}
