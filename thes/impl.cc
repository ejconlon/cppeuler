
#include "impl.h"

#include <sys/mman.h>
#include <fcntl.h>


Thesaurus::Thesaurus(std::string& filename) : filename_(filename), mm_(NULL), pageSize_(0x1000), fd_(-1), offset_(0) {	
}
Thesaurus::~Thesaurus() {
	if (isOpen()) {
		close();
	}
}

void Thesaurus::open() {
	offset_ = 0;
	const char* fnc = filename_.c_str();
	fd_ = ::open(fnc, O_RDONLY); 	
	reset();
}

void Thesaurus::reset() {
	if (mm_ != NULL) munmap(mm_, pageSize_);
	offset_ = 0;
	mm_ = mmap(NULL, pageSize_, PROT_READ, 0, fd_, offset_);
}

void Thesaurus::advance() {
	if (mm_ != NULL) munmap(mm_, pageSize_);
	offset_ += pageSize_;
	mm_ = mmap(NULL, pageSize_, PROT_READ, 0, fd_, offset_);
}

void Thesaurus::close() {
	if (mm_ != NULL) munmap(mm_, pageSize_);
	mm_ = NULL;
	offset_ = 0;
	::close(fd_);
	fd_ = -1;
}

bool Thesaurus::isOpen() {
	return fd_ != 1;
}

size_t Thesaurus::getOffset() {
	return offset_;
}	

size_t Thesaurus::getPageSize() {
	return pageSize_;
}	

char* Thesaurus::seek(size_t pos) {
	if (pos < offset_) {
		reset();
	} else {
		pos -= offset_;
	}
	while (pos > offset_ + pageSize_) {
		advance();
		pos -= pageSize_;
	}
	return static_cast<char *>(mm_) + pos;
}

std::list<std::string>* Thesaurus::findSynonyms(std::string& query) {
	std::list<std::string>* syns = new std::list<std::string>();
	syns->push_back("hershey bar");
	return syns;
}

