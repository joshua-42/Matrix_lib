#include <Matrix.hpp>

int main() {
    Matrix<int> Mint1(3, 3);
    Matrix<int> Mint2(1, 6);

    Mint1.data = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
    };

    Mint2.data = {
        1, 2, 3, 4, 5, 6
    };

    Matrix<int> Mint3 = Mint1.transpose();
    Mint3.print();
}