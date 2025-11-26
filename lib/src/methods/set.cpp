#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <vector>

#include "wisebit/array.hpp"


namespace wisebit {

void BitArray::PushBack(bool bit) {
    if (((len_ + 1) / 8) >= data_.size()) {
        ExpandVector();
    }

    size_t array_index = (len_) / 8;
    size_t bit_index = (len_) % 8;

    data_[array_index] |= (bit << (7 - bit_index));
    ++len_;
}


void BitArray::SetBit(size_t index, bool bit) {
    if (index >= len_) {
        throw std::out_of_range("Выход за границы массива");
    }

    size_t array_index = index / 8;
    size_t bit_index = index % 8;

    uint8_t mask = 1 << (7 - bit_index);

    data_[array_index] = (data_[array_index] & ~mask) | (bit ? mask : 0);
}

} // namespace wisebit
