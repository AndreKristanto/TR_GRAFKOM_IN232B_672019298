#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <windows.h>
#include <glut.h>

#define pi (2*acos(0.0))

#define sqrt2 (sqrt(2))

typedef struct point
{
    double x,y,z;
} Point;

bool drawAxes = true;
float tyreAngle = 115;

float quadAngle = -90;
float boxAngle = 0;
float boxScaleFactor = 1;
float tyreScaleFactor = 1;
float tinyBoxAngle = 0;
float background = 0;
float slidingDoor = 0;
int fu = 0;

Point pos, u, r, l;

void displayAxes()
{
    if(drawAxes)
    {
        glBegin(GL_LINES);
        {
            glColor3f(1.0, 0, 0);

            glVertex3f( 500,0,0); // a point on pos x axis
            glVertex3f(-500,0,0); // a point on neg x axis

            glColor3f(0, 1.0, 0);

            glVertex3f(0,-500,0); // a point on pos y axis
            glVertex3f(0, 500,0); // a point on neg y axis

            glColor3f(0, 0, 1.0);

            glVertex3f(0,0, 500);  // a point on pos z axis
            glVertex3f(0,0,-500);   // a point on neg z axis
        }
        glEnd();
    }
}

Point func(Point vect, Point perp, int dir)
{
    double c = cos(pi/180);
    double s = dir * sin(pi/180);
    Point point;
    point.x = c * vect.x + s * perp.x;
    point.y = c * vect.y + s * perp.y;
    point.z = c * vect.z + s * perp.z;
    c = sqrt(point.x*point.x + point.y*point.y + point.z*point.z);
    point.x /= c;
    point.y /= c;
    point.z /= c;
    return point;
}

void keyboardListener(unsigned char key, int x,int y)
{
    switch(key)
    {
    case '1':
    {
        Point l1 = func(l, r, -1);
        r = func(r, l, 1);
        l = l1;
        break;
    }
    case '2':
    {
        Point l1 = func(l, r, 1);
        r = func(r, l, -1);
        l = l1;
        break;
    }

    case '3':
    {
        Point u1 = func(u, l, -1);
        l = func(l, u, 1);
        u = u1;
        break;
    }
    case '4':
    {
        Point u1 = func(u, l, 1);
        l = func(l, u, -1);
        u = u1;
        break;
    }
    case '5':
    {
        Point r1 = func(r, u, -1);
        u = func(u, r, 1);
        r = r1;
        break;
    }
    case '6':
    {
        Point r1 = func(r, u, 1);
        u = func(u, r, -1);
        r = r1;
        break;
    }
    case '7':
    {
        tyreScaleFactor += 0.2;
        break;
    }
    case '8':
    {
        tyreScaleFactor -= 0.2;
        break;
    }
    default:
        break;
    }
}

void specialKeyListener(int key, int x,int y)
{
    switch(key)
    {
    case GLUT_KEY_DOWN: // down arrow
    {
        quadAngle += 5;
        printf("Quad Angle %f\n", quadAngle);
        break;
    }

    case GLUT_KEY_UP:   // up arrow
    {
        quadAngle -= 5;
        printf("Quad Angle %f\n", quadAngle);
        break;
    }

    case GLUT_KEY_RIGHT:    // right arrow
    {
        boxAngle += 5;
        printf("Box Angle %f\n", boxAngle);
        break;
    }

    case GLUT_KEY_LEFT:     // left arrow
    {
        boxAngle -= 5;
        printf("Box Angle %f\n", boxAngle);
        break;
    }

    case GLUT_KEY_PAGE_UP:
    {
        boxScaleFactor += 0.2;
        break;
    }

    case GLUT_KEY_PAGE_DOWN:
    {
        boxScaleFactor -= 0.2;
        break;
    }

    case GLUT_KEY_HOME:
    {
        if(slidingDoor == 140)
            break;
        else
        {
            slidingDoor += 5;
            break;
        }
    }

    case GLUT_KEY_END:
    {
        if(slidingDoor == 0)
            break;
        else
        {
            slidingDoor -= 5;
            break;
        }
    }

    default:
        break;
    }
}


