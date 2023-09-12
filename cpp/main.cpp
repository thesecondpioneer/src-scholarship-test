#include <iostream>

#include "sparse_matrix.h"
#include "utils.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s MATRIX_FILE power\n", argv[0]);
        exit(0);
    }

    SparseMatrix m(GetInputStream(argv[1]));
    uint32_t p = atoi(argv[2]);

    auto m_power_2 = m * m;
    auto m_power_p = m.Power(p);

    m.Print();
    m_power_2.Print();
    m_power_p.Print();

    return 0;
}
