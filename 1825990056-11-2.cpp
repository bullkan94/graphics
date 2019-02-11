#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#define PI 3.141592
#define SIN(x) sin(2 * PI * ((x) / 360.0))
#define COS(x) cos(2 * PI * ((x) / 360.0))
#define TAN(x) tan(2 * PI * ((x) / 360.0))

GLdouble vertex[][3] = {
	{ 0.0, 0.0, 0.5 },
	{ -0.4, 0.0, -0.3 },
	{ 0.5, 0.0, 0.0 },
	{ 0.0, 0.5, 0.0 },
	{ 0.0, -0.5, 0.0 }
};

GLdouble color[][3] = {
	{ 1.0, 0.0, 0.0 },
	{ 0.0, 1.0, 0.0 },
	{ 0.0, 0.0, 1.0 },
	{ 1.0, 1.0, 0.0 },
	{ 1.0, 0.0, 1.0 },
	{ 0.0, 1.0, 1.0 }
};

int face[][3] = {
	{ 3, 1, 0 },
	{ 3, 2, 1 },
	{ 3, 2, 0 },
	{ 4, 0, 1 },
	{ 4, 1, 2 },
	{ 4, 0, 2 },
};

int mode = 0;

void idle(void) {
	glutPostRedisplay();
}

void display(void) {
	int i;
	int j;

	static double r = 0;
	static double xz = 0;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(5.0 * COS(xz), 2.0, 
		5.0 * SIN(xz), 0.0 ,0.0, 0.0, 0.0, 1.0, 0.0);

	glRotated(r, 0.0, 0.0, 1.0);

	glBegin(GL_TRIANGLES);

	for (j = 0; j < 6; j++) {
		glColor3dv(color[j]);
		for(i = 0; i < 3; i++) {
			glVertex3dv(vertex[face[j][i]]);
		}
	}
	glEnd();
	
	glutSwapBuffers();

	if(mode == 1) {
		if((r += 0.1) >= 360) r = 0;
		if((xz += 0.01) >= 360) xz = 0;
	}
	if(mode == 2) {
		if((r -= 0.1) <= 0) r = 360;
		if((xz -= 0.01) <= 0) xz = 360;
	}
}

void resize(int w, int h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, ((double)w / (double)h), 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y) {
	switch (button) {
		case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			mode = 1;
			glutIdleFunc(idle);
		}    
		else {
			mode = 0;
			glutIdleFunc(0);
		}
		break;

		case GLUT_MIDDLE_BUTTON:
		break;

		case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			mode = 2;
			glutIdleFunc(idle);
		}    
		else {
			mode = 0;
			glutIdleFunc(0);
		}
		break;

		default:
		break;
	}
}

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char *argv[]) {
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 240);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);
	init();
	glutMainLoop();
	return 0;
}