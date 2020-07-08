//Prof. Marco Antonio, abr/2020, ST765 FT UNICAMP
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
//#include "image.h"


static int rodatudo = 0;

void init(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();

	glRotatef((GLfloat)rodatudo, 0.0, 1.0, 0.0);

	//chao

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.8, 0.0);
	glVertex3f(-15, 1.5, 15);
	glVertex3f(15, 1.5, 15);
	glVertex3f(15, 1.5, -15);
	glVertex3f(-15, 1.5, -15);
	glEnd();
	/*glColor3f(0.5, 0.5, 0.0);
	glPushMatrix();
	glScalef(30.0, 1.0, 30.0);
	glutSolidCube(1.0);
	glPopMatrix();*/

	//cadeira

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(5.0, 0.0, 0.0);
	glScalef(0.5, 8.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(9.0, 0.0, 0.0);
	glScalef(0.5, 8.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	//encosto
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(7.0, 2.0, 0.0);
	glScalef(4.0, 4.0, 0.0);
	glutSolidCube(1.0);
	glPopMatrix();

	//assento
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(7.0, -1.0, -2.0);
	glScalef(5.0, 0.5, 4.0);
	glutSolidCube(1.0);
	glPopMatrix();

	//pernas
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(5.0, -2.5, -3.5);
	glScalef(0.5, 4.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(9.0, -2.5, -3.5);
	glScalef(0.5, 4.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();



	//mesa
	//tampo
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(7.5, 2.5, -5.0);
	glScalef(15.0, 0.5, 8.0);
	glutSolidCube(1.0);
	glPopMatrix();


	//pernas
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.5, -1.0, -2.0);
	glScalef(0.5, 6.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(14.5, -1.0, -2.0);
	glScalef(0.5, 6.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(14.5, -1.0, -8.0);
	glScalef(0.5, 6.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.5, -1.0, -8.0);
	glScalef(0.5, 6.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	//maça
	glColor3f(6,0.0,0);
	glPushMatrix();
	glTranslatef(2.5, 3.0, -3.0);
	glutSolidSphere(0.5, 10, 8);
	glPopMatrix();

	//cabo Maça
	glColor3f(0.0, 0.5, 0.0);
	glPushMatrix();
	glTranslatef(2.5, 3.5, -3.0);
	glScalef(0.2, 0.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//objeto Chakeira
	glColor3f(0.0, 0.0, 0.5);
	glPushMatrix();
	glTranslatef(7.5, 3.0, -6.0);
	glScalef(0.5, 0.8, 0.5);
	glutSolidTeapot(1.0);
	glPopMatrix();


	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(55.0, (GLfloat)w / (GLfloat)h, 1.0, 60.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, -8.0, -30.0);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'r':
		rodatudo = (rodatudo + 5) % 360;
		glutPostRedisplay();
		break;
	case 't':
		rodatudo = (rodatudo - 5) % 360;
		glutPostRedisplay();
		break;
	case 27:                                         // tecla Esc (encerra o programa)
		exit(0);
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

