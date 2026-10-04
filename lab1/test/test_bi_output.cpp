#include "BigInt.h"
#include "gtest/gtest.h"

TEST(BIOutput, output) {
    BigInt val("-1234567");
    std::ostringstream oss;
    oss << val;
    EXPECT_EQ(oss.str(), "-1234567");
}
