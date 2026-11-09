#ifndef OOP_NSU_LABS_CONFIGREADER_H
#define OOP_NSU_LABS_CONFIGREADER_H
#include <fstream>
#include <optional>
#include <string>
#include <vector>

struct Command {
    std::string name;
    std::vector<std::string> args;
};

class ConfigReader {
public:
    ConfigReader(const std::string& filepath);
    std::optional<Command> ReadNextCommand();
private:
    std::ifstream file_;

    static std::optional<Command> parseLineIntoCommand(const std::string& line);
};


#endif //OOP_NSU_LABS_CONFIGREADER_H
