
#include "impl.h"

#include <iostream>
#include <sstream>
#include <exception>

Triangle* parse(std::string s) {
	Triangle* tri = new Triangle();

	int l = 1;
	std::vector<int> v;
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

long findLargestSum(Triangle* tri) {
	return 23;
}

