#include <cstddef>  // Copyright 2025 wiserin
#include <cstdint>
#include <stdexcept>
#include <vector>

#include "wisebit/array.hpp"


namespace wisebit {

BitArray::BitArray(size_t reserve) {
    data_.reserve(reserve);
    len_ = 0;
}


BitArray::BitArray(const std::vector<uint8_t>& data) {
    data_ = std::vector<uint8_t> (data.size());
    for (int i = 0; i < data.size(); ++i) {
        data_[i] = data[i];
    }
    len_ = data_.size() * 8;
}


BitArray::BitArray(const std::vector<uint8_t>& data, size_t bits_len) {
    data_ = std::vector<uint8_t> (data.size());
    for (int i = 0; i < data.size(); ++i) {
        data_[i] = data[i];
    }
    if (bits_len > (data_.size() * 8)) {
        throw std::out_of_range("bits_len не может быть меньше длинны вектора * 8");
    }
    len_ = bits_len;
}


BitArray::BitArray(std::vector<uint8_t>&& data) {
    data_ = std::move(data);
    len_ = data_.size() * 8;
}


BitArray::BitArray(std::vector<uint8_t>&& data, size_t bits_len) {
    data_ = std::move(data);
    if (bits_len > (data_.size() * 8)) {
        throw std::out_of_range("bits_len не может быть меньше длинны вектора * 8");
    }
    len_ = bits_len;
}


BitArray::BitArray(const BitArray& array) {
    data_ = array.data_;
    len_ = array.len_;
}


BitArray::BitArray(BitArray&& array) {
    data_ = std::move(array.data_);
    len_ = array.len_;
}


BitArray& BitArray::operator=(const BitArray& array) {
    data_ = array.data_;
    len_ = array.len_;
    return *this;
}


BitArray& BitArray::operator=(BitArray&& array) {
    data_ = std::move(array.data_);
    len_ = array.len_;
    return *this;
}

} // namespace wisebit
