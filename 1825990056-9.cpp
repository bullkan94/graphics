#include <stdio.h>
#include <GL/glut.h>

#define MAXPOINTS 100      
GLint point[MAXPOINTS][2]; 
int pointnum = 0;          
int rubberband = 0;

void drawRec(GLint x0, GLint y0,
	GLint x1, GLint y1) {
	glBegin(GL_LINE_LOOP);
	glVertex2i(x0, y0);
	glVertex2i(x1, y0);
	glVertex2i(x1, y1);
	glVertex2i(x0, y1);
	glEnd();
}

void display(void)
{
	int i;

	glClear(GL_COLOR_BUFFER_BIT);

	if (pointnum > 1) {
		glColor3d(0.0, 0.0, 0.0);
		for (i = 0; i < pointnum; i += 2) {
			drawRec(point[i][0], point[i][1],
				point[i + 1][0], point[i + 1][1]);
		}
	}

	glFlush();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glLoadIdentity();
	glOrtho(-0.5, (GLdouble)w - 0.5,
		(GLdouble)h - 0.5, -0.5, -1.0, 1.0);
}

void mouse(int button, int state, int x, int y)
{

	switch (button) {
		case GLUT_LEFT_BUTTON:

		point[pointnum][0] = x;
		point[pointnum][1] = y;
		if (state == GLUT_UP) {

			glColor3d(0.0, 0.0, 0.0);
			drawRec(point[pointnum - 1][0], point[pointnum - 1][1], 
				point[pointnum][0], point[pointnum][1]);
			glFlush();


			rubberband = 0;
		}    
		else {

		}
		if (pointnum < MAXPOINTS - 1) ++pointnum;
		break;
		case GLUT_MIDDLE_BUTTON:
		break;
		case GLUT_RIGHT_BUTTON:
		break;
		default:
		break;
	}
}

void motion(int x, int y)
{
	static GLint savepoint[2]; 

	glEnable(GL_COLOR_LOGIC_OP);
	glLogicOp(GL_INVERT);  

	if (rubberband)
		drawRec(point[pointnum - 1][0], point[pointnum - 1][1],
			savepoint[0], savepoint[1]);	
	drawRec(point[pointnum - 1][0], point[pointnum - 1][1],
		x, y);

	glFlush();

	glLogicOp(GL_COPY);
	glDisable(GL_COLOR_LOGIC_OP);

	savepoint[0] = x;
	savepoint[1] = y;

	rubberband = 1;
}

void init(void)
{

	glClearColor(1.0, 1.0, 1.0, 1.0);
}


int main(int argc, char *argv[])
{
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 240);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	init();
	glutMainLoop();
	return 0;
}