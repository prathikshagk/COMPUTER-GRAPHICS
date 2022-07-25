
#include<GL/glut.h>
#include<stdio.h>
float h=0,k=0;
float theta;
int choice;


void draw_triangle()
{
	
    glBegin(GL_LINE_LOOP);
    glVertex2i(100,100);
    glVertex2i(400,100);
    glVertex2i(250,350);
    glEnd();
}


void display_about_origin()
{
glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    draw_triangle();
    //glTranslatef(100,100,0);
    glRotatef(theta,0,0,1);
    //glTranslatef(-100,-100,0);
    draw_triangle();
    glFlush();
}
    
    
void display_about_fixed_point()
{
	glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    draw_triangle();
    glTranslatef(h,k,0);
    glRotatef(theta,0,0,1);
    glTranslatef(-h,-k,0);
    draw_triangle();
    glLoadIdentity();
    glFlush();
}


int main(int argc,char **argv)
{
   printf("Enter 1 for rotation about the origin\n");
   printf("Enter 2 for rotation about a fixed point\n");
   scanf("%d",&choice);
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowPosition(300,300);
   glutInitWindowSize(500,500);
   if(choice==1)
   {
      printf("Enter angle of rotation\n");
      scanf("%f",&theta);
      glutCreateWindow("Rotation about origin");      
      glutDisplayFunc(display_about_origin);
   }
   else if(choice==2)
   {
      printf("Enter angle of rotation\n");
      scanf("%f",&theta);
      printf("Enter x,y value of pivot(fixed) point\n");
      scanf("%f%f",&h,&k);
      glutCreateWindow("Rotation about fixed point");      
      glutDisplayFunc(display_about_fixed_point);
    }
    else
      printf("Invalid choice\n");
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0,500.0,-500.0,500.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
   // glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
    glutMainLoop();
    return 0;
}
