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

TEST(BIOperators, UnaryMinus) {
    BigInt pos(500);
    BigInt zero(0);
    EXPECT_EQ(static_cast<std::string>(-pos), "-500");
    EXPECT_EQ(static_cast<std::string>(-zero), "0");
}

TEST(BIOperators, Addition) {
    BigInt pos_1(999);
    BigInt pos_2(1);
    BigInt neg_1(-100);
    BigInt neg_2(-250);
    EXPECT_EQ(static_cast<std::string>(pos_1 + pos_2), "1000");
    EXPECT_EQ(static_cast<std::string>(100 + pos_1), "1099");
    EXPECT_EQ(static_cast<std::string>(neg_1 + neg_2), "-350");
    EXPECT_EQ(static_cast<std::string>(pos_1 + 0), "999");
    EXPECT_EQ(static_cast<std::string>(neg_1 + pos_1), "899");
}

TEST(BIOperators, Subtraction) {
    BigInt pos_1(500);
    BigInt pos_2(200);
    BigInt neg_1(-500);
    BigInt neg_2(-200);

    EXPECT_EQ(static_cast<std::string>(pos_1 - pos_2), "300");
    EXPECT_EQ(static_cast<std::string>(pos_2 - pos_1), "-300");
    EXPECT_EQ(static_cast<std::string>(pos_1 - (-100)), "600");
    EXPECT_EQ(static_cast<std::string>(neg_1 - 200), "-700");
    EXPECT_EQ(static_cast<std::string>(neg_2 - neg_1), "300");
    EXPECT_EQ(static_cast<std::string>(pos_1 - pos_1), "0");
    EXPECT_EQ(static_cast<std::string>(1000 - pos_1), "500");
}

TEST(BIOperators, CompoundAssignments) {
    BigInt val(100);
    val += 50;
    EXPECT_EQ(static_cast<std::string>(val), "150");
    val += -200;
    EXPECT_EQ(static_cast<std::string>(val), "-50");
    val -= -100;
    EXPECT_EQ(static_cast<std::string>(val), "50");
    val -= 50;
    EXPECT_EQ(static_cast<std::string>(val), "0");
}