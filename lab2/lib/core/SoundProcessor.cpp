//
// Created by anton on 17.10.2026.
//

#include "SoundProcessor.h"
#include "../WAV/WavWriter.h"
#include "../converters/ConverterFactory.h"
#include <algorithm>
#include <utility>

SoundProcessor::SoundProcessor(const std::string& outputFile, const std::vector<std::string>& wavFiles)
	: outputPath_(outputFile) {
	for (const std::string& path : wavFiles) {
		WavReader reader(path);
		if (inputSamples_.empty()) {
			outputHeader_ = reader.getHeader();
		}
		std::vector<int16_t> fileSamples;
		std::vector<int16_t> chunk;
		while (reader.readNextSamples(chunk)) {
			fileSamples.insert(fileSamples.end(), chunk.begin(), chunk.end());
		}
		inputSamples_.push_back(fileSamples);
	}
	outputSamples_ = inputSamples_[0];
}

void SoundProcessor::ExecCommand(const Command& command) {
	auto action = createConverter(command);

	std::size_t totalOutput = outputSamples_.size();
	std::size_t start = action.startSecond * WavReader::SAMPLE_RATE;
    std::size_t end = totalOutput;
    if (action.endSecond) {
        end = *action.endSecond * WavReader::SAMPLE_RATE;
    }
    start = std::min(start, totalOutput);
    end = std::min(end, totalOutput);
    if (start >= end) return;

    std::vector<std::vector<int16_t>> samples;
    samples.emplace_back(outputSamples_.begin() + start, outputSamples_.begin() + end);

    if (action.inputIndex) {
        const auto& other = inputSamples_[*action.inputIndex];
        std::size_t count = std::min(other.size(), samples[0].size());
        samples.emplace_back(other.begin(), other.begin() + count);
    }

    action.converter->convert(samples);
    std::copy(samples[0].begin(), samples[0].end(), outputSamples_.begin() + start);
}

void SoundProcessor::WriteOutput() const {
	WavHeader header = outputHeader_;
	header.data_size = static_cast<uint32_t>(outputSamples_.size() * sizeof(int16_t));

	WavWriter writer(outputPath_, header);
	writer.writeSamples(outputSamples_);
}

