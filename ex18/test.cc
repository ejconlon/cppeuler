
#include "impl.h"

#include "gtest/gtest.h"

#include <iostream>

TEST(TriTest, Parse) {
	Triangle* t1 = parse(SMALL_STR);
	ASSERT_TRUE(t1 != NULL);
	EXPECT_EQ(4, t1->size());
	EXPECT_EQ(1, (*t1)[0].size());
	EXPECT_EQ(2, (*t1)[1].size());
	EXPECT_EQ(3, (*t1)[2].size());
	EXPECT_EQ(4, (*t1)[3].size());
	delete t1;
}

TEST(TriTest, Sum) {
	Triangle* t = parse(SMALL_STR);
	EXPECT_EQ(23, findLargestSum(t));
	delete t;
}

int main(int argc, char **argv) {
	std::cout << "Running main() from test.cc\n";

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