void mouseListener(int button, int state, int x, int y) 	//x, y is the x-y of the screen (2D)
{
    switch(button)
    {
    case GLUT_LEFT_BUTTON:
        if(state == GLUT_DOWN) // 2 times?? in ONE click? -- solution is checking DOWN or UP
        {
            printf("Mouse Left Button Clicked\n");
        }
        else if(state == GLUT_UP)
        {
            printf("Mouse Left Button Released\n");
        }
        break;
    default:
        break;
    }
}

void displayTyre(float tyreRadius, float tyreWidth)
{
    int tyreSlices = 10;
    float sliceWidth = (2 * M_PI * tyreRadius) / tyreSlices;
    float sliceAngle = 360 / tyreSlices;

    float halfTyreWidth = tyreWidth / 2, quartTyreWidth = halfTyreWidth / 2;
    float halfSliceWidth = sliceWidth / 2;

    if(fu == 0)
    {
        for(int i = 0; i< tyreSlices; i++)
        {
            if(i%2==0)
            {
                glColor3f(1, 0, 1);
            }
            else
            {
                glColor3f(1, 0, 0);
            }

            glPushMatrix();
            glRotatef(sliceAngle*i, 1, 0, 0);
            glBegin(GL_QUADS);
            {
                glVertex3f(halfTyreWidth,-tyreRadius/2, 0);
                glVertex3f(-halfTyreWidth, -tyreRadius/2, 0);
                glVertex3f(-halfTyreWidth, -tyreRadius, 0);
                glVertex3f(halfTyreWidth, -tyreRadius, 0);
            }
            glEnd();
            glPopMatrix(); //same again for another color

        }
    }



    /*glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    {
        glVertex3f(halfTyreWidth, 0, tyreRadius);
        glVertex3f(halfTyreWidth, 0, -tyreRadius);
        glVertex3f(-halfTyreWidth, 0, -tyreRadius);
        glVertex3f(-halfTyreWidth, 0, tyreRadius);
    }
    glEnd();*/


    glColor3f(0.25, 0.5, 1);
    for(int i=0; i<tyreSlices; i++)
    {
        glPushMatrix();
        glRotatef(sliceAngle*i, 1, 0, 0);
        glTranslatef(0, tyreRadius, 0);
        glBegin(GL_QUADS);
        {
            glVertex3f(halfTyreWidth, 0, halfSliceWidth);
            glVertex3f(halfTyreWidth, 0, -halfSliceWidth);
            glVertex3f(-halfTyreWidth, 0, -halfSliceWidth);
            glVertex3f(-halfTyreWidth, 0, halfSliceWidth);
        }
        glEnd();
        glPopMatrix();


    }
}

void displayQuad(float quadLength, float quadWidth, float xcolor, float ycolor, float zcolor) // width along x axis, length along z axis
{
    float halfQuadWidth = quadWidth / 2, halfQuadLength = quadLength / 2;

    glBegin(GL_QUADS);
    {
        /** Solid Fill Quad **/

        //glColor3f(1, 1, 0);

        //glVertex3f(halfQuadWidth, 0, halfQuadLength);
        //glVertex3f(halfQuadWidth, 0, -halfQuadLength);
        //glVertex3f(-halfQuadWidth, 0, -halfQuadLength);
        //glVertex3f(-halfQuadWidth, 0, halfQuadLength);

        /** Gradient Fill Quad **/


        glColor3f(xcolor, ycolor, zcolor);

        glVertex3f(halfQuadWidth, 0, halfQuadLength);
        glVertex3f(halfQuadWidth, 0, -halfQuadLength);

        glColor3f(xcolor, ycolor, zcolor);

        glVertex3f(-halfQuadWidth, 0, -halfQuadLength);
        glVertex3f(-halfQuadWidth, 0, halfQuadLength);

    }
    glEnd();
}

void displayBox(float boxLength, float boxWidth, float boxHeight, float xcolor, float ycolor, float zcolor) // length -> x axis, width -> yaxis, height -> z axis
{
    float halfBoxLength = boxLength / 2, halfBoxWidth = boxWidth / 2, halfBoxHeight = boxHeight / 2;
    glBegin(GL_QUADS);
    {
        glColor3f(xcolor, ycolor, zcolor);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);

        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);

        glColor3f(xcolor-0.35, ycolor-0.35, zcolor-0.35);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);

        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);

        glColor3f(xcolor-0.5, ycolor-0.5, zcolor-0.5);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);

        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);
    }
    glEnd();
}

