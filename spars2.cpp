#include <iostream>
#include <vector>

using namespace std;

// ساختار داده‌ای برای نگهداری مقادیر غیرصفر در ماتریس
struct SparseMatrixElement {
    int row;
    int col;
    int value;
};

// تابعی برای نمایش ماتریس اسپارس
void printSparseMatrix(const vector<SparseMatrixElement>& sparseMatrix) {
    int size = sparseMatrix.size();

    for (int i = 0; i < size; i++) {
        cout << sparseMatrix[i].row << " " << sparseMatrix[i].col << " " << sparseMatrix[i].value << endl;
    }
}

int main() {
    // ماتریس اسپارس
    vector<SparseMatrixElement> sparseMatrix;

    // افزودن مقادیر غیرصفر به ماتریس اسپارس
    SparseMatrixElement element1 = {0, 1, 2};
    SparseMatrixElement element2 = {1, 2, 3};
    SparseMatrixElement element3 = {2, 0, 4};

    sparseMatrix.push_back(element1);
    sparseMatrix.push_back(element2);
    sparseMatrix.push_back(element3);

    // نمایش ماتریس اسپارس
    printSparseMatrix(sparseMatrix);

    return 0;
}
