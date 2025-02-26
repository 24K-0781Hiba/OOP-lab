#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
private:
    int rows, cols;
    double* data;

public:
    Matrix() : rows(0), cols(0), data(nullptr) {}

    Matrix(int r, int c) : rows(r), cols(c) {
        data = (rows > 0 && cols > 0) ? new double[rows * cols]() : nullptr;
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        if (other.data) {
            data = new double[rows * cols];
            for (int i = 0; i < rows * cols; ++i) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }

    Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(other.data) {
        other.rows = other.cols = 0;
        other.data = nullptr;
    }

    ~Matrix() {
        delete[] data;
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this;

        delete[] data;
        rows = other.rows;
        cols = other.cols;
        if (other.data) {
            data = new double[rows * cols];
            for (int i = 0; i < rows * cols; ++i) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
        return *this;
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    double& at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw out_of_range("Matrix index out of bounds");
        }
        return data[r * cols + c];
    }

    const double& at(int r, int c) const {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw out_of_range("Matrix index out of bounds");
        }
        return data[r * cols + c];
    }

    void fill(double value) {
        if (data) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] = value;
            }
        }
    }

    Matrix transpose() const {
        Matrix transposed(cols, rows);
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                transposed.at(c, r) = at(r, c);
            }
        }
        return transposed;
    }

    void print() const {
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                cout << setw(8) << at(r, c) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix m(2, 3);
    m.fill(10.2);
    m.at(1, 2) = 9.8;
    cout << "Original matrix:\n";
    m.print();

    cout << "\nTransposed matrix:\n";
    Matrix transposed = m.transpose();
    transposed.print();

    return 0;
}
