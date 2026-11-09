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
		if (inputSamples_.empty()) outputHeader_ = reader.getHeader();
		std::vector<int16_t> samples;
		std::vector<int16_t> block;
		while (reader.readNextSamples(block)) {
			samples.insert(samples.end(), block.begin(), block.end());
		}
		inputSamples_.push_back(samples);
	}
	outputSamples_ = inputSamples_[0];
}

void SoundProcessor::ExecCommand(const Command& command) {
	auto action = createConverter(command);
	std::size_t start = action.startSecond * WavReader::SAMPLE_RATE;
    std::size_t end = outputSamples_.size();
    if (action.endSecond) {
        end = *action.endSecond * WavReader::SAMPLE_RATE;
    }

    start = std::min(start, outputSamples_.size());
    end = std::min(end, outputSamples_.size());
    if (start >= end) return;

    std::vector<std::vector<int16_t>> samples;
    samples.emplace_back(outputSamples_.begin() + start, outputSamples_.begin() + end);

    if (action.inputIndex) {
        const auto& in = inputSamples_[*action.inputIndex];
        std::size_t count = std::min(in.size(), samples[0].size());
        samples.emplace_back(in.begin(), in.begin() + count);
    }

    action.converter->convert(samples);
    std::copy(samples[0].begin(), samples[0].end(), outputSamples_.begin() + start);
}

void SoundProcessor::WriteOutput() const {
	WavHeader header = outputHeader_;
	header.data_size = static_cast<uint32_t>(outputSamples_.size() * sizeof(int16_t));
	header.overall_size = header.data_size + 36;

	WavWriter writer(outputPath_, header);
	writer.writeSamples(outputSamples_);
}

