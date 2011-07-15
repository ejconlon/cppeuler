#ifndef IMPL_H_
#define IMPL_H_

#include <string>
#include <list>

class Thesaurus {
	private:
		std::string filename_;
		void* mm_;
		int fd_;
		size_t offset_;
		size_t pageSize_;

	public:
		Thesaurus(std::string& filename);
		~Thesaurus();
		void open();
		std::list<std::string>* findSynonyms(std::string& query);
		size_t getOffset();
		size_t getPageSize();
		bool isOpen();
		void close();
		void reset();
		void advance();
		char* seek(size_t pos);

};


#endif