void displayScene()
{
    //Primitive Object dimensions

    float quadLength = 100, quadWidth = 60;
    float largeBoxLength = 200, largeBoxWidth = 100, largeBoxHeight = 10;
    float smallBoxLength = 150, smallBoxWidth = 70, smallBoxHeight = 30;
    float tinyBoxLength = 10, tinyBoxWidth = 10, tinyBoxHeight = 10;
    float tyreRadius = 100, tyreWidth = 40;


    /** Principal Axes **/

    displayAxes();

    /**/

    /** Quad **/


    //glRotatef(quadAngle, 1, 0, 0); // rotates with respect to x axis
    //glRotatef(quadAngle, 0, 1, 0); // rotates with respect to y axis
    //glRotatef(quadAngle, 0, 0, 1); // rotates with respect to z axis
    //displayQuad(quadLength, quadWidth);


    /**/
    /*glTranslatef(150, 0, 0); // rotation applied first, translation applied second
    glRotatef(boxAngle, 1, 0, 0); // rotates with respect to x axis
    glRotatef(boxAngle, 0, 1, 0); // rotates with respect to y axis
    glRotatef(boxAngle, 0, 0, 1); // roytates with respect to z axis*/

    /** Single Box **/
    //base
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1); // rotation applied to both boxes
    glTranslatef(0, 0, 0);   // translation applied first, rotation applied second
    displayBox(300, 200, 30, 0, 0, 0.7);
    glPopMatrix();
    //house
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    glTranslatef(0, 0, 70);    // translation applied first, rotation applied second
    displayBox(280, 180, 180, 1.0, 0, 0);
    glPopMatrix();
    //roof
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    glTranslatef(0, 0, 160);    // translation applied first, rotation applied second
    displayBox(281, 200, 10, 0.0, 1.0, 0.0);
    glPopMatrix();
    //first stairs
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    glTranslatef(0, 25, 10);    // translation applied first, rotation applied second
    displayBox(81, 210, 10, 0.75, 0.75, 0);
    glPopMatrix();
    //2nd stairs
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    glTranslatef(0, 30, 0);    // translation applied first, rotation applied second
    displayBox(120, 240, 10, 0, 0.75, 0.8);
    glPopMatrix();
    //3rd stairs
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    glTranslatef(0, 37, -10);    // translation applied first, rotation applied second
    displayBox(160, 270, 10, 0.75, 0.75, 0.75);
    glPopMatrix();

    //door 1st part
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    glTranslatef(slidingDoor, 0, 0);
    glTranslatef(-15, 95, 50);    // translation applied first, rotation applied second
//    displayBox(80, 185, 150, 0.5, 0.58, 1.0);
    displayQuad(125, 40, 0.5, 0.58, 1.0);
    glPopMatrix();

    //door 2nd part
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    glTranslatef(-slidingDoor, 0, 0);
    glTranslatef(20, 95, 50);    // translation applied first, rotation applied second
//    displayBox(80, 185, 150, 0.5, 0.58, 1.0);
    displayQuad(125, 40, 0.5, 0.58, 1.0);
    glPopMatrix();
    //back first door
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    //glTranslatef(slidingDoor, 0, 0);
    glTranslatef(-15, -95, 50);    // translation applied first, rotation applied second
//    displayBox(80, 185, 150, 0.5, 0.58, 1.0);
    displayQuad(125, 40, 0.5, 0.58, 1.0);
    glPopMatrix();
    //back 2nd door
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    glTranslatef(-slidingDoor, 0, 0);
    glTranslatef(20, -95, 50);    // translation applied first, rotation applied second
