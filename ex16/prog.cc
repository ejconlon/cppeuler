
/*
 *
*  2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 What is the sum of the digits of the number 2^1000?
Answer:
1366
 */

#include "impl.h"

#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Need limit" << std::endl;;	
		return -1;
	}
	const int limit = atoi(argv[1]);

	const int sum = findDS(limit);
	std::cout << sum << std::endl;
	return 0;
}
