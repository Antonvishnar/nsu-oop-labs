#include <iostream>

#include "BigInt.h"

int main() {
    BigInt big_int0;
    BigInt big_int1("598659876565834754735644566857260856854027609587675604586540811117645534654895639");
    // может быть и отрицательное:
    BigInt big_int2("-999999999999999999999999999999999999999999999999999999999999999999999999999999999");
    big_int1 = -big_int0;
    big_int2 = ++big_int1;
    BigInt big_int3 = big_int1 + big_int2;
    big_int3 -= big_int1;
    BigInt big_int4 = big_int1 * big_int2;
    BigInt big_int5 = big_int1 * big_int2;
    big_int5 /= 2;
    BigInt big_int6 = big_int1 * big_int2;
    big_int6 += 125;
    BigInt big_int7 = big_int1 * big_int2;
    big_int7 += 500 * big_int2;

    if (big_int1 < big_int2 && !big_int3 && 8000 >= big_int4) {
        // ...
    }

    std::cout<<big_int0<<'\n';

    return 0;
}
