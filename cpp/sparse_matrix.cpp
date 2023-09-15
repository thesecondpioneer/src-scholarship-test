I#include "sparse_matrix.h"

SparseMatrix::SparseMatrix(fs::path fname) {
    std::ifstream stream(fname);
    int32_t n_rows;
    stream >> n_rows;
    data.resize(n_rows);

    for (int32_t i = 0; i < n_rows; i++) {
        int32_t n_cols;
        stream >> n_cols;
        data[i].reserve(n_cols);
        for (int32_t j = 0; j < n_cols; j++) {
            int32_t index;
            double value;
            stream >> index >> value;
            data[i].push_back({index, value});
        }
    }
}

void SparseMatrix::Print() {
    int32_t n = data.size();
    printf("%d rows:\n", n);
    for (int32_t i = 0; i < n; i++) {
        int32_t element_index = 0;
        for (int32_t j = 0; j < n; j++) {
            if (element_index < data[i].size()) {
                if (data[i][element_index].index == j) {
                    printf("%.2f ", data[i][element_index].value);
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
SparseMatrix Eye(int32_t n){
    SparseMatrix result;
    result.data = std::vector(n,std::vector<SparseMatrix::Element>(n));
    for(int32_t i = 0; i < n; i++){
        result.data[i][i].value = 1;
        for(int32_t j = 0; j < n; j++){
            result.data[i][i].index = j;
        }
    }
}
SparseMatrix SparseMatrix::operator*(const SparseMatrix &m) {
    SparseMatrix result;
    // Here's your code
    result.data = std::vector<std::vector<Element>>(data.size(),std::vector<Element>(m.data[0].size()));
    for(int32_t i = 0; i < data.size(); i++){
        for(int32_t j = 0; j < m.data[0].size(); j++){
            if(data[i][j].value!=0){ //единственная оптимулина для спарсов до которой додумался
                for (int32_t k = 0; k < data[0].size(); k++){
                    result.data[i][k].value += data[i][j].value*m.data[k][j].value; //тут, конечно же, ошибся с индексами, в голове было умножение с учётом роликов, а написал умножение стандартное
                    result.data[i][j].index = j;
                }
            }
        }
    }
    return result;
};

SparseMatrix SparseMatrix::operator^(uint32_t p) {
    SparseMatrix result;
    // Here's your code
    //Перевести в двоичную систему степень матрицы
    //Перемножать матрицу саму на себя, сохранять матрицу, перемножать сохраненную матрицу саму на себя, по пути в резалте
    //перемножаем матрицы, степени которых соответствуют степеням двойки, на которую домножается разряд двоичной записи
    //для перевода в десятичную систему счисления
    //В резалте останется искомая степень матрицы
    //в первом коммите "наиная степень"
    //теперь эта реализация
    //если она не заработала, то может быть заработает предыдущий коммит =(
    result = Eye(data.size());
    if(p == 0){
        return result;
    }else{
        std::string s, binp;
        SparseMatrix Q = *this;
        while (p > 0){
            s.push_back(char(p%2 - '0'));
            p /= 2;
        }
        for(int32_t i = 0; i < s.size(); i++){
            if (s[i] == 1){
                result = result*Q;
            }
            Q = Q*Q;
        }
    }
    return result;
}
