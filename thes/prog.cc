
#include "impl.h"

#include <iostream>

int main(int argc, char* argv[]) {
	if (argc < 3) {
		std::cout << "Need thesaurus file and query" << std::endl;;	
		return -1;
	}
	std::string filename(argv[1]);
	std::string query(argv[2]);

	Thesaurus t(filename);

	std::list<std::string>* synonyms = t.findSynonyms(query);

	std::list<std::string>::const_iterator it;
	for (it = synonyms->begin(); it != synonyms->end(); ++it) {
		std::cout << *it << std::endl;
	}

	delete synonyms;

	return 0;
}
