//
// Created by anton on 17.10.2026.
//

#include "SoundProcessor.h"
#include "../WAV/WavWriter.h"
#include "../converters/ConverterFactory.h"
#include <algorithm>
#include <stdexcept>
#include <utility>

#include "VectorSampleStream.h"

SoundProcessor::SoundProcessor(const std::string& outputFile, const std::vector<std::string>& wavFiles)
	: outputPath_(outputFile) {

	if (wavFiles.empty()) {
		throw std::invalid_argument("No input wav files");
	}

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

	for (auto& samples : inputSamples_) {
		inputStreams_.push_back(std::make_unique<VectorSampleStream>(samples, 0, samples.size()));
	}

	outputSamples_ = inputSamples_[0];
}

void SoundProcessor::ExecCommand(const Command& command) {
	auto action = createConverter(command, inputStreams_);

	std::size_t totalOutput = outputSamples_.size();
	std::size_t start = action.startSecond * WavReader::SAMPLE_RATE;
	std::size_t end = totalOutput;
	if (action.endSecond) {
		end = *action.endSecond * WavReader::SAMPLE_RATE;
	}
	start = std::min(start, totalOutput);
	end = std::min(end, totalOutput);

	VectorSampleStream mainStream(outputSamples_, start, end - start);
	action.converter->convert(mainStream);
}


void SoundProcessor::WriteOutput() const {
	WavHeader header = outputHeader_;
	header.data_size = outputSamples_.size() * sizeof(int16_t);

	WavWriter writer(outputPath_, header);
	writer.writeSamples(outputSamples_);
}

