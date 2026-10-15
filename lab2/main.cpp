#include<iostream>

#include "lib/ConfigReader.h"

int main(int argc, char* argv[]) {

    ConfigReader configReader(argv[argc-1]);
    while (auto command = configReader.ReadNextLine()) {
        
    }

    std::cout<<"Hello!";

    return 0;
}
