#include <GL/glut.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(0.0, 0.6);
	glVertex2d(-0.3, -0.6);
	glVertex2d(0.5, 0.1);
	glVertex2d(-0.5, 0.1);
	glVertex2d(0.3, -0.6);
	glEnd();
	glFlush();
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}