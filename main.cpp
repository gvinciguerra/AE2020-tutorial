#include <iostream>
#include <sdsl/vectors.hpp>
#include <sdsl/bit_vectors.hpp>

int main() {
    sdsl::int_vector<> v = {1, 1, 2, 3, 5, 8};
    std::cout << sdsl::size_in_bytes(v) << std::endl;
    std::cout << v << std::endl;
    return 0;
}