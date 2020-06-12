/*Streltsov Stepan, 15.11.2019, 11-2 b*/

#ifndef _ANIM_H_                  
#define _ANIM_H_

#include <stdio.h>    
#include <stdlib.h>
#include <glut.h>
#include <math.h>
#include <time.h>

namespace segl
{
  class anim;
  class object
  {
  public:
    virtual void Render( anim *Ani )
    {
    }   
  };
   class anim
   {
      static anim Instance;
      double Time;
  private:

    static const int MaxNumOfObjects = 600;
    int NumOfObjects;
    object *Objects[MaxNumOfObjects];

      static void Reshape( int W, int H )
    {
      double Size = 0.1, ratio_x = Size, ratio_y = Size;

      glViewport(0, 0, W, H);
      if (W > H)
        ratio_x *= (double)W / H;
      else
        ratio_y *= (double)H / W;

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glFrustum(-ratio_x / 2, ratio_x / 2, -ratio_y / 2, ratio_y / 2, Size, 1000);
      glMatrixMode(GL_MODELVIEW);
    }

    anim(char *Title = "^_^") : NumOfObjects(0)
    {  
      glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

      glutInitWindowPosition(0, 0);
      glutInitWindowSize(700, 700);
      glutCreateWindow(Title);

      glEnable(GL_DEPTH_TEST);
      glEnable(GL_LIGHTING);
      glEnable(GL_LIGHT0);
      glEnable(GL_COLOR_MATERIAL);

      glutDisplayFunc(Display);
      glutKeyboardFunc(Keyboard);
      glutReshapeFunc(Reshape);
    }
    static void Display( void )
    {
      glClearColor(0.25, 0.47, 0.8, 1);
      glClear(GL_COLOR_BUFFER_BIT);
      glClear(GL_DEPTH_BUFFER_BIT);

      glLoadIdentity();
      //glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 500);
      gluLookAt(8, 8, 8, 0, 0, 0, 0, 1, 0);
      
      for (int i = 0; i < Instance.NumOfObjects; i++)
      {
        glPushMatrix();
        Instance.Objects[i]->Render(&Instance);
        glPopMatrix();
      }

      Instance.Time = clock() / (double) CLOCKS_PER_SEC;

      glFinish();
      glutSwapBuffers();
      glutPostRedisplay();
    }
    static void Keyboard( unsigned char Key, int X, int Y )
    {
      if (Key == 27)
        exit(0);
      else if (Key == 'f')
        glutFullScreen();
    }

  public:
    void Run()
      {
        glutMainLoop();
      }        
      static anim&Get()
      {
       return Instance;
      }
      anim&operator<<(object *Obj)
      {
        if (NumOfObjects < MaxNumOfObjects)
          Objects[NumOfObjects++] = Obj;
        return *this;
      }
    };
}

#endif _ANIM_H_
