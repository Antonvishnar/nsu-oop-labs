//
// Created by anton on 02.11.2026.
//

#include "MixConverter.h"
#include <algorithm>
#include <utility>


MixConverter::MixConverter(const SampleStream& secondStream)
	: secondStream_(secondStream) {}

void MixConverter::convert(SampleStream& stream) {

	std::size_t count = std::min(stream.size(),  secondStream_.size());

	for (std::size_t i = 0; i < count; ++i) {
		stream[i] = (stream[i] + secondStream_[i]) / 2;
	}
}


