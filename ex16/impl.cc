
#include "impl.h"

long findDS(const int limit) {
	std::vector<int>* v = oneVector();
	for (int l = limit; l > 0; --l) {
		multByTwo(v);
	}
	long s = vsum(v);
	delete v;
	return s;
}

long vsum(std::vector<int>* vec) {
	long s = 0;
	for (int i = 0; i < vec->size(); i++) {
		s += (*vec)[i];
	}
	return s;
}

std::vector<int>* oneVector() {
	std::vector<int>* v = new std::vector<int>();
	v->push_back(1);
	return v;
}

void multByTwo(std::vector<int>* vec) {
	for (int i = 0; i < vec->size(); i++) {
		(*vec)[i] *= 2;
	}
	int carry = 0;
	for (int i = 0; i < vec->size(); i++) {
		(*vec)[i] += carry;
		carry = (*vec)[i] / 10;
		(*vec)[i] %= 10;
	}
	if (carry > 0) {
		vec->push_back(carry);
	}
}

