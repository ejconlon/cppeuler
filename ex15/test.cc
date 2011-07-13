
#include "impl.h"

#include "gtest/gtest.h"

#include <iostream>

TEST(RoutesTest, Dummy) {
	EXPECT_EQ(2, findRoutes(1));
	EXPECT_EQ(6, findRoutes(2));
}

TEST(RouteMemoTest, Dummy) {
	RouteMemo m(2);
	EXPECT_EQ(2, m.get(1, 1));
	EXPECT_EQ(6, m.get(2, 2));
}

int main(int argc, char **argv) {
	std::cout << "Running main() from test.cc\n";

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

