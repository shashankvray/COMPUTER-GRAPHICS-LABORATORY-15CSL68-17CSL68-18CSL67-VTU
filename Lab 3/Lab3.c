//3. Draw a colour cube and spin it using OpenGL transformation matrices

#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
GLfloat v[8][3]={{0,0,0},{0,0.5,0},{0.5,0.5,0},{0.5,0,0},{0,0,0.5},{0,0.5,0.5},{0.5,0.5,0.5},{0.5,0,0.5}},nv[8][3];
GLfloat d=0,r;
char a;
void spin()
{
    d=d+1;
    if(d>360)
        d=0;
    glutPostRedisplay();
}
void drawface(int a,int b,int c,int d)
{
    glBegin(GL_POLYGON);
       glVertex3fv(nv[a]);
       glVertex3fv(nv[b]);
       glVertex3fv(nv[c]);
       glVertex3fv(nv[d]);
    glEnd();
    glFlush();
}
void draw()
{
    int i;
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    r= d*3.14/180;
    if(a=='x')
    {

        for(i=0;i<8;i++)
         {
             nv[i][0]=v[i][0];
             nv[i][1]=v[i][1]*cos(r)-v[i][2]*sin(r);
             nv[i][2]=v[i][1]*sin(r)+v[i][2]*cos(r);
         }
    }
    if(a=='y')
    {

        for(i=0;i<8;i++)
         {
             nv[i][0]=v[i][0]*cos(r)-v[i][2]*sin(r);
             nv[i][1]=v[i][1];
             nv[i][2]=v[i][0]*sin(r)+v[i][2]*cos(r);
         }
    }
    if(a=='z')
    {

        for(i=0;i<8;i++)
         {
             nv[i][0]=v[i][0]*cos(r)-v[i][1]*sin(r);
             nv[i][1]=v[i][0]*sin(r)+v[i][1]*cos(r);
             nv[i][2]=v[i][2];
         }
    }

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
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    printf("Enter the axis\n");
    scanf("%c",&a);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Cube");
    glutDisplayFunc(draw);
    glutIdleFunc(spin);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
