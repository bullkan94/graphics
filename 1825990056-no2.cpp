/*
名前：PARK JUNHYEON
学籍番号；18-2599-005-6
使い方；マウス左ボタンを押すと電子が回転する。
		右ボタンを押すと原子模型全体が回転する。
説明；原子模型を作りました。マウスを押すと周りの電子もしくは原子模型が動きます。
	一番よく全体の動きが見える位置と大きさを決定するのが難しかったんですが、
	値を色々変えながら確認しました。
	（韓国語バージョンOSでコードを作成したため文字コードの問題があるかもしれません。）
*/
#ifndef NDEBUG
#define NDEBUG
#endif

#include <gl/glut.h>
#include <math.h>

int elec = 0;
int atom = 0;

void idle(void) {
	glutPostRedisplay();
}

GLfloat light0pos[] = { 0.0, 10.0, 10.0, 1.0 };

GLfloat red[] = { 0.8, 0.1, 0.1, 1.0 };
GLfloat blue[] = { 0.1, 0.1, 0.8, 1.0 };
GLfloat green[] = { 0.1, 0.8, 0.1, 1.0 };
GLfloat yellow[] = { 0.8, 0.8, 0.1, 1.0 };
GLfloat purple[] = { 0.8, 0.1, 0.8, 1.0 };
GLfloat color[] = { 0.1, 0.8, 0.8, 1.0 };
GLfloat white[] = { 0.8, 0.8, 0.8, 1.0 };

GLfloat specular[] = { 0.5, 0.5 ,0.5, 1.0 };
GLfloat def[] = { 0.0, 0.0, 0.0, 1.0 };

void display(void) {
	static double r1;
	static double r2;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(15.0, 15.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, def);

	glRotated(r2, 0.0, 1.0, 0.0);

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);
	glutSolidSphere(4.0, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glRotated(10.0, 0.0, 1.0, 0.0);
	glRotated(45.0, 1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glutSolidTorus(0.1, 10.0, 30, 30);
	glPushMatrix();
	glRotated(r1, 0.0, 0.0, 1.0);
	glTranslated(0.0, 10.0, 0.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, green);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, def);
	glutSolidSphere(0.7, 30, 30);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotated(-10.0, 0.0, 1.0, 0.0);
	glRotated(-45.0, 1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
	glutSolidTorus(0.1, 10.0, 30, 30);
	glPushMatrix();
	glRotated(r1, 0.0, 0.0, 1.0);
	glTranslated(10.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, def);
	glutSolidSphere(0.7, 30, 30);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotated(90.0, 1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
	glutSolidTorus(0.1, 10.0, 30, 30);
	glPushMatrix();
	glRotated(-r1, 0.0, 0.0, 1.0);
	glTranslated(-sqrt(50.0), sqrt(50.0), 0.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, yellow);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, def);
	glutSolidSphere(0.7, 30, 30);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotated(-10.0, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
	glutSolidTorus(0.1, 10.0, 30, 30);
	glPushMatrix();
	glRotated(-r1, 0.0, 0.0, 1.0);
	glTranslated(sqrt(50.0), -sqrt(50.0), 0.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, purple);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, def);
	glutSolidSphere(0.7, 30, 30);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotated(-40.0, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
	glutSolidTorus(0.1, 10.0, 30, 30);
	glPushMatrix();
	glRotated(-r1, 0.0, 0.0, 1.0);
	glTranslated(-sqrt(50.0), -sqrt(50.0), 0.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, def);
	glutSolidSphere(0.7, 30, 30);
	glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();

	if (elec)
		if ((r1 += 0.6) >= 360) r1 = 0;
	if(atom)
		if ((r2 += 0.4) >= 360) r2 = 0;
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
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
}

void mouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			elec = 1;
			glutIdleFunc(idle);
		}
		else {
			elec = 0;
			glutIdleFunc(0);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			atom = 1;
			glutIdleFunc(idle);
		}
		else {
			atom = 0;
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