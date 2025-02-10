#include <iostream>
#include <vector>
using namespace std;
class Matrix {
private:
    int rows;
    int cols;
    vector<vector<int>> elements; 

public:
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        elements = vector<vector<int>>(rows, vector<int>(cols, 0)); 
    }
    int getRows() { return this->rows; }
    int getCols() { return this->cols; }
    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            elements[i][j] = value;
        } else {
            cout << "Invalid index (" << i << "," << j << ")\n";
        }
    }
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }
    Matrix add(Matrix &other) {
        if (this->rows != other.getRows() || this->cols != other.getCols()) {
            cout << "Matrices cannot be added\n";
            return Matrix(0, 0); 
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.elements[i][j] = this->elements[i][j] + other.elements[i][j];
            }
        }
        return result;
    }
    Matrix multiply(Matrix &other) {
        if (this->cols != other.getRows()) {
            cout << "Matrices cannot be multiplied\n";
            return Matrix(0, 0);
        }
        Matrix result(this->rows, other.getCols());
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < other.getCols(); j++) {
                result.elements[i][j] = 0;
                for (int k = 0; k < this->cols; k++) {
                    result.elements[i][j] += this->elements[i][k] * other.elements[k][j];
                }
            }
        }
        return result;
    }
};
int main() {
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);
    mat1.setElement(0, 0, 1);
    mat1.setElement(0, 1, 2);
    mat1.setElement(1, 0, 3);
    mat1.setElement(1, 1, 4);
    mat2.setElement(0, 0, 5);
    mat2.setElement(0, 1, 6);
    mat2.setElement(1, 0, 7);
    mat2.setElement(1, 1, 8);
    cout << "Matrix 1:\n";
    mat1.display();
    cout << "Matrix 2:\n";
    mat2.display();
    Matrix sum = mat1.add(mat2);
    cout << "Sum of matrices:\n";
    sum.display();
    Matrix product = mat1.multiply(mat2);
    cout<<"Product of matrices:\n";
    product.display();
    return 0;
}

