#ifndef INTERNSHIP_TEST_SPARSE_MATRIX_H
#define INTERNSHIP_TEST_SPARSE_MATRIX_H

#include <fstream>
#include <vector>

class SparseMatrix {
   public:
    struct Element {
        int32_t index;
        double value;
    };

    explicit SparseMatrix() {}
    SparseMatrix(std::ifstream stream);

    void Print();

    SparseMatrix operator*(const SparseMatrix &m);

    SparseMatrix Power(uint32_t p);

   private:
    std::vector<std::vector<Element>> data_;
};

#endif  // INTERNSHIP_TEST_SPARSE_MATRIX_H
