#include <cstdint>
#include <stdexcept>
#include <vector>

#include "wisebit/array.hpp"


namespace wisebit {

bool BitArray::GetBit(size_t index) {
    if (index > len_) {
        throw std::out_of_range("Выход за границы массива");
    }

    size_t array_index = index / 8;
    size_t bit_index = index % 8;

    bool bit = (data_[array_index] >> (7 - bit_index)) & 1;
    return bit;
}


std::vector<uint8_t> BitArray::Extract() {
    return data_;
}

} // namespace wisebit
