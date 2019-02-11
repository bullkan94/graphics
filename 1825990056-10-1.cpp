#include <stdio.h>
#include <GL/glut.h>

#define MAXPOINTS 100

void resize1(int, int);
void resize2(int, int);

GLdouble vertex[][3] = {
	{ 0.3, 0.3, 0.0 },
	{ 0.7, 0.3, 0.0 },
	{ 0.7, 0.7, 0.0 },
	{ 0.3, 0.7, 0.0 },
	{ 0.0, 0.0, 1.0 },
	{ 1.0, 0.0, 1.0 },
	{ 1.0, 1.0, 1.0 },
	{ 0.0, 1.0, 1.0 }
};

int edge[][2] = {
	{ 0, 1 },
	{ 1, 2 },
	{ 2, 3 },
	{ 3, 0 },
	{ 4, 5 },
	{ 5, 6 },
	{ 6, 7 },
	{ 7, 4 },
	{ 0, 4 },
	{ 1, 5 },
	{ 2, 6 },
	{ 3, 7 }
};

void display(void) {
	int i;

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for (i = 0; i < 12; i++) {
		glVertex3dv(vertex[edge[i][0]]);
		glVertex3dv(vertex[edge[i][1]]);
	}
	glEnd();

	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (i = 0; i < 4; i++) {
		glVertex3dv(vertex[edge[i][0]]);
		glVertex3dv(vertex[edge[i][1]]);
	}
	glEnd();

	glColor3d(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	for (i = 4; i < 8; i++) {
		glVertex3dv(vertex[edge[i][0]]);
		glVertex3dv(vertex[edge[i][1]]);
	}
	glEnd();

	glColor3d(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	for (i = 8; i < 12; i++) {
		glVertex3dv(vertex[edge[i][0]]);
		glVertex3dv(vertex[edge[i][1]]);
	}
	glEnd();
	
	glFlush();
}

//私のパソコンではコンソールが開かないので
//glutKeyboardFunc()を使いました
void keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case '1' :
		glutReshapeFunc(resize1);
		break;
		case '2' :
		glutReshapeFunc(resize2);
		break;
		default:
		break;
	}
}

void resize1(int w, int h) {
	glViewport(0, 0, w, h);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
}

void resize2(int w, int h) {
	glViewport(0, 0, w, h);

	glLoadIdentity();
	gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
	gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
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
	glutReshapeFunc(resize1);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}