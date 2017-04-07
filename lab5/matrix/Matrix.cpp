//
// Created by kerni on 04.04.2017.
//

#include <complex>
#include "Matrix.h"


using algebra::Matrix;

Matrix::Matrix(int n, int m) {
    this->n=n;
    this->m=m;
    macierz = new complex<double>*[n];
    for (int i=0; i<n; ++i){
        macierz[i] = new complex<double>[m];
    }

}

Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> matrix_list) {

    int num_row = int(matrix_list.size());
    unsigned long num_col =0;
    for(auto row : matrix_list)
    {
        num_col = row.size();
        break;
    }

    n = int(num_col);
    m = num_row;

    std::complex<double> **tablica = new std::complex<double>  *[m];
    for (int i=0; i< m; i++)
        tablica[i]=new std::complex<double>  [n];
    macierz = tablica;
    macierz[0][0] = 1.0 + 1.0i;


    int i=0;
    int j=0;
    for(std::vector<std::complex<double>> row : matrix_list)
    {
        j=0;
        for(std::complex<double> element : row)
        {
            macierz[i][j] = element;
            j++;
        }
        i++;
    }
}

Matrix::Matrix() {
    //cout << "Macierz"<<endl;
    n=0;
    m=0;
}

Matrix::Matrix(std::string matlab) {
    int n = 1, m = 1;
    string::size_type sz;
    string liczba = "", liczba_re = "", liczba_im = "";
    double liczba_double, liczba_re_double,liczba_im_double;
    for (string::iterator it = matlab.begin(); it < matlab.end(); it++) {
        if (*it == 32) m++;
        if (*it == 59) n++;
    }
    m=m/n;
    this->n = n;
    this->m = m;
    macierz = new complex<double> *[n];
    for (int i = 0; i < n; i++) {
        macierz[i] = new complex<double>[m];
    }

    int i = 0, j = 0;
    for (string::iterator it = matlab.begin(); it != matlab.end(); ++it) {
        if ((*it <= 57 && *it >= 48) ||  *it == 105 || *it == 46) {
            //cout << *it << "   ";
            liczba += *it;

        }
        else if (*it == 32 || *it == 93) {
            if (liczba.find("i") != string::npos) { //If "i" exists

                liczba_re = liczba.substr(0, liczba.find("i"));
                liczba_im = liczba.substr(liczba.find("i")+1, liczba.length()-liczba.find("i"));

                liczba_re_double = stod(liczba_re, &sz);
                liczba_im_double = stod(liczba_im, &sz);
                macierz[i][j] = complex<double>(liczba_re_double, liczba_im_double);
                j++;
                liczba = "";
                liczba_re = "";
                liczba_im = "";
            } else {
                liczba_double = stod(liczba, &sz);
                macierz[i][j] = complex<double>(liczba_double);
                j++;
                liczba = "";
            }
        }
        else if (*it == 59) {
            if (liczba.find("i") != string::npos) {

                liczba_re = liczba.substr(0, liczba.find("i"));
                liczba_im = liczba.substr(liczba.find("i")+1, liczba.length()-liczba.find("i"));

                liczba_re_double = stod(liczba_re, &sz);
                liczba_im_double = stod(liczba_im, &sz);
                macierz[i][j] = complex<double>(liczba_re_double, liczba_im_double);
                i++;
                j=0;
                liczba = "";
                liczba_re = "";
                liczba_im = "";
            } else {
                liczba_double = stod(liczba, &sz);
                macierz[i][j] = complex<double>(liczba_double);
                i++;
                j=0;
                liczba = "";

            }
            *it++;
        }
    }

}


Matrix::Matrix(Matrix &m1) {
    n = m1.n;
    m = m1.m;
    macierz = new complex<double>*[n];
    for (int i=0; i<n; ++i){
        macierz[i] = new complex<double>[m];
        for(int j=0; j<m; j++)
        {
            macierz[i][j]=m1.macierz[i][j];
        }
    }
}


string Matrix::Print(){

    std::ostringstream data;
    data << "[";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            data << std::real(macierz[i][j]) << "i" << std::imag(macierz[i][j]);

            if (j == n-1 && i != m-1) {
                data << "; ";
            }
            else if (i != n-1 || j != m-1) {
                data << ", ";
            }
        }
    }

    data << "]";
    return data.str();
}

Matrix::~Matrix() {
    //cout << "Macierz deleted"<<endl;
    for (int i = 0; i < n; i++) {
        delete [] macierz[i];
    }
    delete [] macierz;
}

pair<size_t, size_t> Matrix::Size() {
    return make_pair(n,m);
    }

Matrix Matrix::Add( Matrix matrix) {
    Matrix wynik = *this;

    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < m; j++) {
            wynik.macierz[i][j] = (this->macierz[i][j]) + (matrix.macierz[i][j]);
        }
    }
    return wynik;
}

Matrix Matrix::Mul( Matrix matrix) {
    if (n != matrix.getWidth()) {
        throw "Wrong matrixes sizes!";
    }

    Matrix m3(n, matrix.getWidth());

    for (int o = 0; o < n; o++) {
        for (int p = 0; p < matrix.getWidth(); p++) {
            m3.getMatrix()[o][p] = 0;
            for (int k = 0; k < matrix.getHeight(); k++) {
                m3.getMatrix()[o][p] += macierz[o][k] * matrix.getMatrix()[k][p];
            }
        }
    }

    return m3;
}

Matrix Matrix::Mul(complex<double> multiplier) {
    Matrix m3(n, m);
    for (int o = 0; o < n; o++) {
        for (int p = 0; p < m; p++) {
            m3.getMatrix()[o][p] = macierz[o][p] * multiplier;
        }
    }
    return m3;
}

Matrix Matrix::Sub(Matrix matrix) {
    if (m != matrix.getWidth() || n != matrix.getHeight()) { //Dummyproof code
        throw "Matrixes must be same size!";
    }
    Matrix m3(matrix.getHeight(), matrix.getWidth());
    for (int o = 0; o < n; o++) {
        for (int p = 0; p < m; p++) {
            m3.getMatrix()[o][p] = macierz[o][p] - matrix.getMatrix()[o][p];
        }
    }
    return m3;
}

Matrix Matrix::Pow(int value) {
    Matrix m3 = *this;

    for (int i=0; i<value; i++){
        m3 = m3.Mul(*this);
    }
    return m3;
}

complex<double> **Matrix::getMatrix() {
    return macierz;
}

int Matrix::getHeight() {
    return n;
}

int Matrix::getWidth() {
    return m;
}
