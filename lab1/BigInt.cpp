#include "BigInt.h"

#include <stdexcept>

BigInt::BigInt() : value_(new char[1]), size_(1), is_negative_(false) {
    value_[0] = '0';
}

BigInt::BigInt(const std::string &value) {
    std::string clean = validate_string_(value);
    std::size_t start = 0;
    if (clean[0] == '-') {
        is_negative_ = true;
        size_ = clean.size() - 1;
        start = 1;
    } else {
        is_negative_ = false;
        size_ = clean.size();
    }
    value_ = new char[size_];
    for (std::size_t i = 0; i < size_; ++i) {
        value_[i] = clean[i + start];
    }
}

BigInt::BigInt(long long value) : BigInt(std::to_string(value)) {}

BigInt::~BigInt() {
    delete[] value_;
}

BigInt::operator std::string() const {
    std::string res;
    if (is_negative_) res += '-';
    for (std::size_t i = 0; i < size_; ++i) {
        res += value_[i];
    }
    return res;
}

std::string BigInt::validate_string_(const std::string &value) {
    if (value.empty()) return "0";

    std::size_t start = 0;
    bool is_neg = false;

    if (value[0] == '-') {
        is_neg = true;
        start = 1;
    } else if (value[0] == '+') {
        start = 1;
    }

    if (start == value.size()) {
        throw std::invalid_argument("String contains only a sign");
    }

    for (std::size_t i = start; i < value.size(); ++i) {
        if (!std::isdigit(value[i])) {
            throw std::invalid_argument("Invalid symbol in BigInt string");
        }
    }

    while (start < value.size() && value[start] == '0') {
        ++start;
    }

    if (start == value.size()) {
        return "0";
    }
    std::string res = value.substr(start);
    if (is_neg) res = '-' + res;
    return res;
}

std::ostream& operator<<(std::ostream& os, const BigInt& bi) {
    return os << static_cast<std::string>(bi);
};
