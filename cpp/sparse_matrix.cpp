#include "sparse_matrix.h"

SparseMatrix::SparseMatrix(std::ifstream stream) {
    int32_t n_rows;
    stream >> n_rows;
    data_.resize(n_rows);

    for (int32_t i = 0; i < n_rows; i++) {
        int32_t n_cols;
        stream >> n_cols;
        data_[i].reserve(n_cols);
        for (int32_t j = 0; j < n_cols; j++) {
            int32_t index;
            double value;
            stream >> index >> value;
            data_[i].push_back({index, value});
        }
    }
}

void SparseMatrix::Print() {
    int32_t n = data_.size();
    printf("%d rows:\n", n);
    for (int32_t i = 0; i < n; i++) {
        int32_t element_index = 0;
        for (int32_t j = 0; j < n; j++) {
            if (element_index < data_[i].size()) {
                if (data_[i][element_index].index == j) {
                    printf("%.2f ", data_[i][element_index].value);
                    element_index++;
                } else {
                    printf("%.2f ", 0.);
                }
            } else {
                printf("%.2f ", 0.);
            }
        }
        printf("\n");
    }
}

SparseMatrix SparseMatrix::operator*(const SparseMatrix &m) {
    SparseMatrix result;
    // Here's your code
    return result;
};

SparseMatrix SparseMatrix::Power(uint32_t p) {
    SparseMatrix result;
    // Here's your code
    return result;
}