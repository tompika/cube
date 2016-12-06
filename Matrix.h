/**
    
    Matrix.h
    Bevgraf - 3. hazi

    @author Péter Szilvácsku
    @version 1.0 2016.11.10. 
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#define pi 3.14159265359

class Matrix
{

  public:
    double **data;
    int m, n;

    Matrix()
    {
    }

    Matrix(int n, int m)
    {
        this->n = n;
        this->m = m;

        data = new double *[n];
        for (int i = 0; i < n; i++)
            data[i] = new double[m];
    }

    Matrix(int n, int m, std::vector<std::vector<double>> data_)
    {
        this->n = n;
        this->m = m;
        data = new double *[n];
        for (int i = 0; i < n; i++)
            data[i] = new double[m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                data[i][j] = data_[i][j];
            }
        }
    }

    Matrix operator*(const Matrix Other)
    {

        Matrix ret = Matrix(n, Other.m);
        float sum;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < Other.m; j++)
            {
                sum = 0;
                for (int k = 0; k < Other.m; k++)
                    sum = sum + this->data[i][k] * Other.data[k][j];
                ret.data[i][j] = sum;
            }

        return ret;
    }

    Matrix getRotationMatrixX(int n, int m, double angle)
    {

        double rad = angle * (pi / 180);
        std::vector<std::vector<double>> tmp = {{1, 0, 0, 0},
                                                {0, cos(rad), -sin(rad), 0},
                                                {0, sin(rad), cos(rad), 0},
                                                {0, 0, 0, 1}};
        return Matrix(n, m, tmp);
    }

    Matrix getRotationMatrixY(int n, int m, double angle)
    {

        double rad = angle * (pi / 180);

        std::vector<std::vector<double>> tmp = {{cos(rad), 0, sin(rad), 0},
                                                {0, 1, 0, 0},
                                                {-sin(rad), 0, cos(rad), 0},
                                                {0, 0, 0, 1}};
        return Matrix(n, m, tmp);
    }


    Matrix getMerolegesMatrix(int n, int m){
        std::vector<std::vector<double>> tmp = {{1, 0, 0, 0},
                                                {0, 1, 0, 0},
                                                {0, 0, 0, 0},
                                                {0, 0, 0, 1}};

        return Matrix(n, m, tmp);


    }
    Matrix getCentralisMatrix(int n, int m, double s){
          std::vector<std::vector<double>> tmp = {{1, 0, 0, 0},
                                                {0, 1, 0, 0},
                                                {0, 0, 0, 0},
                                                {0, 0, -1/s, 1}};

        return Matrix(n, m, tmp);

    }

    void display()
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cout << data[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
};

#endif
