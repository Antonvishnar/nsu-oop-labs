#ifndef OOP_NSU_LABS_BIGINT_H
#define OOP_NSU_LABS_BIGINT_H
#include <string>

class BigInt {
public:
    BigInt();
    BigInt(const std::string &value);
    BigInt(long long value);
    ~BigInt();

    operator std::string() const;
private:
    char* value_;
    std::size_t size_;
    bool is_negative_;

    std::string validate_string_(const std::string &value);
};
std::ostream& operator<<(std::ostream& os, const BigInt& bi);


#endif //OOP_NSU_LABS_BIGINT_H
