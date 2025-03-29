#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool isNegative;

    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

    void normalize() {
        int carry = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        while (carry > 0) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
        removeLeadingZeros();
    }

    BigInteger addPositive(const BigInteger& other) const {
        BigInteger result;
        size_t max_len = max(digits.size(), other.digits.size());
        result.digits.resize(max_len, 0);
        
        int carry = 0;
        for (size_t i = 0; i < max_len; ++i) {
            int a = (i < digits.size()) ? digits[i] : 0;
            int b = (i < other.digits.size()) ? other.digits[i] : 0;
            int sum = a + b + carry;
            result.digits[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry > 0) {
            result.digits.push_back(carry);
        }
        return result;
    }

    BigInteger subtractPositive(const BigInteger& other) const {
        BigInteger result;
        result.digits.resize(digits.size(), 0);
        
        int borrow = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            int a = digits[i];
            int b = (i < other.digits.size()) ? other.digits[i] : 0;
            int diff = a - b - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits[i] = diff;
        }
        result.removeLeadingZeros();
        return result;
    }

    int compareAbsolute(const BigInteger& other) const {
        if (digits.size() != other.digits.size()) {
            return digits.size() > other.digits.size() ? 1 : -1;
        }
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i]) {
                return digits[i] > other.digits[i] ? 1 : -1;
            }
        }
        return 0;
    }

public:
    BigInteger() : isNegative(false) { digits.push_back(0); }
    
    BigInteger(const string& s) {
        if (s.empty()) {
            digits.push_back(0);
            isNegative = false;
            return;
        }
        
        size_t start = 0;
        if (s[0] == '-') {
            isNegative = true;
            start = 1;
        } else if (s[0] == '+') {
            isNegative = false;
            start = 1;
        } else {
            isNegative = false;
        }
        
        for (int i = s.length() - 1; i >= (int)start; --i) {
            if (!isDigit(s[i])) {
                 digits.clear();
                digits.push_back(0);
                isNegative = false;
                return;
            }
            digits.push_back(s[i] - '0');
        }
        removeLeadingZeros();
    }
    
    BigInteger(long long num) {
        if (num < 0) {
            isNegative = true;
            num = -num;
        } else {
            isNegative = false;
        }
        
        if (num == 0) {
            digits.push_back(0);
        } else {
            while (num > 0) {
                digits.push_back(num % 10);
                num /= 10;
            }
        }
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            BigInteger result = addPositive(other);
            result.isNegative = isNegative;
            return result;
        } else {
            int cmp = compareAbsolute(other);
            if (cmp == 0) {
                return BigInteger(0);
            } else if (cmp > 0) {
                BigInteger result = subtractPositive(other);
                result.isNegative = isNegative;
                return result;
            } else {
                BigInteger result = other.subtractPositive(*this);
                result.isNegative = other.isNegative;
                return result;
            }
        }
    }

    BigInteger operator-(const BigInteger& other) const {
        BigInteger temp = other;
        temp.isNegative = !temp.isNegative;
        return *this + temp;
    }

    BigInteger operator*(const BigInteger& other) const {
        BigInteger result;
        result.digits.resize(digits.size() + other.digits.size(), 0);
        
        for (size_t i = 0; i < digits.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < other.digits.size() || carry > 0; ++j) {
                long long product = result.digits[i + j] + 
                                  digits[i] * (j < other.digits.size() ? other.digits[j] : 0) + 
                                  carry;
                result.digits[i + j] = product % 10;
                carry = product / 10;
            }
        }
        
        result.isNegative = isNegative != other.isNegative;
        result.removeLeadingZeros();
        return result;
    }

    bool operator==(const BigInteger& other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return isNegative;
        }
        if (isNegative) {
            return compareAbsolute(other) > 0;
        }
        return compareAbsolute(other) < 0;
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const BigInteger& num) {
        if (num.isNegative) {
            os << '-';
        }
        for (int i = num.digits.size() - 1; i >= 0; --i) {
            os << num.digits[i];
        }
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& num) {
        string s;
        is >> s;
        num = BigInteger(s);
        return is;
    }
};

int main() {
    BigInteger a("12345678901234567890");
    BigInteger b("98765432109876543210");
    BigInteger c = a + b;
    BigInteger d = b - a;
    BigInteger e = a * b;
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << c << endl;
    cout << "b - a = " << d << endl;
    cout << "a * b = " << e << endl;
    
    cout << boolalpha; //returns the words true and false
    cout << "a < b? " << (a < b) << endl;
    cout << "a == b? " << (a == b) << endl;
    return 0;
}
