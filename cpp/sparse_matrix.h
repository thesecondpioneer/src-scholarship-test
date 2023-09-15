#ifndef INTERNSHIP_TEST_SPARSE_MATRIX_H
#define INTERNSHIP_TEST_SPARSE_MATRIX_H

#include <filesystem>
#include <fstream>
#include <vector>

namespace fs = std::filesystem;

class SparseMatrix {
public:
    struct Element {
        int32_t index;
        double value;
    };

    explicit SparseMatrix() {}
    SparseMatrix(fs::path fname);

    void Print();

    SparseMatrix operator*(const SparseMatrix &m);
    SparseMatrix operator^(uint32_t p);

    std::vector<std::vector<Element>> data;
    friend SparseMatrix Eye(int32_t n);
};

#endif  // INTERNSHIP_TEST_SPARSE_MATRIX_H