#include<stdio.h>
#include<GL/glut.h>
float xvmin=200,yvmin=200,xvmax=300,yvmax=300;
float xmin,ymin,xmax,ymax;
double x,y;
float x0,y0,x1,y1;
int RIGHT=2;
int LEFT=1;
int TOP=8;
int BOTTOM=4;
int computeoutcode(float x,float y);
void CSLCA(float x0,float y0,float x1,float y1)
{
int outcode0,outcode1,outcodeout;
int accept=0;
int done=0;
outcode0=computeoutcode(x0,y0);
outcode1=computeoutcode(x1,y1);
while(done==0)
{
if(!(outcode0|outcode1))
{
accept=1;
done=1;
}
else if(outcode0&outcode1)
{
done=1;
}
else
{
outcodeout=outcode0?outcode0:outcode1;
if(outcodeout& TOP)
{
x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
y=ymax;
}
else if(outcodeout& BOTTOM)
{
x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
y=ymin;
}
else if(outcodeout& RIGHT)
{
y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
x=xmax;
}
else
{
y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
x=xmin;
}
if(outcodeout==outcode0)
{
x0=x;
y0=y;
outcode0=computeoutcode(x0,y0);
}
else
{
x1=x;
y1=y;
outcode1=computeoutcode(x1,y1);
}
}
}
if(accept==1)
{
double sx=(xvmax-xvmin)/(xmax-xmin);
double sy=(yvmax-yvmin)/(ymax-ymin);
double vx0=xvmin+(x0-xmin)*sx;
double vy0=yvmin+(y0-ymin)*sy;
double vx1=xvmin+(x1-xmin)*sx;
double vy1=yvmin+(y1-ymin)*sy;
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(xvmin,yvmin);
glVertex2f(xvmax,yvmin);
glVertex2f(xvmax,yvmax);
glVertex2f(xvmin,yvmax);
glEnd();
glColor3f(0.0,0.0,1.0);
glBegin(GL_LINES);
glVertex2d(vx0,vy0);
glVertex2d(vx1,vy1);

glEnd();
glFlush();
}
}
void drawline()
{
glBegin(GL_LINES);
glVertex2f(x0,y0);
glVertex2f(x1,y1);
glEnd();
}
void drawrect()
{
glBegin(GL_LINE_LOOP);

glVertex2f(xmin,ymin);
glVertex2f(xmax,ymin);
glVertex2f(xmax,ymax);
glVertex2f(xmin,ymax);
glEnd();
glFlush();
}
int computeoutcode(float x,float y)
{
int code=0;
if(y>ymax)
 code=TOP;
else if(y<ymin)
 code=BOTTOM;
if(x<xmin)
 code=LEFT;
else if(x>xmax)
 code=RIGHT;
return code;
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
drawline();
glColor3f(0.0,0.0,1.0);
drawrect();
CSLCA(x0,y0,x1,y1);
glFlush();
}
void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(1.0,0.0,0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,499.0,0.0,499.0);
}
int main(int argc,char ** argv)
{
printf("Enter the end points of clipping window\n");
scanf("%f%f%f%f",&xmin,&ymin,&xmax,&ymax);
printf("Enter the end points");
scanf("%f%f%f%f",&x0,&y0,&x1,&y1);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow("cohen_sutherland line clipping_4MT19CS097");
glutDisplayFunc(display);
myinit();
glutMainLoop();
return 0;
}
