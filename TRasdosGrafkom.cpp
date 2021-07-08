#include<windows.h>
#include<gl/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void mouseMotion(int, int);
void ukuran(int, int);

int is_depth;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void tampil(void)
{
    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glTranslatef(xmov, ymov, zmov);
    glPushMatrix();

    //DEPAN
    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-50, -20, 20); //A
    glVertex3f(-30, -20, 20); //B
    glVertex3f(-30, 20, 20); //C
    glVertex3f(-50, 20, 20); //D
    glEnd();

    // DEPAN
    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-30, -20, 20); //B
    glVertex3f(-30, -20, -100); //E
    glVertex3f(-30, 20, -100); //F
    glVertex3f(-30, 20, 20); //C
    glEnd();

    // DEPAN
    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-50, -20, 20); //B
    glVertex3f(-50, -20, -100); //E
    glVertex3f(-50, 20, -100); //F
    glVertex3f(-50, 20, 20); //C
    glEnd();

    // DEPAN
    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-50, -20, -100); //B
    glVertex3f(-30, -20, -100); //E
    glVertex3f(-30, 20, -100); //F
    glVertex3f(-50, 20, -100); //C
    glEnd();

    // DEPAN
    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-50, -20, 20); //B
    glVertex3f(-30, -20, 20); //E
    glVertex3f(-30, -20, -100); //F
    glVertex3f(-50, -20, -100); //C
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-55, 20, 20); //B
    glVertex3f(-25, 20, 20); //E
    glVertex3f(-25, 20, -100); //F
    glVertex3f(-55, 20, -100); //C
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-60, -20, 20); //A
    glVertex3f(60, -20, 20); //B
    glVertex3f(60, 20, 20); //C
    glVertex3f(-60, 20, 20); //D
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-60, -20, 50); //A
    glVertex3f(60, -20, 50); //B
    glVertex3f(60, 20, 50); //C
    glVertex3f(-60, 20, 50); //D
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-60, -20, 20); //A
    glVertex3f(-60, 20, 20); //B
    glVertex3f(-60, 20, 50); //D
    glVertex3f(-60, -20, 50); //C
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(60, -20, 20); //A
    glVertex3f(60, 20, 20); //B
    glVertex3f(60, 20, 50); //D
    glVertex3f(60, -20, 50); //C
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-60, -20, 20); //A
    glVertex3f(-60, -20, 50); //B
    glVertex3f(60, -20, 50); //C
    glVertex3f(60, -20, 20); //D
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-60, 20, 10); //A
    glVertex3f(-60, 20, 60); //B
    glVertex3f(60, 20, 60); //C
    glVertex3f(60, 20, 10); //D
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(50, 20, 20); //A
    glVertex3f(50, 20, -100); //B
    glVertex3f(50, -20, -100); //C
    glVertex3f(50, -20, 20); //D
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(55, 20, 20); //A
    glVertex3f(55, 20, -100); //B
    glVertex3f(20, 20, -100); //C
    glVertex3f(20, 20, 20); //D
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(25, 20, 20); //A
    glVertex3f(25, 20, -100); //B
    glVertex3f(25, -20, -100); //C
    glVertex3f(25, -20, 20); //D
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(50, -20, -100); //A
    glVertex3f(50, 20, -100); //B
    glVertex3f(25, 20, -100); //C
    glVertex3f(25, -20, -100); //D
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(50, -20, 20); //A
    glVertex3f(25, -20, 20); //B
    glVertex3f(25, -20, -100); //C
    glVertex3f(50, -20, -100); //D
    glEnd();

    //TENGAH
    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-30, -20, -10); //A
    glVertex3f(25, -20, -10); //B
    glVertex3f(25, 20, -10); //C
    glVertex3f(-30, 20, -10); //D
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-30, -20, -30); //A
    glVertex3f(25, -20, -30); //B
    glVertex3f(25, 20, -30); //C
    glVertex3f(-30, 20, -30); //D
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-30, -20, -10); //A
    glVertex3f(-30, -20, -30); //B
    glVertex3f(25, -20, -30); //D
    glVertex3f(25, -20, -10); //C
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-30, 20, -10); //A
    glVertex3f(25, 20, -10); //D
    glVertex3f(25, 20, -30); //B
    glVertex3f(-30, 20, -30); //C
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-30, -20, -50); //A
    glVertex3f(25, -20, -50); //B
    glVertex3f(25, 20, -50); //C
    glVertex3f(-30, 20, -50); //D
    glEnd();
   
    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-30, -20, -70); //A
    glVertex3f(25, -20, -70); //B
    glVertex3f(25, 20, -70); //C
    glVertex3f(-30, 20, -70); //D
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-30, -20, -50); //A
    glVertex3f(-30, -20, -70); //B
    glVertex3f(25, -20, -70); //D
    glVertex3f(25, -20, -50); //C
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 191, 184);
    glVertex3f(-30, 20, -50); //A
    glVertex3f(-30, 20, -70); //B
    glVertex3f(25, 20, -70); //D
    glVertex3f(25, 20, -50); //C
    glEnd();


    //BAGIAN 2

    glPopMatrix();
    glutSwapBuffers();
}

void idle() {
    if (!mouseDown) {
        xrot += 0.3f;
        yrot += 0.4f;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        zmov += 3.0;
        break;
    case 'd':
    case 'D':
        xmov += 3.0;
        break;
    case 's':
    case 'S':
        zmov -= 3.0;
        break;
    case 'a':
    case 'A':
        xmov -= 3.0;
        break;
    case '7':
        ymov += 3.0;
        break;
    case '9':
        ymov -= 3.0;
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("The Avenues Mall");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}