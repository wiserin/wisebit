#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>


namespace wisebit {


class BitArray {
    std::vector<uint8_t> data_;
    size_t len_;

    void ExpandVector();

 public:
    BitArray() = default;
    BitArray(size_t reserve);
    BitArray(const std::vector<uint8_t>& data);
    BitArray(std::vector<uint8_t>&& data);

    BitArray(const BitArray& array);
    BitArray(BitArray&& array);
    BitArray& operator=(const BitArray& array);
    BitArray& operator=(BitArray&& array);

    bool operator[](size_t index);
    bool operator==(const BitArray& another);
    bool operator!=(const BitArray& another);

    void PushBack(bool bit);
    void SetBit(size_t index, bool value);
    bool InvertBit(size_t index);

    bool GetBit(size_t index);

    void Invert();

    std::vector<uint8_t> Extract();

    ~BitArray() = default;

};


} // namespace wisebit
