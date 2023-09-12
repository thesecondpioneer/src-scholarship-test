import sys

from sparse_matrix import SparseMatrix


def main(argv):
    if len(argv) != 3:
        print(f'Usage: {argv[0]} MATRIX_FILE power')
        return

    m = SparseMatrix(argv[1])
    p = int(argv[2])

    m_power_2 = m @ m
    m_power_p = m ** p

    m.print()
    m_power_2.print()
    m_power_p.print()


if __name__ == '__main__':
    main(sys.argv)
