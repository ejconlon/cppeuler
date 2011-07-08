
#include "impl.h"

#include "gtest/gtest.h"

#include <iostream>

TEST(ChainTest, Dummy) {
	EXPECT_EQ(42, findLongestChain(100));
}

int main(int argc, char **argv) {
	std::cout << "Running main() from test.cc\n";

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

