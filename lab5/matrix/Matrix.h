//
// Created by kerni on 04.04.2017.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H
#include <cstdlib>
#include <string>
#include <iostream>
#include <complex>
#include <vector>



using namespace std;

namespace algebra {
    class Matrix {

        complex<double> **macierz;
        int n,m;
        //int d_row, d_col;
        //std::vector<std::vector<double>> &matrix1;

    public:
        Matrix (int, int);
        Matrix(std::initializer_list<std::vector<std::complex<double>>> matrix_list);
        Matrix ();
        Matrix (std::string);
        Matrix(Matrix &m1);
        string Print();
        ~Matrix();
        pair<size_t, size_t> Size();
        Matrix Add(Matrix m1);
        Matrix Mul(Matrix m1);
        Matrix Mul(complex<double> number);
        Matrix Sub(Matrix matrix);
        Matrix Pow(int value);
        complex<double> **getMatrix();
        int getWidth();
        int getHeight();
    };
}

#endif //JIMP_EXERCISES_MATRIX_H
