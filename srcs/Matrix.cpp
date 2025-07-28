#include <Matrix.hpp>

int main() {
    Matrix<int> Mint1(4, 1);
    Matrix<int> Mint2(1, 6);

    Mint1.data = {
        1,
        2,
        3,
        4
    };

    Mint2.data = {
        1, 2, 3, 4, 5, 6
    };

    try {
        Mint1 = Mint1 * Mint2;
        Mint1.print();
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}