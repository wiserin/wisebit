#include <vector>

#include "wisebit/array.hpp"


namespace wisebit {

bool BitArray::operator[](size_t index) {
    if (index > len_) {
        throw std::out_of_range("Выход за границы массива");
    }

    size_t array_index = index / 8;
    size_t bit_index = index % 8;

    bool bit = (data_[array_index] >> (7 - bit_index)) & 1;
    return bit;
}

bool BitArray::operator==(const BitArray& another) {
    if (another.data_ == data_ && another.len_ == len_) {
        return true;
    } else {
        return false;
    }
}


bool BitArray::operator!=(const BitArray& another) {
    return !(*this == another);
}


} // namespace wisebit
