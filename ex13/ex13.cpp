
/*
 * Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
 * (nums.txt)
 * Answer: 5537376230
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>

std::vector<std::string*>* readlines(char* filename);
std::vector<int>* transform(std::string* strRep);
std::string* transform_1(std::vector<int>* vectorRep);
std::vector<int>* sum(std::vector<std::vector<int>*>* vectorReps);
void addTo(std::vector<int>* res, std::vector<int>* arg);

template <typename A, typename B>
std::vector<B>* map(std::vector<A>* vectorA, B (*f)(A)); 

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Need filename" << std::endl;
		return -1;
	}
	char* filename = argv[1];

	std::vector<std::string*>* strReps = readlines(filename);

	std::vector<std::vector<int>*>* vectorReps = map(strReps, &transform);

	std::vector<int>* vectorRes = sum(vectorReps);

	std::string* strRes = transform_1(vectorRes);

	std::cout << *strRes << std::endl;

	assert((*strRes).substr(0, 10) == std::string("5537376230"));
	

	for (int i = 0; i < strReps->size(); i++) {
		delete strReps->at(i);
	}
	delete strReps;
	for (int i = 0; i < vectorReps->size(); i++) {
		delete vectorReps->at(i);
	}
	delete vectorReps;
	delete vectorRes;
	delete strRes;
	return 0;
}

std::vector<std::string*>* readlines(char* filename){
	std::vector<std::string*>* entries = new std::vector<std::string*>();
	const int len = 512;
	char num[len];
	std::ifstream fs(filename);
	if (fs.is_open()) {
		while (fs.good()) {
			fs.getline(num, len);
			std::string* s = new std::string(num);
			entries->push_back(s);
		}
	}
	return entries;
}

std::vector<int>* sum(std::vector<std::vector<int>*>* entries) {
	std::vector<int>* vectorRep = new std::vector<int>();
	std::vector<std::vector<int>*>::iterator eit;
	for (eit = entries->begin(); eit != entries->end(); eit++) {
		std::vector<int>* v = *eit;
		addTo(vectorRep, v);
	}
	return vectorRep;
}

void addTo(std::vector<int>* res, std::vector<int>* arg) {
	// add component by component
	for (int pos = 0; pos < arg->size(); pos++) {
		if (pos >= res->size()) {
			res->push_back(arg->at(pos));	
		} else {
			(*res)[pos] = res->at(pos) + arg->at(pos);
		}
	}
	// and fix up with carries
	int carry = 0;
	for (int pos = 0; pos < res->size(); pos++) {
		int x = res->at(pos) + carry;
		carry = x / 10;
		x = x % 10;
		(*res)[pos] = x;
	}
	if (carry > 0) {
		res->push_back(carry);
	}
}

std::vector<int>* transform(std::string* strRep) {
	std::vector<int>* vectorRep = new std::vector<int>();
	std::string::reverse_iterator rit;
	for (rit = strRep->rbegin(); rit != strRep->rend(); ++rit) {
		char c = *rit;
		//std::cout << "A: " << c << std::endl;
		vectorRep->push_back(c - '0');
	}
	return vectorRep;
}

std::string* transform_1(std::vector<int>* vectorRep) {
	std::string* strRep = new std::string();
	std::vector<int>::reverse_iterator rit;
	for (rit = vectorRep->rbegin(); rit != vectorRep->rend(); ++rit) {
		int c = *rit;
		//std::cout << "B: " << '0' + c << std::endl;
		strRep->push_back('0' + c);
	}
	return strRep;
}

template <typename A, typename B>
std::vector<B>* map(std::vector<A>* vectorA, B (*f)(A)) {
	std::vector<B>* vectorB = new std::vector<B>();
	for (int i = 0; i < vectorA->size(); i++) {
		B res = (*f)(vectorA->at(i));
		vectorB->push_back(res);
	}
	return vectorB;
}

