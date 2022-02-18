#include <gtest/gtest.h>

int main(int arg, char** argv) {

	::testing::InitGoogleTest(&arg, argv);
	return RUN_ALL_TESTS();

}