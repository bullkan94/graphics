#include <stdlib.h>
#include <GL/glut.h>

GLdouble vertex[][3] = {
	{ 0.0, 0.0, 0.0 },
	{ 1.0, 0.0, 0.0 },
	{ 0.0, 1.0, 0.0 },
	{ 0.0, 0.0, 1.0 }
};

int face[][3] = {
	{ 0, 1, 2 },
	{ 3, 0, 2 },
	{ 0, 3, 1 },
	{ 1, 3, 2 }
};

GLdouble normal[][3] = {
	{ 0.0, 0.0, -1.0 },
	{ -1.0, 0.0, 0.0 },
	{ 0.0, -1.0, 0.0 },
	{ 1.0, 1.0, 1.0 }
};

GLfloat light0pos[] = { 0.0, 3.0, 5.0, 1.0 };
GLfloat light1pos[] = { 5.0, 3.0, 0.0, 1.0 };
GLfloat green[] = { 0.0, 0.8, 0.0, 1.0 };
GLfloat red[] = { 0.8, 0.0, 0.0, 1.0 };
GLfloat white[] = { 0.7, 0.7, 0.7, 1.0 };

inline void tetra(void) {
	int i, j;
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);

	glBegin(GL_TRIANGLES);
	for(j = 0; j < 4; ++j) {
		glNormal3dv(normal[j]);
		for(i = 0; i < 3; ++i) {
			glVertex3dv(vertex[face[j][i]]);
		}
	}
	glEnd();
	glutSwapBuffers();
}

int mode = 0;

void idle(void) {
	glutPostRedisplay();
}

void display(void) {
	static double r = 0;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt( 3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
	glLightfv(GL_LIGHT1, GL_POSITION, light1pos);

	glRotated(r, 0.0, 1.0, 0);
	
	tetra();
	

	if(mode == 1) {
		if((r += 0.1) >= 360) r = 0;
	}
	if(mode == 2) {
		if((r -= 0.1) <= 0) r = 360;
	}
}

void resize(int w, int h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, ((double)w / (double)h), 1.0, 100.0);
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

	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, red);
	glLightfv(GL_LIGHT0, GL_SPECULAR, red);

	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, green);
	glLightfv(GL_LIGHT1, GL_SPECULAR, green);
}

int main(int argc, char *argv[]) {
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 300);
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