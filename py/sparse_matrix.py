from typing import List


class Element:
    def __init__(self, index, value):
        self.index = index
        self.value = value


class SparseMatrix:
    def __init__(self, file=None):
        self.data_: List[List[Element]] = []
        if file:
            with open(file, 'r') as f:
                n = int(f.readline())
                for _ in range(n):
                    self.data_.append([])
                    line = f.readline().split()
                    for j in range(1, len(line), 2):
                        self.data_[-1].append(Element(index=int(line[j]),
                                                      value=float(line[j+1])))

    def print(self):
        n = len(self.data_)
        print(f'{len(self.data_)} rows')
        for i in range(n):
            element_index = 0
            for j in range(n):
                if element_index < len(self.data_[i]):
                    if self.data_[i][element_index].index == j:
                        print(f'{self.data_[i][element_index].value:.2f} ', end='')
                    else:
                        print(f'{0:.2f} ', end='')
                else:
                    print(f'{0:.2f} ', end='')
            print()

    def __matmul__(self, other):
        result = SparseMatrix()
        # your code here
        return result

    def __pow__(self, power, modulo=None):
        result = SparseMatrix()
        # your code here
        return result
