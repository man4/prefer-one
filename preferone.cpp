#include <cstdlib>
#include <iostream>
#include <cstdint>

typedef std::uint64_t uint_type;

// Simple bitvector with methods to set and test bits
struct bitvector {
    unsigned char *bits;
};

static void init(bitvector &bv, size_t size) {
    bv.bits = new unsigned char[size]();
}

static void destroy(bitvector &bv) {
    delete[] bv.bits;
}

static void set_bit(bitvector &bv, size_t pos) {
    bv.bits[pos / 8] |= 1 << (pos % 8);
}

static bool test_bit(bitvector &bv, size_t pos) {
    return bv.bits[pos / 8] & (1 << (pos % 8));
}

// Prints the de Bruijn sequence B(2, order) using the prefer-one algorithm
// Precondition: 1 <= order <= 8 * sizeof(uint_type)
void debruijn(int order) {
    // MASK serves as both a bitmask and a size
    uint_type MASK = (order == 8 * sizeof(uint_type)) ? -1 : ((uint_type)1 << order) - 1;
    uint_type window = 0;

    bitvector sequences;
    init(sequences, MASK / 8 + 1);

    while (true) {
        window = (window << 1) & MASK;

        if (!test_bit(sequences, window + 1)) {
            set_bit(sequences, ++window);
            std::cout << 1; 
        }
        else if (!test_bit(sequences, window)) {
            set_bit(sequences, window);
            std::cout << 0;
        }
        else break;
    }

    destroy(sequences);
}

int main(int argc, char *argv[]) {
    int order = (argc == 1) ? 1 : std::atoi(argv[1]);
    debruijn(order);
}
