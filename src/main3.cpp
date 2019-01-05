/*
* RedSquare.c
*
*   This program draws a red rectangle on a blue background.
*
*/
 
#include "GL/glut.h"
 
void display(void)
{
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);
 
    glColor3f(1.0, 0.0, 0.0);
    /* draw unit square polygon */
    glPushMatrix();
        glTranslated(0.0,0.2,-6);
        glutSolidSphere(1,50,50);
    glPopMatrix(); 
 
    /* flush GL buffers */
    glFlush();
}
 
void init()
{
    /* set clear color to blue */
    glClearColor (0.3, 0.4, 1.0, 0.0);
 
    /* set fill color to red */
    
 
    /* set up standard orthogonal view with clipping */
    /* box as cube of side 2 centered at origin */
    /* This is default view and these statement could be removed */
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
 
int main(int argc, char** argv)
{
    /* Initialize mode and open a window in upper left corner of screen */
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("A simple GLUT program: Red Square");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}
