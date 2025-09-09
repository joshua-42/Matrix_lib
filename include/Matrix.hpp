#pragma once

#include <cmath>
#include <vector>
#include <iostream>

// namespace Matrix {

    template<typename T>class Matrix {
        public :
            size_t          rows, cols;
            std::vector<T>  data;

            Matrix(size_t r, size_t c) : rows(r), cols(c), data(r * c){}

            size_t getIndex(size_t i, size_t j) const{
                return (i * cols + j);
            }

            T &operator()(size_t i, size_t j) {
                return(data[getIndex(i, j)]);
            }

            const T &operator()(size_t i, size_t j) const{
                return(data[getIndex(i, j)]);
            }

            void print() const {
                for (size_t i = 0; i < rows; i++) {
                    std::cout << "[ ";
                    for (size_t j = 0; j < cols; j++) {
                        std::cout << operator()(i, j) << " ";
                    }
                    std::cout << "]\n";
                }
            }

            Matrix<T> transpose() const {
                 Matrix<T> result(cols, rows);

                 for (size_t i = 0; i < rows; i++) {
                    for (size_t j = 0; j < cols; j++) {
                        result(j, i) = (*this)(i, j);
                    }
                 }
                 return result;
            }

            Matrix operator+(const Matrix& other) const {
                Matrix<T>   tmp(rows, cols);

                if (rows != other.rows || cols != other.cols) {
                    throw std::invalid_argument("Addition error: matrices must have the same dimensions.");
                }
                for (size_t i = 0; i < rows; i++) {
                    for (size_t j = 0; j < cols; j++) {
                        tmp(i, j) = (*this)(i, j) + other(i, j);
                    }
                }
                return tmp;
            }

            Matrix operator-(const Matrix &other) const {
                Matrix<T>   tmp(rows, cols);

                if (rows != other.rows || cols != other.cols) {
                    throw std::invalid_argument("Addition error: matrices must have the same dimensions.");
                }
                for (size_t i = 0; i < rows; i++) {
                    for (size_t j = 0; j < cols; j++) {
                        tmp(i, j) = (*this)(i, j) - other(i, j);
                    }
                }
                return tmp;
            }

            Matrix operator*(const T& scalar) const {
                Matrix<T>   tmp(rows, cols);

                for (size_t i = 0; i < rows; i++) {
                    for (size_t j = 0; j < cols; j++) {
                        tmp(i, j) = (*this)(i, j) * scalar;
                    }
                }
                return tmp;
            }

            Matrix operator*=(const T& scalar) {
                for (size_t i = 0; i < rows; i++) {
                    for (size_t j = 0; j < cols; j++) {
                        (*this)(i, j) *= scalar;
                    }
                }
                return *this;
            }

            Matrix operator*(const Matrix& other) const{
                Matrix<T> tmp(rows, other.cols);

                if (this->cols != other.rows) {
                    throw std::invalid_argument("Multiplication error : matrix of right must have the same number of rows then the number of colums of the right matrix");
                }
                for (size_t i = 0; i < rows; i++) {
                    for (size_t j = 0; j < other.cols; j++) {
                        tmp(i, j) = 0;
                        for (size_t k = 0; k < cols; k++) {
                            tmp(i, j) += (*this)(i, k) * other(k, j);
                        }
                    }
                }
                return tmp;
            }
    };
// }