#include <iostream>
#include <vector>
#include <stdexcept>  // For exception handling

using namespace std;

// Exception for dimension mismatch
class DimensionMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "Matrix dimensions do not match for the operation.";
    }
};

// Generic Matrix class template
template <typename T>
class Matrix {
private:
    vector<vector<T>> data;
    size_t rows, cols;

public:
    // Constructor to create a matrix with given dimensions
    Matrix(size_t rows, size_t cols, T initial_value = T()) : rows(rows), cols(cols) {
        data.resize(rows, vector<T>(cols, initial_value));
    }

    // Method to get the number of rows
    size_t getRows() const { return rows; }

    // Method to get the number of columns
    size_t getCols() const { return cols; }

    // Method to safely access elements with bounds checking
    T& at(size_t row, size_t col) {
        if (row >= rows || col >= cols) {
            throw out_of_range("Index out of range.");
        }
        return data[row][col];
    }

    const T& at(size_t row, size_t col) const {
        if (row >= rows || col >= cols) {
            throw out_of_range("Index out of range.");
        }
        return data[row][col];
    }

    // Overloading the + operator for matrix addition
    Matrix<T> operator+(const Matrix<T>& other) {
        if (this->rows != other.rows || this->cols != other.cols) {
            throw DimensionMismatchException();
        }

        Matrix<T> result(this->rows, this->cols);

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.at(i, j) = this->at(i, j) + other.at(i, j);
            }
        }
        return result;
    }

    // Overloading the * operator for matrix multiplication
    Matrix<T> operator*(const Matrix<T>& other) {
        if (this->cols != other.rows) {
            throw DimensionMismatchException();
        }

        Matrix<T> result(this->rows, other.cols);

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                result.at(i, j) = 0;
                for (size_t k = 0; k < cols; ++k) {
                    result.at(i, j) += this->at(i, k) * other.at(k, j);
                }
            }
        }
        return result;
    }

    // Method to print the matrix
    void print() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                cout << at(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    try {
        // Create two 2x2 matrices
        Matrix<int> mat1(2, 2);
        mat1.at(0, 0) = 1;
        mat1.at(0, 1) = 2;
        mat1.at(1, 0) = 3;
        mat1.at(1, 1) = 4;

        Matrix<int> mat2(2, 2);
        mat2.at(0, 0) = 5;
        mat2.at(0, 1) = 6;
        mat2.at(1, 0) = 7;
        mat2.at(1, 1) = 8;

        // Add matrices
        Matrix<int> resultAdd = mat1 + mat2;
        cout << "Matrix Addition (mat1 + mat2):\n";
        resultAdd.print();

        // Multiply matrices
        Matrix<int> resultMul = mat1 * mat2;
        cout << "\nMatrix Multiplication (mat1 * mat2):\n";
        resultMul.print();
        
        // Attempt to access an out-of-bounds element
        cout << "\nAttempting to access an out-of-bounds element:\n";
        cout << mat1.at(2, 2) << endl; // This will throw an exception

    } catch (const DimensionMismatchException& e) {
        cout << "\nError: " << e.what() << endl;
    } catch (const out_of_range& e) {
        cout << "\nError: " << e.what() << endl;
    }

    return 0;
}
