
#include "impl.h"

#include "gtest/gtest.h"

#include <iostream>

TEST(ChainTest, Dummy) {
	EXPECT_EQ(1, findDS(0));
	EXPECT_EQ(2, findDS(1));
	EXPECT_EQ(4, findDS(2));
	EXPECT_EQ(8, findDS(3));
	EXPECT_EQ(7, findDS(4));
	EXPECT_EQ(5, findDS(5));
}

TEST(ChainTest, Vsum) {
	std::vector<int>* v = oneVector();
	EXPECT_EQ(1, vsum(v));
	multByTwo(v);
	EXPECT_EQ(2, vsum(v));
	multByTwo(v);
	EXPECT_EQ(4, vsum(v));
	multByTwo(v);
	EXPECT_EQ(8, vsum(v));
	multByTwo(v);
	EXPECT_EQ(7, vsum(v));
	multByTwo(v);
	EXPECT_EQ(5, vsum(v));
	delete v;
}

int main(int argc, char **argv) {
	std::cout << "Running main() from test.cc\n";

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

