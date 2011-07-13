
/*
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n  n/2 (n is even)
 * n  3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 *
 * 13  40  20  10  5  16  8  4  2  1
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 *
 *
 * Answer:
 * 837799
 */

#include "impl.h"

#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Need limit" << std::endl;;	
		return -1;
	}
	const long limit = atoi(argv[1]);

	std::pair<long, long> p = findLongestChain(limit);
	std::cout << p.first << " => " << p.second << std::endl;
	return 0;
}
