//5. Clip a lines using Cohen-Sutherland algorithm 

#include <windows.h>
#include <GL/glut.h>

GLfloat xmin=10,ymin=10,xmax=50,ymax=50;
GLfloat x1=5,y1=2,x2=70,y2=80,m;

int left=1,right=2,bottom=4,top=8,flag=0,ac=1,c1,c2;

int getcode(GLfloat x, GLfloat y)
{
    int code=0;
    if(x<xmin)
        code=code|left;
    if(x>xmax)
        code=code|right;
    if(y<ymin)
        code=code|bottom;
    if(y>ymax)
        code=code|top;
    return code;
}
void clip()
{
    GLfloat x,y;
    int c;
    if(c1)
        c=c1;
    else
        c=c2;
    m=(y2-y1)/(x2-x1);
    if(c&left)
    {
        x=xmin;
        y=y1+m*(xmin-x1);
    }
    if(c&right)
    {
        x=xmax;
        y=y1+m*(xmax-x1);
    }
    if(c&bottom)
    {
        y=ymin;
        x=x1+(ymin-y1)/m;
    }
    if(c&top)
    {
        y=ymax;
        x=x1+(ymax-y1)/m;
    }
    if(c==c1)
    {
        x1=x;y1=y;
    }
    else
    {
        x2=x;y2=y;
    }
}
void cohensutherland()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin,ymin);
    glVertex2f(xmax,ymin);
    glVertex2f(xmax,ymax);
    glVertex2f(xmin,ymax);
    glEnd();
    if(ac)
    {
    glColor3f(0,0,1);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
    }
    while(1&flag)
    {
        c1=getcode(x1,y1);
        c2=getcode(x2,y2);
        if((c1|c2)==0)
        {
            ac=1;
            break;
        }
        if((c1&c2)!=0)
        {
            ac=0;
            break;
        }
        if((c1&c2)==0)
            clip();
    }
    glFlush();
}
void Key(unsigned char ch, int x, int y)
{
    if(ch=='c')
        flag=1;
    glutPostRedisplay();
}
void init()
{
    gluOrtho2D(0,100,0,100);
   // glClearColor(1,1,1,1);
}
int main(int C,char *V[])
{
    glutInit(&C,V);
    glutInitWindowSize(480,480);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutCreateWindow("Cohen Sutherland");
    init();
    glutDisplayFunc(cohensutherland);
    glutKeyboardFunc(Key);
    glutMainLoop();
    return 0;
}
