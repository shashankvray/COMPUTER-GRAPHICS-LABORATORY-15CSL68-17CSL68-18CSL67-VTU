//1. Implement Bresenham’s line drawing algorithm for all types of slope. 

#include <windows.h>
#include <GL/glut.h>
#include <math.h>
void draw()
{
    glClearColor(1,1,1,1); //Background Color(#,#,#) and Transparency (#)
    glPointSize(4); //Point Size
    gluOrtho2D(0,50,0,50); //Specifying the 2D Space with Start and End Cordinates
    int x1=10,y1=40,x2=10,y2=30; //Coordinates
    float x,y,dx,dy,m,p,temp;
    glClear(GL_COLOR_BUFFER_BIT); //Clearing the previous BG
    if(x1!=x2)
       m=(y2-y1)/(x2-x1); //Finding Slope. If x1==x2, then slope is zero
    else
       m=999;
    x=x1; //Updating Variable
    y=y1; //Updating Variable
    if(fabs(m)<1) //Positive Slope and zero slope
    {
        if(x1>x2)
        {
            temp=x1;x1=x2;x2=temp;
            temp=y1;y1=y2;y2=temp;
        }
        dx=fabs(x2-x1);
        dy=fabs(y2-y1);
        x=x1;
        y=y1;
        p=2*dy-dx;
        while(x<=x2)
        {
            glBegin(GL_POINTS);
            glColor3f(1,0,0);
            glVertex2f(x,y);
            glEnd();
            x=x+1;
            if(p>=0)
            {
                if(m>=0&&m<1)
                    y=y+1;
                else
                    y=y-1;
                p=p+2*dy-2*dx;
            }
            else
                p=p+2*dy;
        }
    }
    if(fabs(m)>=1)  //Negative and Infinite Slope
    {
        if(y1>y2)
        {
            temp=x1;x1=x2;x2=temp;
            temp=y1;y1=y2;y2=temp;
        }
        dx=fabs(x2-x1);
        dy=fabs(y2-y1);
        x=x1;
        y=y1;
        p=2*dy-dx;
        while(y<=y2)
        {
            glBegin(GL_POINTS);
            glColor3f(1,0,0);
            glVertex2f(x,y);
            glEnd();
            y=y+1;
            if(p>=0)
            {
                if(m>=1)
                    x=x+1;
                else
                    x=x-1;
                p=p+2*dx-2*dy;
            }
            else
                p=p+2*dx;
       }
    }
    glFlush(); //Refreshing the window
}
int main(int C,char *V[])
{
    glutInit(&C,V);
    glutInitWindowSize(480,480);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutCreateWindow("Bresenham's Algorithm");
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
