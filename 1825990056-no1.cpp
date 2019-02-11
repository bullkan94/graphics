/*
名前：PARK JUNHYEON
学籍番号；18-2599-005-6
使い方；マウス左ボタンを押すと左の、右ボタンを押すと右の文字が回転を始める
説明；名前を英語で書いた時、子音PRを作りました。一番苦労した点は
	PとRの丸いところでした。円の半分だけが必要だったため自分で
	簡単ですが半分だけを描くTorusの関数を作りました。
	Sphereを細かく繋いで一つの図形に見えるようにしたため
	光を照らした時、問題なく色が見えます。
	（韓国語バージョンOSでコードを作成したため文字コードの問題があるかもしれません。）
*/
#ifndef NDEBUG
#define NDEBUG
#endif

#include <gl/glut.h>

int left = 0;
int right = 0;

GLfloat light0pos[] = { 20.0, 10.0, 0.0, 1.0 };
GLfloat light1pos[] = { -20.0, 10.0, 0.0, 1.0 };
GLfloat red[] = { 1.0, 0.2, 0.2, 1.0 };
GLfloat blue[] = { 0.2, 0.2, 0.8, 1.0 };
GLfloat white[] = { 0.8, 0.8, 0.8, 1.0 };

inline void halfTorus(int radius) {
	glTranslated(0.0, 11.0, 0.0);
	for (int r = 0; r <= 180; r++) {
		glPushMatrix();
		glRotated(r, 0.0, 0.0, 1.0);
		glTranslated(0.0, (double)radius, 0.0);
		glutSolidSphere(1.0, 10, 10);
		glPopMatrix();
	}
}

void idle(void) {
	glutPostRedisplay();
}

void display(void) {
	static double r1;
	static double r2;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 10.0, -25.0, 0.0, 10.0, 0.0, 0.0, 1.0, 0.0);

	glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
	glLightfv(GL_LIGHT1, GL_POSITION, light1pos);
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);

	glPushMatrix(); 
	 glTranslated(7.0, 0.0, 0.0);
	 glRotated(r1, 0.0, 1.0, 0.0);
	 glPushMatrix();
	  glPushMatrix();
	   for (int i = 0; i < 15; i++) {
		   glTranslated(0.0, 1.0, 0.0);		   
		   glutSolidCube(2.0);
	   }
	  glPopMatrix();
	  halfTorus(4);
	 glPopMatrix();
	glPopMatrix();

	/////////////////

	glPushMatrix();
	 glTranslated(-7.0, 0.0, 0.0);
	 glRotated(r2, 0.0, 1.0, 0.0);
	 glPushMatrix();
	 glPushMatrix();
	 for (int i = 0; i < 15; i++) {
		 glTranslated(0.0, 1.0, 0.0);
		 glutSolidCube(2.0);
	 }
	 glPopMatrix();
	 halfTorus(4);
	 glRotated(135.0, 0.0, 0.0, 1.0);
	 glTranslated(0.0, 4.0, 0.0);
	 for (int i = 0; i < 6; i++) {
		 glTranslated(0.0, 1.0, 0.0);
		 glutSolidCube(2.0);
	 }	 
	 glPopMatrix();	
	glPopMatrix();

	glutSwapBuffers();

	if(left)
		if (r1++ >= 360) r1 = 0;
	if(right)
		if (r2++ >= 360) r2 = 0;
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, ((double)w / (double)h), 1.0, 100.0);


	glMatrixMode(GL_MODELVIEW);
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, red);
	glLightfv(GL_LIGHT0, GL_SPECULAR, red);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, blue);
	glLightfv(GL_LIGHT1, GL_SPECULAR, blue);
}

void mouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			left = 1;
			glutIdleFunc(idle);
		}
		else {
			left = 0;
			glutIdleFunc(0);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			right = 1;
			glutIdleFunc(idle);
		}
		else {
			right = 0;
			glutIdleFunc(0);
		}
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