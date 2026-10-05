#include "BigInt.h"
#include "gtest/gtest.h"

TEST(BIOperators, CopyAssign) {
    BigInt original("-1234567890");
    BigInt copy;
    copy = original;
    EXPECT_EQ(static_cast<std::string>(original), static_cast<std::string>(copy));
}

TEST(BIOperators, Comparisons) {
    BigInt BI_1(1000);
    BigInt BI_2(2000);
    BigInt BI_3("-1500");
    BigInt BI_4("0");

    EXPECT_TRUE(BI_1 < BI_2);
    EXPECT_TRUE(BI_2 > BI_1);
    EXPECT_TRUE(BI_3 < BI_4);
    EXPECT_TRUE(BI_1 <= 10000);
    EXPECT_TRUE(BI_1 >= 1000);
    EXPECT_TRUE(BI_1 != BI_2);
    EXPECT_TRUE(BI_1 == 1000);

    EXPECT_TRUE(10000 >= BI_1);
    EXPECT_TRUE(-10000 <= BI_4);
}

TEST(BIOperators, LogicalNot) {
    BigInt zero("0");
    BigInt neg_val(-999);
    EXPECT_TRUE(!zero);
    EXPECT_FALSE(!neg_val);
}