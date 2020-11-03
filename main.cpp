#include <chrono>
#include <iostream>
#include <sdsl/bit_vectors.hpp>

template<typename SelectType>
bool lookup(const std::string &s, const char *data, const SelectType &select, size_t total_strings) {
    // check whether s is smaller than anyone in the set
    auto res = std::strcmp(s.c_str(), data);
    if (res == 0)
        return true;
    else if (res < 0)
        return false;

    // s is to the right of the first string
    size_t lo = 0;
    size_t hi = total_strings - 1;
    while (lo <= hi) {
        auto mid = lo + (hi - lo) / 2;
        auto str_start = select(mid + 1);
        auto res = std::strcmp(s.c_str(), data + str_start);
        if (res == 0)
            return true;
        if (res > 0)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return false;
}

#define TO_MiB(x) (double(x) / (1 << 20))

int main() {
    std::ifstream file("/Users/giorgio/Desktop/words.txt");
    std::string buffer;

    std::getline(file, buffer);
    size_t num_strings = std::stoull(buffer);

    std::getline(file, buffer);
    size_t total_length_strings_only = std::stoull(buffer);

    size_t total_length_with_terminators = total_length_strings_only + num_strings;
    sdsl::bit_vector bv(total_length_with_terminators, 0);
    char *data = (char *) malloc(sizeof(char) * total_length_with_terminators);

    size_t i = 0;
    while (std::getline(file, buffer)) {
        std::memcpy(data + i, buffer.c_str(), buffer.size() + 1); // +1 to copy the terminator
        bv[i] = 1;
        i += buffer.size() + 1;
    }
    assert(i == total_length_with_terminators);

    // To use the plain bitvector uncomment the following line
    //    sdsl::select_support_mcl<1> select(&bv);

    // To use Elias Fano uncomment the following two lines
    sdsl::sd_vector<> ef(bv);
    sdsl::select_support_sd<1> select(&ef);  // == sdsl::sd_vector<>::select_1_type select(&ef);

    std::cout << "num strings \t" << num_strings << std::endl
              << "total length\t" << total_length_with_terminators << std::endl
              << "raw data takes\t" << TO_MiB(total_length_with_terminators * sizeof(char)) << " MiB" << std::endl
              << "bitvector takes\t" << sdsl::size_in_mega_bytes(ef) << " MiB" << std::endl // To use Elias-Fano pass ef instead of bv
              << "select takes\t" << sdsl::size_in_mega_bytes(select) << " MiB" << std::endl
              << "(pointers alone would've taken " << TO_MiB(num_strings * sizeof(char *)) << " MiB)" << std::endl;

    std::string s;
    while (true) {
        std::cout << "input string (return to exit) > ";
        std::getline(std::cin, s);
        if (s.empty())
            break;

        auto t0 = std::chrono::high_resolution_clock::now();
        auto flag = lookup(s, data, select, num_strings);
        auto t1 = std::chrono::high_resolution_clock::now();
        auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
        std::cout << (flag ? "found in " : "not found in ") << ns << " ns" << std::endl;
    }
    return 0;
}