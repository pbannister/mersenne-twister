#ifndef __ZRANDOM_H__
#define __ZRANDOM_H__

//
//  Mersenne twister - random number generator.
//  Generate uniform distribution of 32 bit integers with the MT19937 algorithm.
//

class ZRandom {

private:
	enum {
		N = 624, M = 397
	};
	unsigned MT[N + 1];
	unsigned* map[N];
	int nValues;

public:
	ZRandom(unsigned iSeed = 20070102);
	unsigned getValue();

};

#endif
