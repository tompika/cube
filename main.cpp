#include <GL/glut.h>
#include <math.h>
#include <vector>

#include "Matrix.h"
#include "Utils.h"
#include "Cube.h"
#define pi 3.14159265359	

GLsizei winWidth = 800, winHeight = 600;

GLint keyStates[256];
double DELTA = 45;
double DELTA2 = 45;
double DELTA3 = 45;
Cube cube;
Cube cube2;


void mul_matrices( float A[ ][ 4 ], float B[ ][ 4 ], float C[ ][ 4 ] )
{
int i, j, k;

float sum;

for( i = 0; i < 4; i++ )
    for( j = 0; j < 4; j++ ) {
        sum = 0;
        for( k = 0; k < 4; k++ )
            sum = sum + A[ i ][ k ] * B[ k ][ j ];
        C[ i ][ j ] = sum;
    }
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, winWidth, 0.0, winHeight);
    glShadeModel(GL_FLAT);
    glPointSize(10.0);



}

void keyOperations()
{

    if (keyStates['q'])
    {
        DELTA -= 0.1;
    }

    if (keyStates['w'])
    {
        DELTA +=0.1;
    }

    if (keyStates['a'])
    {
        DELTA3 +=0.1;
       
    }

    if (keyStates['s'])
    {
        DELTA3 -= 0.1;
       
    }

    if (keyStates['y'])
    {
        DELTA2 +=0.1;
    }

    if (keyStates['x'])
    {
        DELTA2 -=0.1;
    }

    glutPostRedisplay();
}



void display()
{
    keyOperations();    

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);

  /*          
	float S[4][4]={150, 0, 0, 0,
				 0, 150, 0, 0,
				 0, 0, 150, 0,
				 0, 0, 	 0, 1};
	
	float E[4][4]={1, 0, 0, 400,
				   0, 1, 0, 300,
				   0, 0, 1, 0,
                
				   0, 0, 0, 1};
				 
				 
/*	float VM[4][4]={1, 0, 0, 0,
				    0, 1, 0, 0,
				    0, 0, 0, 0,
				    0, 0, 0, 1};*/
    				 
	/*			 
	float VM[4][4]={1, 0, 0, 0,
				    0, 1, 0, 0,
				    0, 0, 0, 0,
				    0, 0, 0, 1};
	
	float rad = DELTA * (pi / 180);
    float rad2 = DELTA2 * (pi / 180);
	
//	std::cout << "RAD: " <<"  " << rad << std::endl;

	float FY[4][4]={cos(rad), 0, sin(rad), 0,
					0, 1, 0, 0,
					-sin(rad), 0, cos(rad), 0,
					0, 0, 0, 1};
	
	float FX[4][4]={1, 0, 0, 0,
					0, cos(rad2), -sin(rad2), 0,
					0, sin(rad2), cos(rad2), 0,
					0, 0, 0, 1};
	
    float FX2[4][4]={1, 0, 0, 0,
					0, cos(rad2), -sin(rad2), 0,
					0, sin(rad2), cos(rad2), 0,
					0, 0, 0, 1};
	
*/


    std::vector<std::vector<double>> tms = { {100, 0, 0, 0},
                                            {0, 100, 0, 0},
                                            {0, 0, 100, 0},
                                            {0, 0, 	 0, 1}};
        
    std::vector<std::vector<double>> tms2 = {{1, 0, 0, 200},
                                            {0, 1, 0, 200},
                                            {0, 0, 1, 0},
                                            {0, 0, 0, 1}};
    
        std::vector<std::vector<double>> tms22 = {  {1, 0, 0, 500},
                                                    {0, 1, 0, 200},
                                                    {0, 0, 1, 0},
                                                    {0, 0, 0, 1}};
        


    Matrix skalaz = Matrix(4,4, tms);
    Matrix eltol = Matrix(4,4, tms2);
    Matrix eltol2 = Matrix(4,4, tms22);


    
    Matrix rotX = Matrix().getRotationMatrixX(4, 4, 20);

    Matrix rotY = Matrix().getRotationMatrixY(4, 4, DELTA);
    Matrix rotY2 = Matrix().getRotationMatrixY(4, 4, DELTA2);
    Matrix rotY3 = Matrix().getRotationMatrixY(4, 4, DELTA3);

    Matrix merolegesVet = Matrix().getMerolegesMatrix(4,4);
    Matrix centralisVet = Matrix().getCentralisMatrix(4,4, 350);

                            //x_min, x_max, y min, y max, u min, u max, v min, v max
    Matrix WTV = cube.calcWTV(-1, 1,    -1, 1,    300,600,     300,600);
    //WTV.display();
    
    //Matrix M = WTV*(merolegesVet * rotX * rotY);
    
    


    //M.display();

    Matrix M    = eltol * ( merolegesVet *rotX * rotY * skalaz);
    Matrix M2   = eltol * ( merolegesVet *rotX * rotY2 * skalaz);
    Matrix M3   = eltol * ( merolegesVet *rotX * rotY3 * skalaz);

    Matrix M_    = eltol2 * ( centralisVet *rotX * rotY * skalaz);
    Matrix M2_   = eltol2 * ( centralisVet *rotX * rotY2 * skalaz);
    Matrix M3_   = eltol2 * ( centralisVet *rotX * rotY3 * skalaz);

    
	
    cube = Cube();
    cube2 = Cube();
      

   // cube.h1.print();
    cube.transformH1(M);
    cube.transformH2(M2);
    cube.transformH3(M3);

    cube2.transformH1(M_);
    cube2.transformH2(M2_);
    cube2.transformH3(M3_);

    cube2.draw();
    cube.draw();


    glutSwapBuffers();
   
}

/*void update(int n)
{
    


    glutPostRedisplay();

    glutTimerFunc(5, update, 0);
}*/


void keyPressed(unsigned char key, int x, int y)
{
    keyStates[key] = 1;
}

void keyUp(unsigned char key, int x, int y)
{
    keyStates[key] = 0;
}


int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(winWidth, winHeight);
    glutInitWindowPosition(10, 10);

    glutCreateWindow("Cube - Szilvacsku Peter");
    init();

    glutDisplayFunc(display);

 //   glutMouseFunc(processMouse);
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyUp);

   // glutTimerFunc(5, update, 0);

    glutMainLoop();
    return 0;
}