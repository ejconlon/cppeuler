
/*
 * Starting in the top left corner of a 22 grid, there are 6 routes (without backtracking) to the bottom right corner.
 *
 *
 * How many routes are there through a 20x20 grid?
 *
 *
 * Answer:
 * 137846528820
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

	RouteMemo m(limit);
	m.print();
	const long routes = m.get(limit, limit);
	std::cout << routes << std::endl;
	return 0;
}
