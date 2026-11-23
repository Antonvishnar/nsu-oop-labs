//
// Created by anton on 22.11.2026.
//

#ifndef OOP_NSU_LABS_SAMPLESTREAM_H
#define OOP_NSU_LABS_SAMPLESTREAM_H

#include <cstdint>

class SampleStream {
public:
    virtual ~SampleStream() = default;
    virtual std::size_t size() const = 0;
    virtual int16_t& operator[](std::size_t index) = 0;
    virtual int16_t operator[](std::size_t index) const = 0;
};

#endif //OOP_NSU_LABS_SAMPLESTREAM_H
