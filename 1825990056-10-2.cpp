#include <stdio.h>
#include <GL/glut.h>

GLdouble vertex[][3] = {
	{ 0.1, 0.8, 0.0 },
	{ 0.8, 0.1, 0.0 },
	{ 0.8, 0.8, 0.0 },
	{ 0.4, 0.4, 0.7 }
};

int edge[][2] = {
	{ 3, 2 },
	{ 2, 0 },
	{ 0, 3 },
	{ 3, 1 },
	{ 1, 2 },
	{ 2, 3 },
	{ 3, 0 },
	{ 0, 1 },
	{ 1, 3 },
	{ 1, 0 },
	{ 0, 2 },
	{ 2, 1 }
};

void display(void) {
	int i;

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for (i = 0; i < 3; i++) {
		glVertex3dv(vertex[edge[i][0]]);
		glVertex3dv(vertex[edge[i][1]]);
	}
	glEnd();

	glColor3d(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	for (i = 3; i < 6; i++) {
		glVertex3dv(vertex[edge[i][0]]);
		glVertex3dv(vertex[edge[i][1]]);
	}
	glEnd();

	glColor3d(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	for (i = 6; i < 9; i++) {
		glVertex3dv(vertex[edge[i][0]]);
		glVertex3dv(vertex[edge[i][1]]);
	}
	glEnd();

	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for (i = 9; i < 12; i++) {
		glVertex3dv(vertex[edge[i][0]]);
		glVertex3dv(vertex[edge[i][1]]);
	}
	glEnd();
	
	glFlush();
}

void resize(int w, int h) {
	glViewport(0, 0, w, h);

	glLoadIdentity();
	gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
	gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
}


int main(int argc, char *argv[]) {
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 240);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	init();
	glutMainLoop();
	return 0;
}