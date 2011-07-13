#ifndef IMPL_H_
#define IMPL_H_

#include <map>

long next(const long cur);
long chainLen(long cur);
std::pair<long, long> findLongestChain(const long limit);

class ChainLenMemo {
	private:
		typedef std::map<long, long> MapType;
		MapType memo;
		long hits;
		long misses;

	public:
		ChainLenMemo();
		~ChainLenMemo();
		long get(const long cur);
		long getHits();
		long getMisses();
};

#endif
