#ifndef OOP_NSU_LABS_CONVERTERCREATOR_H
#define OOP_NSU_LABS_CONVERTERCREATOR_H
#include "Converter.h"

struct Command;

class ConverterCreator {
public:
    virtual ~ConverterCreator() = default;
    virtual Converter* createConverter(const Command& command) = 0;
};
#endif //OOP_NSU_LABS_CONVERTERCREATOR_H
