#include <GL/glut.h>

void resize1(int, int);
void resize2(int, int);
void draw(int);

GLdouble vertex[][3] = {
	{ -0.3, 0.8, 0.1 },
	{ 0.4, 0.7, -0.3 },
	{ -0.2, -0.8, 0.3 },
	{ 0.1, 0.2, 0.8 }
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

double r = 0;
double mul = 1;
double l_x = 0.0;
int count = 0;

void idle(void) {
	glutPostRedisplay();
}

inline void draw() {
	int i;

	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(l_x, 0.0, 8.0, l_x, 0.0, 0.0, 0.0, 1.0, 0.0);

	glRotated((double)r, 0.0, 1.0, 0.0);

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

	glutSwapBuffers();
}

void display1(void) {
	draw();

	if((r += 0.5) >= 360) r = 0;
	for(int i = 0; i < 4; i ++)
		vertex[i][0] += 0.001;
	count++;
	
}

void display2(void) {
	draw();

	if((r -= 0.5) >= 360) r = 0;
	if(count-- > 0) {
		for(int i = 0; i < 4; i ++)
			vertex[i][0] -= 0.001;
	} else {
		count = 0;
	}
}

void resize(int w, int h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, ((double)w / (double)h), 3.0, 300.0);
	glMatrixMode(GL_MODELVIEW);

}

void mouse(int button, int state, int x, int y) {

	switch (button) {
		case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			glutDisplayFunc(display1);
			glutIdleFunc(idle);
		}    
		else {
			glutDisplayFunc(display2);
			glutIdleFunc(0);
		}
		break;

		case GLUT_MIDDLE_BUTTON:
		break;

		case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			glutIdleFunc(idle);
		}    
		else {
			glutIdleFunc(0);
		}
		break;

		default:
		break;
	}
}

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char *argv[]) {
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display1);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);;
	init();
	glutMainLoop();
	return 0;
}