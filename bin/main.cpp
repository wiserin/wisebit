#include <cstdint>
#include <vector>

#include <iostream>

#include "wisebit/array.hpp"


int main() {
    wisebit::BitArray bitset {std::vector<uint8_t> {244, 121}};
    wisebit::BitArray bitset_2 {std::vector<uint8_t> {244, 121}};

    // bitset.PushBack(1);
    // bitset.PushBack(1);
    // bitset.PushBack(1);
    // bitset.PushBack(1);

    // bitset.PushBack(0);
    // bitset.PushBack(1);
    // bitset.PushBack(0);
    // bitset.PushBack(0);

    bitset.PushBack(1);
    bitset.PushBack(1);

    bitset_2.PushBack(1);
    // bitset_2.PushBack(1);
    // bitset.SetBit(18, 1);
    // bitset.InvertBit(16);
    // bitset.SetBit(size_t index, bool value)

    std::cout << (bitset != bitset_2) << std::endl;

    std::cout << (bitset[0] == bitset_2[0]) << std::endl;

    std::cout << bitset[6] << std::endl;
    std::cout << bitset << std::endl;

    // std::vector<uint8_t> ex = bitset.Extract();
    // std::cout << static_cast<int>(ex[0]) << std::endl;
    // std::cout << static_cast<int>(ex[1]) << std::endl;
    // std::cout << static_cast<int>(ex[2]) << std::endl;

    // std::cout << bitset.GetBit(4) << std::endl;

}