/**
    
    Cube.h
    Bevgraf - 5. hazi

    @author Péter Szilvácsku
    @version 1.0 2016.12.03. 
*/

#ifndef HASAB_H
#define HASAB_H

#include <vector>
#include <iostream>
#include "Utils.h"
#include "Matrix.h"


class Hasab
{

  public:

    std::vector<Point3D> points;

    Hasab(){}


    Hasab(std::vector<Point3D> points_){

        this->points = points_;
    }
    

    void print(){

        for(int i=0; i<points.size(); i++)
            std::cout << "x= " <<  points[i].x << " y= " << points[i].y << " z= " << points[i].z << std::endl;


    }



    void draw()
    {

       glBegin(GL_LINES);
    //   glBegin(GL_POLYGON);
                //2      1
                //
                //
                //3      0
                     glColor3f(0.0, 0.0, 1.0);
				glVertex2f( points[0].x, points[0].y);
				glVertex2f( points[1].x, points[1].y);

                glVertex2f( points[1].x, points[1].y);
				glVertex2f( points[2].x, points[2].y);

                glVertex2f( points[2].x, points[2].y);
				glVertex2f( points[3].x, points[3].y);

                glVertex2f( points[3].x, points[3].y);
				glVertex2f( points[0].x, points[0].y);
                
               // glEnd();
             //    glColor3f(0.0, 0.0, 1.0);
              //  glBegin(GL_LINES);
           
                ////
                //6      5
                //
                //
                //7      4
                glVertex2f( points[4].x, points[4].y);
				glVertex2f( points[5].x, points[5].y);
            
                glVertex2f( points[5].x, points[5].y);
                glVertex2f( points[6].x, points[6].y);
                
                glVertex2f( points[6].x, points[6].y);
                glVertex2f( points[7].x, points[7].y);  

                glVertex2f( points[7].x, points[7].y);
                glVertex2f( points[4].x, points[4].y);

                ////
                //62      51
                //
                //
                //73      40
                glVertex2f( points[4].x, points[4].y);
				glVertex2f( points[0].x, points[0].y);
            
                glVertex2f( points[5].x, points[5].y);
                glVertex2f( points[1].x, points[1].y);
                
                glVertex2f( points[6].x, points[6].y);
                glVertex2f( points[2].x, points[2].y);  

                glVertex2f( points[7].x, points[7].y);
                glVertex2f( points[3].x, points[3].y);


        glEnd();

    }

};

#endif
