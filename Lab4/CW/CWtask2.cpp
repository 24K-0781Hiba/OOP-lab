#include <iostream>
using namespace std;

class Polynomial {
private:
    int degree;  
    double* coefficients; 

public:
    //default
    Polynomial() : degree(0) {
        coefficients = new double[1];
        coefficients[0] = 0.0;
    }

    //parameterized constructor
    Polynomial(int deg, const double coeffs[]) : degree(deg) {
        if (deg < 0) {
            cerr << "Error: Degree cannot be negative. Setting degree to 0." << endl;
            degree = 0;
            coefficients = new double[1];
            coefficients[0] = 0.0;
        } else {
            coefficients = new double[deg + 1];
            for (int i = 0; i <= deg; ++i) {
                coefficients[i] = coeffs[i];
            }
        }
    }

    //copy construcor
    Polynomial(const Polynomial& other) : degree(other.degree) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }
    }

    //move constructor
    Polynomial(Polynomial&& other) noexcept : degree(other.degree), coefficients(other.coefficients) {
        other.degree = 0;
        other.coefficients = nullptr;
    }

    //destructor
    ~Polynomial() {
        delete[] coefficients;
    }

    Polynomial& operator=(const Polynomial& other) {
        if (this == &other) return *this; 

        delete[] coefficients; 

        degree = other.degree;
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }

        return *this;
    }
    Polynomial& operator=(Polynomial&& other) noexcept {
        if (this == &other) return *this;

        delete[] coefficients; 
        degree = other.degree;
        coefficients = other.coefficients;
        other.degree = 0;
        other.coefficients = nullptr;
        return *this;
    }

    int getDegree() const {
        return degree;
    }

    double evaluate(double x) const {
        double result = 0.0;
        double power = 1.0;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * power;
            power *= x; 
        }
        return result;
    }

    Polynomial add(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        double* resultCoeffs = new double[maxDegree + 1](); 

        for (int i = 0; i <= degree; ++i) {
            resultCoeffs[i] += coefficients[i];
        }

        for (int i = 0; i <= other.degree; ++i) {
            resultCoeffs[i] += other.coefficients[i];
        }

        Polynomial result(maxDegree, resultCoeffs);
        delete[] resultCoeffs; 
        return result;
    }
    
    Polynomial multiply(const Polynomial& other) const {
        int resultDegree = degree + other.degree;
        double* resultCoeffs = new double[resultDegree + 1]();

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        Polynomial result(resultDegree, resultCoeffs);
        delete[] resultCoeffs;
        return result;
    }

    void print() const {
        for (int i = degree; i >= 0; --i) {
            if (coefficients[i] != 0) {
                if (i != degree) {
                    cout << " + ";
                }
                cout << coefficients[i];
                if (i > 0) {
                    cout << "x";
                    if (i > 1) {
                        cout << "^" << i;
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {

    double coeffs1[] = {1, 2, 3}; //1+2x +3x^2
    double coeffs2[] = {4, 5};    //4+5x

    Polynomial p1(2, coeffs1);
    Polynomial p2(1, coeffs2);
    cout << "Polynomial 1: ";
    p1.print();
    cout << "Polynomial 2: ";
    p2.print();
    Polynomial sum = p1.add(p2);
    cout << "Sum: ";
    sum.print();
    Polynomial product = p1.multiply(p2);
    cout << "Product: ";
    product.print();
    cout << "Evaluation of Polynomial 1 at x = 2: " << p1.evaluate(2) << endl;
    return 0;
}
