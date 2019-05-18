//2. Create and rotate a triangle about the origin and a fixed point. 

#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
GLfloat P[3][2]={{0,0.5},{-0.5,-0.5},{0.5,-0.5}}, NP[3][2];
GLfloat d,r,xr,yr;
int i;
void draw()
{
  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1,0,0);
  glBegin(GL_LINE_LOOP);
     glVertex2fv(P[0]);
     glVertex2fv(P[1]);
     glVertex2fv(P[2]);
  glEnd();
  r=d*(3.14)/180;

  for(i=0;i<3;i++)
  {
      NP[i][0]=xr+(P[i][0]-xr)*cos(r)-(P[i][1]-yr)*sin(r);
      NP[i][1]=yr+(P[i][0]-yr)*sin(r)+(P[i][1]-xr)*cos(r);
  }

 glColor3f(1,0,1);
  glBegin(GL_LINE_LOOP);
     glVertex2fv(NP[0]);
     glVertex2fv(NP[1]);
     glVertex2fv(NP[2]);
 glEnd();
 glFlush();
}

int main(int argc, char *argv[])
{
    printf("Enter the angle\n");
    scanf("%f",&d);
    printf("Enter the points for rotation\n");
    scanf("%f,%f",&xr,&yr);

    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE );
    glutCreateWindow("Triangle Rotation");
    glutDisplayFunc(draw);
    glutMainLoop();

    return 0;
}
