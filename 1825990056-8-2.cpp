#include <GL/glut.h>
#include <math.h>

void draw(int n)
{
	int i;
	glBegin(GL_LINE_LOOP);

	for(i = 0; i < n; i++)
	{
		glVertex2d(sin((i / n) * (2 * M_PI)), 
			cos((i / n) * (2 * M_PI)));
	}

	glEnd();
	glFlush();
}

void display(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);

	for(i = 3; i <= 9; i++)
	{
		int j;
		glBegin(GL_LINE_LOOP);

		for(j = 0; j < i; j++)
		{
			glVertex2d(sin((2 * j * M_PI) / i), 
				cos((2 * j * M_PI) / i));
		}

		glEnd();
		glFlush();
	}

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