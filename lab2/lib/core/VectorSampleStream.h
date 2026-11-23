//
// Created by anton on 22.11.2026.
//

#ifndef OOP_NSU_LABS_VECTORSAMPLESTREAM_H
#define OOP_NSU_LABS_VECTORSAMPLESTREAM_H
#include <vector>
#include "SampleStream.h"

class VectorSampleStream : public SampleStream {
public:
    VectorSampleStream(std::vector<int16_t>& data, std::size_t offset, std::size_t length)
        : data_(data), offset_(offset), length_(length) {}

    std::size_t size() const override { return length_; }
    int16_t& operator[](std::size_t index) override { return data_[offset_ + index]; }
    int16_t operator[](std::size_t index) const override { return data_[offset_ + index]; }

private:
    std::vector<int16_t>& data_;
    std::size_t offset_;
    std::size_t length_;
};

#endif //OOP_NSU_LABS_VECTORSAMPLESTREAM_H
