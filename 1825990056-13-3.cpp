#include <GL/glut.h>

int mode2 = 0;

void idle(void) {
	glutPostRedisplay();
}

void display(void)
{
	static double r2;
 
  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glColor3d(1.0, 0.0, 0.0);
  glutSolidSphere(2., 10, 10);  //S1
  glColor3d(1.0, 0.0, 1.0);	
  glPushMatrix();
    glRotated(-60., 0., 0., 1.);//R1
	glPushMatrix();
	  glTranslated(0., 5., 0.);
	  glScaled(1., 5., 1.);
	  glutSolidCube(2.0);  //P1
	glPopMatrix();
	glColor3d(0.0, 1.0, 0.0);
	glPushMatrix();
	  glTranslated(0., 10., 0.);
	  glutSolidSphere(2., 10, 10); //S2
      glColor3d(1.0, 0.0, 1.0);
      glRotated(r2, 0.0, 1.0, 0.0);
      glPushMatrix();
        glRotated(-40., 0., 0., 1.);//R1
	    glPushMatrix();
	      glTranslated(0., 5., 0.);
	      glScaled(1., 5., 1.);
	      glutSolidCube(2.0);  //P1
	    glPopMatrix();
	    glColor3d(0.0, 0.0, 1.0);
	    glPushMatrix();
	     glTranslated(0., 10., 0.);
	     glutSolidSphere(2., 10, 10);
	    glPopMatrix();
	  glPopMatrix();
	glPopMatrix();
  glPopMatrix();
  glutSwapBuffers();

  if(mode2 == 1) {
  	if((r2 += 0.5) >= 360) r2 = 0;
  }
}

void resize(int w, int h)
{
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-30, 30, -30, 30, -30.0, 30.0);

   glMatrixMode(GL_MODELVIEW);
}

void init(void)
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glEnable(GL_DEPTH_TEST);
}

void mouse(int button, int state, int x, int y) {
	switch (button) {
		case GLUT_LEFT_BUTTON:

		break;

		case GLUT_MIDDLE_BUTTON:
		break;

		case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			mode2 = 1;
			glutIdleFunc(idle);
		}    
		else {
			mode2 = 0;
			glutIdleFunc(0);
		}
		break;

		default:
		break;
	}
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