#include "BigInt.h"
#include "gtest/gtest.h"

TEST(BIOperators, CopyAssign) {
    BigInt original("-1234567890");
    BigInt copy = original;
    EXPECT_EQ(static_cast<std::string>(original), static_cast<std::string>(copy));
}
