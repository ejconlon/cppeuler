
#include "impl.h"

#include "gtest/gtest.h"

#include <iostream>

TEST(FindTest, Dummy) {
	std::string filename("thesaurus.dat");
	std::string query("bar");
	std::string expected("hershey bar");
	Thesaurus t(filename);
	t.open();
	std::list<std::string>* syns = t.findSynonyms(query);
	std::list<std::string>::const_iterator it = syns->begin();
	EXPECT_EQ(expected, *it);
}

TEST(LoadTest, Loading) {
	std::string filename("thesaurus.dat");
	Thesaurus t(filename);
	t.open();
	EXPECT_EQ(0, t.getOffset());
	t.advance();
	EXPECT_EQ(t.getPageSize(), t.getOffset());
	t.advance();
	EXPECT_EQ(2*t.getPageSize(), t.getOffset());
	t.close();
	EXPECT_EQ(0, t.getOffset());
}

int main(int argc, char **argv) {
	std::cout << "Running main() from test.cc\n";

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

