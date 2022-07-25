#include<GL/glut.h>
#include<stdio.h>
void tableLeg(double thick,double len)
{
glPushMatrix();
glScaled(thick,len,thick);
glutSolidCube(1.0);
glPopMatrix();
}
void table(double topWid,double topThick,double legThick,double legLen)
{
glPushMatrix();
glTranslated(0,legLen,0);
glScaled(topWid,topThick,topWid);
glutSolidCube(1.0);
glPopMatrix();
glPushMatrix();
glTranslated(0.28,0.15,0.28);
tableLeg(legThick,legLen);
glTranslated(0.0,0.0,-2*0.28);
tableLeg(legThick,legLen);
glTranslated(-2*0.28,0,0);
tableLeg(legThick,legLen);
glTranslated(0.0,0.0,2*0.28);
tableLeg(legThick,legLen);
glPopMatrix();
}
void displaySolid(void)
{
	//glColor3f(1.0,1.0,1.0);
GLfloat mat_ambient[]={0.2f,0.7f,0.2f,1.0f};
GLfloat mat_diffuse[]={0.0f,0.0f,0.0f,0.0f};
GLfloat mat_specular[]={0.0f,1.0f,0.0f,1.0f};
GLfloat mat_shininess[]={50.0f};
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
GLfloat lightIntensity[]={1.0f,1.0f,1.0f,1.0f};
GLfloat light_position[]={2.0f,6.0f,3.0f,0.0f};
glLightfv(GL_LIGHT0,GL_POSITION,light_position);
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-1,1,-1,1,-1,10.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(2.3,1.3,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glPushMatrix();
glTranslatef(0.6,0.38,0.5);
glRotated(30,0,1,0);
glutSolidTeapot(0.08);
glPopMatrix();
glPushMatrix();
glTranslatef(0.4,0,0.4);
table(0.6,0.02,0.02,0.3);
glPopMatrix();
glFlush();
}
int main(int argc,char **argv)
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
     glutInitWindowSize(640,480);
     glutInitWindowPosition(100,100);
     
     glutCreateWindow("Simple Shaded Teapot");
     glutDisplayFunc(displaySolid);
     glEnable(GL_LIGHTING);
      glEnable(GL_LIGHT0);
      glShadeModel(GL_SMOOTH);
       glEnable(GL_DEPTH_TEST);
      glEnable(GL_NORMALIZE);
      glClearColor(0.0,0.0,0.0,0.0);
      glutMainLoop();
      }
     
     



