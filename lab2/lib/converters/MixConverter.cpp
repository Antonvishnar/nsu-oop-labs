//
// Created by anton on 02.11.2026.
//

#include "MixConverter.h"

void MixConverter::convert(std::vector<std::vector<int16_t>>& samples) {
	if (samples.size() < 2) {
		return;
	}

	for (std::size_t i = 0; i < samples[0].size() && i < samples[1].size(); ++i) {
		samples[0][i] = (samples[0][i] + samples[1][i]) / 2;
	}
}


