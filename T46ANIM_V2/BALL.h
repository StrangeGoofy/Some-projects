#ifndef _BALL_H_
#define _BALL_H_

#include "ANIM.h"

namespace segl
{
  class ball : public object
  {
    void Render( anim *Ani )
    {
      for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
      {
        glPushMatrix();
        glTranslated(j, 0, i);
        glScaled(0.9, 0.25, 0.9);
        glTranslated(0, -0.5, 0);
        glColor3d((i+j) % 2, 1 - (i+j) % 2, 1);
        glutSolidCube(1);
        glPopMatrix();
      }            
    }
  };
}

#endif