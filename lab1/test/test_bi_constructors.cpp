#include<gtest/gtest.h>
#include "BigInt.h"

TEST(BIConstructors, DefaultAndNums) {
    BigInt zero;
    EXPECT_EQ(static_cast<std::string>(zero), "0");

    BigInt pos_num(15000);
    EXPECT_EQ(static_cast<std::string>(pos_num), "15000");

    BigInt neg_num(-15000);
    EXPECT_EQ(static_cast<std::string>(neg_num), "-15000");

    BigInt neg_zero(-0000);
    EXPECT_EQ(static_cast<std::string>(neg_zero), "0");
}

TEST(BIConstructors, FromValidString) {
    BigInt def_val("1234567");
    EXPECT_EQ(static_cast<std::string>(def_val), "1234567");

    BigInt big_val("1111111111111111111111111111111111111111111111111");
    EXPECT_EQ(static_cast<std::string>(big_val), "1111111111111111111111111111111111111111111111111");

    BigInt neg_val("-5555555555555555555555");
    EXPECT_EQ(static_cast<std::string>(neg_val), "-5555555555555555555555");

    BigInt start_with_zero("00000109");
    EXPECT_EQ(static_cast<std::string>(start_with_zero), "109");

    BigInt minus_zero("-00000");
    EXPECT_EQ(static_cast<std::string>(minus_zero), "0");

    BigInt empty_string("");
    EXPECT_EQ(static_cast<std::string>(empty_string), "0");
}

TEST(BIConstructors, FromInvalidString) {
    EXPECT_THROW(BigInt("-"), std::invalid_argument);
    EXPECT_THROW(BigInt("+"), std::invalid_argument);
    EXPECT_THROW(BigInt("123a45"), std::invalid_argument);
    EXPECT_THROW(BigInt("   "), std::invalid_argument);
    EXPECT_THROW(BigInt("--10"), std::invalid_argument);
}

TEST(BIConstructors, CopyConstructor) {
    BigInt original("1234567890");
    BigInt copy(original);
    EXPECT_EQ(static_cast<std::string>(original), static_cast<std::string>(copy));
}
