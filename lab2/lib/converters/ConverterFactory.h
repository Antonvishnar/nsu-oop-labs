#ifndef OOP_NSU_LABS_CONVERTERFACTORY_H
#define OOP_NSU_LABS_CONVERTERFACTORY_H

#include <cstddef>
#include <memory>
#include <optional>
#include <vector>

#include "Converter.h"
#include "../core/ConfigReader.h"

struct ConverterAction {
	std::unique_ptr<Converter> converter;
	std::size_t startSecond;
	std::optional<std::size_t> endSecond;
};

ConverterAction createConverter(const Command& command, const std::vector<std::unique_ptr<SampleStream>>& streams);

#endif //OOP_NSU_LABS_CONVERTERFACTORY_H