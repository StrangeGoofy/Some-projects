#pragma once
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
  class anim
  {
    static anim Instance;

  private:
    anim(char *Title = "11")
    {  
      glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

      glutInitWindowPosition(0, 0);
      glutInitWindowSize(1920, 1024);
      glutCreateWindow(Title);
      glutDisplayFunc(Display);
      glutKeyboardFunc(Keyboard);
    }
    static void Display( void )
    {
      glClearColor(0, 0, 0, 1);
      glClear(GL_COLOR_BUFFER_BIT);

      glLoadIdentity();
      glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 500);

      gluLookAt(2, 2, 1, 0, 0, 0, 0, 1, 0);

      glutWireTeapot(0.3);

      glTranslated(0, 0, -1);
      glutWireTorus(0.1, 0.3, 8, 16);

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
    static anim Instance;
    void Run()
      {
        glutMainLoop();
      }        
    };
}

#endif _ANIM_H_
