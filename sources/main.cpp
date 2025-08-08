#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "mersenne_twister.h"
#include "os_clock.h"

class timer_o {
private:
    os_clock::timed_ns_t t1 = 0;
    os_clock::timed_ns_t t2 = 0;

public:
    timer_o() {
        t1 = os_clock::time_get();
        t2 = t1;
    }
    void split() {
        t2 = os_clock::time_get();
    }
    os_clock::timed_ns_t elapsed_ns() {
        return (t2 - t1);
    }
    os_clock::timed_ms_t elapsed_ms() {
        return os_clock::ms_from_ns(elapsed_ns());
    }
};

int main(int ac, char** av) {
    constexpr unsigned ms_sample = 30000;
    unsigned v = 0;
    {
        mersenne_twister_o o;
        timer_o t;
        int n = 0;
        os_clock::timed_ms_t ms = 0;
        do {
            for (int i = 0; i < 1000000; ++i) {
                v = o.random_get();
            }
            ++n;
            t.split();
            ms = t.elapsed_ms();
        } while (ms < ms_sample);
        printf("Computed %d million primes in %ld (ms) - %0.1f m/s - last %u \n", n, ms, ((n * 1000.0) / ms), v);
    }

    return 0;
}
