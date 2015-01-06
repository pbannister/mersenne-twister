#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ZRandom.h"

class ZTimer {
	clock_t t1;
	clock_t t2;
public:
	ZTimer() :
			t1(::clock()), t2(t1) {
	}
	int elapsed() {
		return (int) (((t2 - t1) * 1000.0) / CLOCKS_PER_SEC);
	}
	int split() {
		t2 = ::clock();
		return elapsed();
	}
};

int main(int ac, char** av) {

	enum {
		dtSample = 30000
	};
	{
		ZRandom o;
		ZTimer t;
		int n = 0;
		do {
			for (int i = 0; i < 1000000; ++i) {
				unsigned v = o.getValue();
			}
			++n;
		} while (t.split() < dtSample);
		int dt = t.elapsed();
		printf("Computed %d million primes in %d MS - %0.1f m/s \n", n, dt,
				((n * 1000.0) / dt));
	}

	return 0;
}
