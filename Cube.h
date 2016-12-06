/**
    
    Cube.h
    Bevgraf - 5. hazi

    @author Péter Szilvácsku
    @version 1.0 2016.12.03. 
*/

#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include <iostream>
#include "Utils.h"
#include "Matrix.h"
#include "Hasab.h"

class Cube
{

  public:
    Hasab h1;
    Hasab h2;
    Hasab h3;



    Cube()
    {

        Point3D c0, c1, c2, c3, c4, c5, c6, c7;

        std::vector<Point3D> point;


        c0 = initPoint3D(0.6, 0.6, -0.6);
        c1 = initPoint3D(0.6, 0.2, -0.6);
        c2 = initPoint3D(-0.6, 0.2, -0.6);
        c3 = initPoint3D(-0.6, 0.6, -0.6);

        point.push_back(c0);
        point.push_back(c1);
        point.push_back(c2);
        point.push_back(c3);

        c4 = initPoint3D(0.6, 0.6, 0.6);
        c5 = initPoint3D(0.6, 0.2, 0.6);
        c6 = initPoint3D(-0.6, 0.2, 0.6);
        c7 = initPoint3D(-0.6, 0.6, 0.6);
        point.push_back(c4);
        point.push_back(c5);
        point.push_back(c6);
        point.push_back(c7);

    
        this->h1 = Hasab(point);
         /*************2.**************/

        point.clear();

        c0 = initPoint3D(0.6, -0.6, -0.6);
        c1 = initPoint3D(0.6, -0.2, -0.6);
        c2 = initPoint3D(-0.6, -0.2, -0.6);
        c3 = initPoint3D(-0.6, -0.6, -0.6);

        point.push_back(c0);
        point.push_back(c1);
        point.push_back(c2);
        point.push_back(c3);

        c4 = initPoint3D(0.6, -0.6, 0.6);
        c5 = initPoint3D(0.6, -0.2, 0.6);
        c6 = initPoint3D(-0.6, -0.2, 0.6);
        c7 = initPoint3D(-0.6, -0.6, 0.6);

        point.push_back(c4);
        point.push_back(c5);
        point.push_back(c6);
        point.push_back(c7);

        this->h2 = Hasab(point);


        /*************3.**************/
        point.clear();

        c0 = initPoint3D(0.6, -0.2, -0.6);
        c1 = initPoint3D(0.6, 0.2, -0.6);
        c2 = initPoint3D(-0.6, 0.2, -0.6);
        c3 = initPoint3D(-0.6, -0.2, -0.6);

        point.push_back(c0);
        point.push_back(c1);
        point.push_back(c2);
        point.push_back(c3);

        c4 = initPoint3D(0.6, -0.2, 0.6);
        c5 = initPoint3D(0.6, 0.2, 0.6);
        c6 = initPoint3D(-0.6, 0.2, 0.6);
        c7 = initPoint3D(-0.6, -0.2, 0.6);

        point.push_back(c4);
        point.push_back(c5);
        point.push_back(c6);
        point.push_back(c7);

        this->h3 = Hasab(point);
    }
    Matrix calcWTV(double x_min, double x_max, double y_min, double y_max, double u_min, double u_max, double v_min, double v_max)
    {

        std::vector<std::vector<double>> T1_vec = {{1, 0, -x_min},
                                                   {0, 1, -y_min},
                                                   {0, 0, 1}};

        std::vector<std::vector<double>> S_vec = {{ (u_max - u_min) / (x_max - x_min), 0, 0},
                                                  {0, (v_max - v_min) / (y_max - y_min), 0},
                                                  {0, 0, 1}};

        std::vector<std::vector<double>> T2_vec ={ {1,  0, u_min},
                                                    {0, 1, v_min},
                                                    {0, 0, 1}};

        Matrix T1   = Matrix(3,3, T1_vec);
        Matrix S    = Matrix(3,3, S_vec);
        Matrix T2   = Matrix(3,3, T2_vec);

        Matrix VTW = T2 * (T1 * S) ;

     //   VTW.display();
   
        return VTW;

    }
    void transformH1(Matrix M)
    {

        for (int i = 0; i < h1.points.size(); i++)
        {

            float tmp[4] = {h1.points[i].x, h1.points[i].y, h1.points[i].z, 1};
            float res[M.n];

            for (int j = 0; j < M.n; j++)
            {   
                res[j] = 0;
                for (int k = 0; k < M.m; k++)
                    res[j] += M.data[j][k] * tmp[k];

            }

            //std::cout <<tmp[0] <<" " <<tmp[1] << " " <<tmp[2] << std::endl;
            
            h1.points[i].x = res[0]/res[M.n-1];
            h1.points[i].y = res[1]/res[M.n-1];
        }
    }

    void transformH2(Matrix M)
    {

        for (int i = 0; i < h2.points.size(); i++)
        {

            float tmp[4] = {h2.points[i].x, h2.points[i].y, h2.points[i].z, 1};
            float res[M.n];

            for (int j = 0; j < M.n; j++)
            {   
                res[j] = 0;
                for (int k = 0; k < M.m; k++)
                    res[j] += M.data[j][k] * tmp[k];

            }

            //std::cout <<tmp[0] <<" " <<tmp[1] << " " <<tmp[2] << std::endl;

            h2.points[i].x = res[0]/res[M.n-1];
            h2.points[i].y = res[1]/res[M.n-1];
        }
    }

    void transformH3(Matrix M)
    {

        for (int i = 0; i < h3.points.size(); i++)
        {

        float tmp[4] = {h3.points[i].x, h3.points[i].y, h3.points[i].z, 1};
        float res[M.n];

    
    
            for (int j = 0; j < M.n; j++)
            {   
                res[j] = 0;
                for (int k = 0; k < M.m; k++)
                    res[j] += M.data[j][k] * tmp[k];

            }

            //std::cout <<res[0] <<" " <<res[1] << " " <<res[2] << std::endl;

            h3.points[i].x = res[0]/res[M.n-1];
            h3.points[i].y = res[1]/res[M.n-1];
        }
    }

    void draw()
    {
        h1.draw();
        h2.draw();
        h3.draw();
    }
};

#endif
