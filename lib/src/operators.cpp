#include <ostream>  // Copyright 2025 wiserin
#include <vector>

#include "wisebit/array.hpp"


namespace wisebit {

bool BitArray::operator[](size_t index) const {
    if (index > len_) {
        throw std::out_of_range("Выход за границы массива");
    }

    size_t array_index = index / 8;
    size_t bit_index = index % 8;

    bool bit = (data_[array_index] >> (7 - bit_index)) & 1;
    return bit;
}

bool BitArray::operator==(const BitArray& another) const {
    if (another.data_ == data_ && another.len_ == len_) {
        return true;
    } else {
        return false;
    }
}


bool BitArray::operator!=(const BitArray& another) const {
    return !(*this == another);
}


std::ostream& operator<<(std::ostream& stream, const BitArray& array) {
    for (int i = 0; i < array.len_; ++i) {
        stream << array.GetBit(i);
        if ((i + 1) % 8 == 0) {
            stream << ' ';
        }
    }
    return stream;
}

} // namespace wisebit