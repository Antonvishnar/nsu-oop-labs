//
// Created by anton on 26.10.2026.
//

#ifndef OOP_NSU_LABS_WAVHEADER_H
#define OOP_NSU_LABS_WAVHEADER_H
#include <cstdint>

struct WavHeader {
    char riff[4];
    uint32_t overall_size;
    char wave[4];
    char fmt_chunk_marker[4];
    uint32_t length_of_fmt;
    uint16_t format_type;
    uint16_t channels;
    uint32_t sample_rate;
    uint32_t byterate;
    uint16_t block_align;
    uint16_t bits_per_sample;
    char data_chunk_header[4];
    uint32_t data_size;
};

#endif //OOP_NSU_LABS_WAVHEADER_H
