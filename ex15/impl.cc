
#include "impl.h"

long findRoutes(const int limit) {
	return findRoutesHelper(limit, limit);
}

long findRoutesHelper(const int x, const int y) {
	if (x == 0 || y == 0){
		return 1;
	} else {
		long xc = findRoutesHelper(x-1, y);
		long yc = findRoutesHelper(x, y-1);
		return xc + yc;
	}
}



