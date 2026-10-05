#ifndef OOP_NSU_LABS_BIGINT_H
#define OOP_NSU_LABS_BIGINT_H
#include <string>

class BigInt {
public:
    BigInt();
    BigInt(const std::string &value);
    BigInt(long long value);
    ~BigInt();

    BigInt(const BigInt &other);
    BigInt& operator=(const BigInt &other);

    friend bool operator==(const BigInt &BI_1, const BigInt &BI_2);
    friend bool operator<(const BigInt &BI_1, const BigInt &BI_2);

    operator std::string() const;
private:
    char* value_;
    std::size_t size_;
    bool is_negative_;

    std::string validate_string_(const std::string &value);
};
std::ostream& operator<<(std::ostream& os, const BigInt& bi);

bool operator!=(const BigInt &BI_1, const BigInt &BI_2);
bool operator>(const BigInt &BI_1, const BigInt &BI_2);
bool operator<=(const BigInt &BI_1, const BigInt &BI_2);
bool operator>=(const BigInt &BI_1, const BigInt &BI_2);

#endif //OOP_NSU_LABS_BIGINT_H
