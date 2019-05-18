/*6. To draw a simple shaded scene consisting of a tea pot on a table. Define suitably the position and properties 
     of the light source along with the properties of the surfaces of the solid object used in the scene. */

#include <windows.h>
#include <GL/glut.h>
GLfloat d=0;
void spin()
{
    d=d+0.01;
    if(d>360)
        d=0;
    glutPostRedisplay();
}
void display()
{
    GLfloat L[]={1,1,1};
    GLfloat P[]={0,1,-1,0};
    GLfloat D1[]={1,0,0};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(0,1,3,0,0,0,0,1,0);
    glLightfv(GL_LIGHT0,GL_AMBIENT,L);
    glLightfv(GL_LIGHT0,GL_POSITION,P);

    glRotatef(d,0,1,0);

    glPushMatrix();
     glScalef(1,0.05,1);
     glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
     glTranslatef(-0.45,-0.5,-0.45);
     glScalef(0.05,1,0.05);
     glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
     glTranslatef(-0.45,-0.5,0.45);
     glScalef(0.05,1,0.05);
     glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
     glTranslatef(0.45,-0.5,-0.45);
     glScalef(0.05,1,0.05);
     glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
     glTranslatef(0.45,-0.5,0.45);
     glScalef(0.05,1,0.05);
     glutSolidCube(1);
    glPopMatrix();

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,D1);
    glPushMatrix();
     glTranslatef(0,0.2,0);
     glutSolidTeapot(0.22);
    glPopMatrix();
    glPopAttrib();

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Teapot");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,2,10);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);
    glutIdleFunc(spin);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);

    glutMainLoop();
    return 0;
}
