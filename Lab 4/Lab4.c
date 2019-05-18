//4. Draw a color cube and allow the user to move the camera suitably to experiment with perspective viewing. 

#include <windows.h>
#include <GL/glut.h>
GLfloat v[8][3]={{0,0,0},{0,0.5,0},{0.5,0.5,0},{0.5,0,0},{0,0,0.5},{0,0.5,0.5},{0.5,0.5,0.5},{0.5,0,0.5}};
GLfloat camx=0,camy=0,camz=4;
void drawface(int a,int b,int c,int d)
{
    glBegin(GL_POLYGON);
       glVertex3fv(v[a]);
       glVertex3fv(v[b]);
       glVertex3fv(v[c]);
       glVertex3fv(v[d]);
    glEnd();
}
void draw()
{
    glColor3f(0,0,0);
    drawface(7,6,5,4);
    glColor3f(0,0,1);
    drawface(6,2,1,5);
    glColor3f(0,1,0);
    drawface(0,3,2,1);
    glColor3f(0,1,1);
    drawface(4,7,3,0);
    glColor3f(1,0,0);
    drawface(7,3,2,6);
    glColor3f(1,0,1);
    drawface(4,0,1,5);
}
void display()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camx,camy,camz,.5,.5,.5,0,1,0);
    draw();
    glutSwapBuffers();
}
void key(unsigned char ch,int x,int y)
{
    switch(ch)
    {
        case 'x': camx-=0.5;
                  break;
        case 'X': camx+=0.5;
                  break;
        case 'y': camy-=0.5;
                  break;
        case 'Y': camy+=0.5;
                  break;
        case 'z': camz-=0.5;
                  break;
        case 'Z': camz+=0.5;
                  break;
    }
    glutPostRedisplay();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Cube");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,2,20);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
