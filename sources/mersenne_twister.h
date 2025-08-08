#pragma once
//
//  Mersenne twister - random number generator.
//  Generate uniform distribution of 32 bit integers with the MT19937 algorithm.
//

class mersenne_twister_o {
private:
    enum {
        N = 624,
        M = 397
    };
    unsigned MT[N + 1];
    unsigned* map[N];
    int n_values;

public:
    mersenne_twister_o(unsigned iSeed = 20070102);

public:
    unsigned random_get();
};
