
#include "impl.h"

#include "gtest/gtest.h"

#include <iostream>

TEST(ChainTest, Dummy) {
	std::pair<long, long> p(9, 20);
	EXPECT_EQ(p, findLongestChain(13));
}

TEST(ChainTest, Next) {
	EXPECT_EQ(1, next(1));
	EXPECT_EQ(1, next(2));
	EXPECT_EQ(10, next(3));
	EXPECT_EQ(40, next(13));
}

TEST(ChainTest, Len) {
	EXPECT_EQ(1, chainLen(1));
	EXPECT_EQ(2, chainLen(2));
	EXPECT_EQ(10, chainLen(13));
}

int main(int argc, char **argv) {
	std::cout << "Running main() from test.cc\n";

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

