//author: Tim Urness
//date:  August 19, 2014
//description: This program serves as an intoduction to OpenGL.  Draws a triangle

#ifdef __APPLE__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include<GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#define WIDTH 500
#define HEIGHT 400

GLfloat vertices[] = {150,100, 350,100, 450,300, 250,300};

void display(void) {
	/*clear all pixels*/
	glClear(GL_COLOR_BUFFER_BIT);

	/*set color to red*/
	glColor3f(0.1,0.5,0.8);

    glEnableClientState(GL_VERTEX_ARRAY);

    /*set pointer to vertices array*/
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_POLYGON, 0, 4); //draw the three points

    glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays

	/*process buffered OpenGL routines*/
	glFlush();
}


void init(void) {
	/*set clearing (background) color*/
	glClearColor(0.0, 0.0, 0.0, 0.0);

    glPointSize(10.0);

	/*initialize viewing values*/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

/*
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGB).  Open window with "Drake CS 147" in
 *  title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutCreateWindow("Drake CS 147");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

