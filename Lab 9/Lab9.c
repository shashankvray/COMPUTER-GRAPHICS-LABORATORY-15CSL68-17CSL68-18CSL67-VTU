//9. Develop a menu driven program to fill the polygon using scan line algorithm 

#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
float x1=200,x2=100,x3=200,x4=300,y1=200,y2=300,y3=400,y4=300;
int le[500],re[500],flag=0;
void edgedetect(float x1,float y1,float x2,float y2,int *le,int *re)
{
	float mx,x,temp;
	int i;
	if((y2-y1)<0)
	{
		temp=y1;y1=y2;y2=temp;
		temp=x1;x1=x2;x2=temp;
	}
	if((y2-y1)!=0)
		mx=(x2-x1)/(y2-y1);
	else
		mx=x2-x1;
	x=x1;
	for(i=y1;i<=y2;i++)
	{
		if(x<(float)le[i])
			le[i]=(int)x;
		if(x>(float)re[i])
			re[i]=(int)x;
		x+=mx;
	}
}
void scanfill()
{
	int i,y;
	for(i=0;i<500;i++)
	{
		le[i]=500;
		re[i]=0;
	}
	edgedetect(x1,y1,x2,y2,le,re);
	edgedetect(x2,y2,x3,y3,le,re);
	edgedetect(x3,y3,x4,y4,le,re);
	edgedetect(x4,y4,x1,y1,le,re);
	for(y=0;y<500;y++)
	{
		if(le[y]<=re[y])
			for(i=(int)le[y];i<(int)re[y];i++)
            {
                glColor3f(0.0,0.0,1.0);
                glBegin(GL_POINTS);
                glVertex2i(i,y);
                glEnd();
            }
	}
}
void display()
{
  glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glVertex2f(x4,y4);
	glEnd();
	if(flag)
        scanfill();
	glFlush();
}
void menu(int id)
{
 switch(id)
 {
   case 1: flag=1;
           break;
   case 2: flag=0;
           break;
   case 3: exit(0);
 }
 glutPostRedisplay();
}
int main(int argc,char**argv)
{
	int sub;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Menu Driven Scan-line Algorithm");
	glutDisplayFunc(display);
	gluOrtho2D(0.0,499.0,0.0,499.0);
	sub=glutCreateMenu(menu);
	glutAddMenuEntry("Yes",1);
	glutAddMenuEntry("No",2);
	glutCreateMenu(menu);
	glutAddSubMenu("Polygon Fill",sub);
	glutAddMenuEntry("Exit",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}
