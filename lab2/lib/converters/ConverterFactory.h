#ifndef OOP_NSU_LABS_CONVERTERFACTORY_H
#define OOP_NSU_LABS_CONVERTERFACTORY_H

#include <cstddef>
#include <memory>
#include <optional>

#include "Converter.h"
#include "../core/ConfigReader.h"

struct ConverterAction {
	std::unique_ptr<Converter> converter;
	std::size_t startSecond;
	std::optional<std::size_t> endSecond;
	std::optional<std::size_t> inputIndex;
};

ConverterAction createConverter(const Command& command);

#endif //OOP_NSU_LABS_CONVERTERFACTORY_H