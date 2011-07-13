
#include "impl.h"

#include <map>

long next(const long cur) {
	if (cur == 1) {
		return 1;
	} else if (cur % 2 == 0) {
		return cur / 2;
	} else {
		return cur*3+1;
	}
}

long chainLen(long cur) {
	long len = 1;
	while (cur != 1) {
		cur = next(cur);
		++len;
	}
	return len;
}

std::pair<long, long> findLongestChain(const long limit) {
	ChainLenMemo m;
	long longestStart = 0;
	long longestLen = 0;
	for (long i = 1; i <= limit; i++) {
		long len = m.get(i);
		if (len > longestLen) {
			longestLen = len;
			longestStart = i;
		}
	}
	return std::make_pair(longestStart, longestLen); 
}

ChainLenMemo::ChainLenMemo() : memo(), hits(0), misses(0) {}
ChainLenMemo::~ChainLenMemo() {}

long ChainLenMemo::get(const long cur) {
	if (cur == 1) return 1;
	MapType::const_iterator it = memo.find(cur);
	if (it == memo.end()) {
		++misses;
		long n = next(cur);
		long l = get(n);
		memo[cur] = l + 1;
		return l + 1;
	} else {
		++hits;
		return it->second;
	}
}

long ChainLenMemo::getHits() { return hits; }
long ChainLenMemo::getMisses() { return misses; }