//    displayBox(80, 185, 150, 0.5, 0.58, 1.0);
    displayQuad(125, 40, 0.5, 0.58, 1.0);
    glPopMatrix();

    //roof above the door
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    glTranslatef(2, 0, 110);    // translation applied first, rotation applied second
    displayBox(78, 195, 5, 0, 0, 0.7);
    glPopMatrix();
    //lampost
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    glTranslatef(0, 0, 160);    // translation applied first, rotation applied second
    displayBox(96, 40, 300, 0.7, 0.7, 0.0);
    glPopMatrix();
    //window
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    //displayBox(28, 60, 40, 1.0, 1.0, 0.8);
    //glRotatef(quadAngle, 1, 0, 0); // rotates with respect to x axis
    //glRotatef(quadAngle, 0, 1, 0); // rotates with respect to y axis

    glTranslatef(145, 0, 75);    // translation applied first, rotation applied second
    glRotatef(quadAngle, 0, 0, 1); // rotates with respect to z axis
    displayQuad(40, 60, 0.75, 0.75, 0);
    glPopMatrix();
    //window roof
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    glTranslatef(128, 0, 97);    // translation applied first, rotation applied second
    displayBox(28, 60, 5, 0, 0.75, 0.8);
    glPopMatrix();

    //sliding window roof
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    glTranslatef(-128, 0, 97);    // translation applied first, rotation applied second
    displayBox(28, 60, 5, 0, 0.75, 0.8);
    glPopMatrix();

    //sliding window
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    //displayBox(28, 60, 40, 1.0, 1.0, 0.8);
    //glRotatef(quadAngle, 1, 0, 0); // rotates with respect to x axis
    //glRotatef(quadAngle, 0, 1, 0); // rotates with respect to y axis

    glTranslatef(-145, 0, 75);    // translation applied first, rotation applied second
    glRotatef(quadAngle, 0, 0, 1); // rotates with respect to z axis
    displayQuad(40, 60, 0.75, 0.75, 0);
    glPopMatrix();



    /** Tyre **/
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    glTranslatef(0, 33, 250);
    //glRotatef(tyreAngle, 1, 0, 0); // roates the tyre w.r.t x axis
    glRotatef(tyreAngle, 0, 1, 0); // roates the tyre w.r.t y axis
    glRotatef(90, 0, 0, 1); // roates the tyre w.r.t z axis
    fu = 0;
    displayTyre(45, 20);
    glPopMatrix();

    //small tyre
    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1);
    glTranslatef(0, 33, 250);
    //glRotatef(tyreAngle, 1, 0, 0); // roates the tyre w.r.t x axis
    glRotatef(tyreAngle, 0, 1, 0); // roates the tyre w.r.t y axis
    glRotatef(90, 0, 0, 1); // roates the tyre w.r.t z axis
    fu = 1;
    displayTyre(22.5, 10);
    glPopMatrix();




    /**/


    /**/

    /** Double Box Stack **/

    //glRotatef(boxAngle, 0, 0, 1); // rotation applied to both boxes
    //glTranslatef(-300, 100, 100); // translation applied to both boxes
    //displayBox(largeBoxLength, largeBoxWidth, largeBoxHeight); // large box
    //glRotatef(boxAngle, 0, 0, 1);   // rotation applied only on the small box
    //glTranslatef(0, 0, (smallBoxHeight/2) + (largeBoxHeight/2)); // places the small box on top of the large box
    //displayBox(smallBoxLength, smallBoxWidth, smallBoxHeight); // small box

    /**/

    /** Double Box Stack - Push Pop Matrix **/


    /*glRotatef(boxAngle, 0, 0, 1); // rotation applied to both boxes

    //glPushMatrix(); // saves the matrix just before scaling, to prevent scale effect to anything other than the large box
    glScalef(boxScaleFactor, boxScaleFactor, boxScaleFactor); // without push-pop, scale will be applied to both boxes
    displayBox(largeBoxLength, largeBoxWidth, largeBoxHeight); // large box
    //glPopMatrix();

    glTranslatef(0, 0, (smallBoxHeight/2) + (largeBoxHeight/2)); // places the small box on top of the large box
    displayBox(smallBoxLength, smallBoxWidth, smallBoxHeight); // small box
    */


    /**/


    /** Tyre Double Box Stack **/

    /*glPushMatrix();
    glScalef(boxScaleFactor, boxScaleFactor, boxScaleFactor);
    displayBox(largeBoxLength, largeBoxWidth, largeBoxHeight); // large box
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, (smallBoxHeight/2) + (largeBoxHeight/2)); // places the small box on top of the large box
    displayBox(smallBoxLength, smallBoxWidth, smallBoxHeight); // small box
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, tyreRadius+smallBoxHeight+(largeBoxHeight/2)); // places the tyre on top of both boxes
    glRotatef(tyreAngle, 1, 0, 0); // check what happens to the tyre after exchanging the order of translation and roation
    glScalef(tyreScaleFactor, tyreScaleFactor, tyreScaleFactor);
    displayTyre(tyreRadius, tyreWidth);
    glPopMatrix();
    */

    /** Animate Function **/
    /*glPushMatrix();
    glScalef(boxScaleFactor, boxScaleFactor, boxScaleFactor);
    displayBox(300, 200, 10); // large box
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, (smallBoxHeight/2) + (largeBoxHeight/2)); // places the small box on top of the large box
    displayBox(280, 130, 100); // small box
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, tyreRadius+smallBoxHeight+(largeBoxHeight/2)); // places the tyre on top of both boxes
    glRotatef(tyreAngle, 1, 0, 0); // check what happens to the tyre after exchanging the order of translation and roation
    glScalef(tyreScaleFactor, tyreScaleFactor, tyreScaleFactor);
    displayTyre(tyreRadius, tyreWidth); // tyre
    glPopMatrix();

    glPushMatrix();
    glRotatef(tinyBoxAngle, 0, 0, 1); // angle is updated in animate function
    glTranslatef(250, 40, 50);
    displayBox(tinyBoxLength, tinyBoxWidth, tinyBoxHeight);
    glPopMatrix();*/
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(background, background, background,0);	//sets background color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // sets the current matrix to identity
    gluLookAt(pos.x, pos.y, pos.z, pos.x+l.x, pos.y+l.y, pos.z+l.z, u.x, u.y, u.z); // sets camera position and direction

    displayScene();

    glutSwapBuffers();
}



