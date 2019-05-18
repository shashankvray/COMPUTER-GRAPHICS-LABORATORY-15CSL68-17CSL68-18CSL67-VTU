/*7. Design, develop and implement recursively subdivide a tetrahedron to form 3D sierpinski gasket. 
     The number of recursive steps is to be specified by the user.*/ 

#include <windows.h>
#include <GL/glut.h>

GLfloat d=0;

void spin()
{
    d=d+0.005;
    if(d>360)
        d=0;
    glutPostRedisplay();
}
void tri(GLfloat a[3],GLfloat b[3],GLfloat c[3])
{
    glBegin(GL_TRIANGLES);
        glVertex3fv(a);
        glVertex3fv(b);
        glVertex3fv(c);
    glEnd();
}
void tetra(GLfloat a[3],GLfloat b[3],GLfloat c[3],GLfloat d[3])
{
    glColor3f(0,0,0);
    tri(a,b,c);
    glColor3f(1,0,0);
    tri(a,b,d);
    glColor3f(0,1,0);
    tri(b,c,d);
    glColor3f(0,0,1);
    tri(a,c,d);
}

void div(GLfloat p0[3],GLfloat p1[3],GLfloat p2[3],GLfloat p3[3],int n)
{
    GLfloat p01[3],p12[3],p20[3],p03[3],p13[3],p23[3];
    if(n==0)
        tetra(p0,p1,p2,p3);
    else
    {
        p01[0]=(p0[0]+p1[0])/2;
        p01[1]=(p0[1]+p1[1])/2;
        p01[2]=(p0[2]+p1[2])/2;

        p12[0]=(p1[0]+p2[0])/2;
        p12[1]=(p1[1]+p2[1])/2;
        p12[2]=(p1[2]+p2[2])/2;

        p20[0]=(p2[0]+p0[0])/2;
        p20[1]=(p2[1]+p0[1])/2;
        p20[2]=(p2[2]+p0[2])/2;

        p03[0]=(p0[0]+p3[0])/2;
        p03[1]=(p0[1]+p3[1])/2;
        p03[2]=(p0[2]+p3[2])/2;

        p13[0]=(p1[0]+p3[0])/2;
        p13[1]=(p1[1]+p3[1])/2;
        p13[2]=(p1[2]+p3[2])/2;

        p23[0]=(p2[0]+p3[0])/2;
        p23[1]=(p2[1]+p3[1])/2;
        p23[2]=(p2[2]+p3[2])/2;


        div(p0,p01,p20,p03,n-1);
        div(p01,p1,p12,p13,n-1);
        div(p12,p2,p20,p23,n-1);
        div(p03,p13,p23,p3,n-1);
    }
}

void draw()
{
    GLfloat p[4][3]={ {-0.5,-0.5,0.5},{0.5,-0.5,0.5},{0,0.5,0.5},{0,0,-0.5} };
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(d,0,1,0);
    div(p[0],p[1],p[2],p[3],3);

    glutSwapBuffers();

}
int main(int c,char *v[])
{
    glutInit(&c,v);
    glutInitWindowPosition(200,150);
    glutInitWindowSize(648,480);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Sierpinski Gasket");
    glutDisplayFunc(draw);
    glutIdleFunc(spin);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
