
#include "impl.h"

#include <iostream>
#include <sstream>
#include <exception>

Triangle* parse(std::string s) {
	Triangle* tri = new Triangle();

	int l = 1;
	std::vector<long> v;
	std::stringstream ss(s);
	std::string p;

	while (std::getline(ss, p, ' ')) {
		while (p.size() > 0 && (p[0] == ' ' || p[0] == '\n')) { p = p.substr(1); }
		while (p.size() > 0 && (p[p.size()-1] == ' ' || p[p.size()-1] == '\n')) { p = p.substr(0, p.size()-1); }
		if (p.size() == 0) continue;
		//std::cout << p << std::endl;
		if (v.size() >= l) {
			tri->push_back(v);
			v.clear();
			l += 1;
		}
		v.push_back(atoi(p.c_str()));
	}
	
	if (v.size() != l && v.size() != 0) {
		throw l;
	} else {
		tri->push_back(v);
	}

	return tri;
}

long findLargestSum(Triangle* triSrc) {
	Triangle triSink(*triSrc);
	zeroOut(&triSink);
	// triSink is now the same size as triSrc;
	// fill in bottom with triSrc row and work way up
	
	for (int r = triSrc->size()-1, c = 0; c <= r; ++c) {
		triSink[r][c] = (*triSrc)[r][c];
	}
	for (int r = triSrc->size()-2; r >= 0; --r) {
		for (int c = 0; c <= r; ++c) {
			long cur = (*triSrc)[r][c];
			long bottom = triSink[r+1][c];
			long right = triSink[r+1][c+1];
			long max = (bottom > right ? bottom : right);
			triSink[r][c] = cur + max;
		}
	}

	return triSink[0][0];
}

void zeroOut(Triangle* tri) {
	for (int i = 0; i < tri->size(); i++) {
		std::vector<long>* r = &(*tri)[i];
		for (int j = 0; j < r->size(); j++) {
			(*r)[j] = 0; 
		}
	}
}

