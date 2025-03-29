#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class PolynomialUtils;

class Polynomial {
private:
    vector<int> coefficients;

    void trim() {
        while (coefficients.size() > 1 && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }

public:
    // Constructors
    Polynomial() = default;
    
    Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {
        trim();
    }

    const vector<int>& getCoefficients() const { return coefficients; }

    //arithmetic ops
    Polynomial operator+(const Polynomial& other) const {
        size_t max_size = coefficients.size() > other.coefficients.size() ? 
                         coefficients.size() : other.coefficients.size();
        vector<int> result(max_size, 0);
        
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result[i] += coefficients[i];
        }
        
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] += other.coefficients[i];
        }
        
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        size_t max_size = coefficients.size() > other.coefficients.size() ? 
                         coefficients.size() : other.coefficients.size();
        vector<int> result(max_size, 0);
        
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result[i] += coefficients[i];
        }
        
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] -= other.coefficients[i];
        }
        
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);
        
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        
        return Polynomial(result);
    }

    //FRIEND
    friend class PolynomialUtils;
    friend ostream& operator<<(ostream& os, const Polynomial& p);
};

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x) {
        int result = 0;
        const vector<int>& coeffs = p.coefficients;
        
        for (size_t i = 0; i < coeffs.size(); ++i) {
            result += coeffs[i] * static_cast<int>(pow(x, i));
        }
        
        return result;
    }

    static Polynomial derivative(const Polynomial& p) {
        if (p.coefficients.size() <= 1) {
            return Polynomial({0});
        }
        
        vector<int> deriv(p.coefficients.size() - 1);
        
        for (size_t i = 1; i < p.coefficients.size(); ++i) {
            deriv[i - 1] = p.coefficients[i] * i;
        }
        
        return Polynomial(deriv);
    }
};

ostream& operator<<(ostream& os, const Polynomial& p) {
    if (p.coefficients.empty()) {
        os << "0";
        return os;
    }

    bool first_term = true;
    
    for (int i = p.coefficients.size() - 1; i >= 0; --i) {
        int coeff = p.coefficients[i];
        
        if (coeff == 0) continue;
        
        // Handle sign
        if (!first_term) {
            if (coeff > 0) {
                os << " + ";
            } else {
                os << " - ";
                coeff = -coeff;
            }
        }
        
        // Print coefficient
        if (coeff != 1 || i == 0) {
            os << coeff;
        }
        
        // Print variable
        if (i > 0) {
            os << "x";
            if (i > 1) {
                os << "^" << i;
            }
        }
        
        first_term = false;
    }
    
    return os;
}

int main() {
    Polynomial p1({7, 2, 6});      //6x^2 + 2x + 7
    Polynomial p2({0, 1, 5, 2});   //2x^3 + 5x^2 + x
    
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    
    cout << "p1 + p2: " << p1 + p2 << endl;
    cout << "p1 - p2: " << p1 - p2 << endl;
    cout << "p1 * p2: " << p1 * p2 << endl;
    
    cout << "p1 evaluated at x=2: " << PolynomialUtils::evaluate(p1, 2) << endl;
    cout << "Derivative of p2: " << PolynomialUtils::derivative(p2) << endl;
    
    return 0;
}
