#include <cstdint>  // Copyright 2025 wiserin
#include <stdexcept>
#include <vector>

#include "wisebit/array.hpp"


namespace wisebit {

bool BitArray::InvertBit(size_t index) {
    if (index >= len_) {
        throw std::out_of_range("Выход за границы массива");
    }

    size_t array_index = index / 8;
    size_t bit_index = index % 8;

    uint8_t mask = 1 << (7 - bit_index);

    data_[array_index] ^= mask;

    return GetBit(index);
}


void BitArray::Invert() {
    for (int i = 0; i < data_.size(); ++i) {
        data_[i] = ~data_[i];
    }
}


void BitArray::ExpandVector() {
    data_.push_back(0);
}


} // namespace wisebit