void animate()
{
    tinyBoxAngle += 0.05;
    glutPostRedisplay();


}
void tyre_moving_clockwise()
{
    tyreAngle +=0.15;
    glutPostRedisplay();

}
void tyre_moving_anticlockwise()
{
    tyreAngle -=0.15;
    glutPostRedisplay();

}

void init()
{
    glClearColor(background, background, background,0); 	//sets background color

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity(); // sets the current matrix to identity
    gluPerspective(80,	1,	1,	1000.0);

    // to understand the following values, read the specification pdf
    double d = 1 / sqrt2;
    pos = {300, 300, 150};
    u = {0, 0, 1};
    r = {-d, d, 0};
    l = {-d, -d, 0};
}

void subMenu(int id)
{
    if(id == 3)
    {
        background = 1;
    }
    else if(id == 4)
    {
        background = 0;
    }
}
void subMenu_fan(int id)
{
    if(id==5)
    {
        glutIdleFunc(tyre_moving_anticlockwise);		//what you want to do in the idle time (when no drawing is occuring)
    }
    else if(id==6)
    {
        glutIdleFunc(tyre_moving_clockwise);		//what you want to do in the idle time (when no drawing is occuring)
    }

}

void mainMenu(int id)
{
    if(id == 1)
    {
        drawAxes = true;
    }
    else if(id == 2)
    {
        drawAxes = false;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color
    glutCreateWindow("My OpenGL Program");

    init();

    glEnable(GL_DEPTH_TEST);	//enable Depth Testing

    glutDisplayFunc(display);	//display callback function
    glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

    glutKeyboardFunc(keyboardListener);
    glutSpecialFunc(specialKeyListener);
    glutMouseFunc(mouseListener);

    int subMenuNo = glutCreateMenu(subMenu);
    glutAddMenuEntry("White", 3);
    glutAddMenuEntry("Black", 4);
    int subMenuNo_fan = glutCreateMenu(subMenu_fan);
    glutAddMenuEntry("Clockwise", 5);
    glutAddMenuEntry("Anti Clockwise", 6);

    glutCreateMenu(mainMenu);
    glutAddMenuEntry("Axes On", 1);
    glutAddMenuEntry("Axes Off", 2);
    glutAddSubMenu("Background", subMenuNo);
    glutAddSubMenu("Fan circling", subMenuNo_fan);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();		//The main loop of OpenGL, this function never returns

    return 0;
}
