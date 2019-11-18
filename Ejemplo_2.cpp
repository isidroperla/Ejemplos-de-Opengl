#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

void cuadricula(int xmin, int xmax, int ymin, int ymax){
	
	glColor3f (0, 0, 0);
	glLineWidth(1);
	
	glBegin(GL_LINES);
    
    glVertex2f(0,ymin);
    glVertex2f(0,ymax);
    
    glVertex2f(xmin,0);
    glVertex2f(xmax,0);
    
    for(int i=xmin; i<=xmax; i++){
		
		glVertex2f(i,0.1);
		glVertex2f(i,-0.1);
		
		}
		
	 for(int i=ymin; i<=ymax; i++){
		
		glVertex2f(-0.1,i);
		glVertex2f(0.1,i);
		
		}
    
    glEnd();
	
	}
	
void figura(void){
	
	glColor3f (0.803, 0, 0.207);
    glPointSize(3);
    
    glBegin(GL_POINTS);
    
    double x, y ,t;
    
    for(double i=0; i<=360; i+=0.05){
		
		t = (i*(2*M_PI)/360);
		
		x = (6.15*cos(3*t))*cos(t);
		y = (6.15*cos(3*t))*sin(t);
    
		glVertex2f(x,y);
		
		}
    
    glEnd();
	
	}
	
void display(void)
{
	glClearColor(1, 1, 0.796, 1.0);
    glClear (GL_COLOR_BUFFER_BIT);
     
    cuadricula(-10, 10, -10, 10);
    
    figura();
    
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -10, 10);

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (900, 750);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("EJERCICIO 6");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
