#include <bits/stdc++.h>
#include "function.h"
using namespace std;

std::ostream &operator<<(std::ostream &output, const Matrix &ma)
{
    int i = 0, j = 0;
    for(i = 0; i < ma.size; i++){
        for(j = 0; j < ma.size - 1; j++){
            cout << ma.matrix[i][j] << " ";
        }
        cout << ma.matrix[i][j] << endl;
    }
    return output;
}

std::istream &operator>>(std::istream &input, Matrix &ma)
{
    for(int i = 0; i < ma.size; i++){
        for(int j = 0; j < ma.size; j++){
            input >> ma.matrix[i][j];
        }
    }
    return input;
}

Matrix::Matrix(int s):size(s),buf(nullptr){
    matrix = new int* [size];
    for(int i = 0; i < size; i++)
        matrix[i] = new int [size];
}

