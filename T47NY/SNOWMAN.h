#ifndef _SNOWMAN_H_
#define _SNOWMAN_H_

#include "ANIM.h"

namespace segl
{
  class snowman : public object
  {
  public:
    double r1( void )
    {
       return 9.0 * (2.0 * rand() / RAND_MAX-1);
    }
    double X, Z;
    snowman( void )
    {
      X = r1();
      Z = r1();
    }
    void Render( anim *Ani )
    { 

      glTranslated(0.5*X*sin(0.2 * X * Ani->Time), 0, 0.6*Z*sin(0.2 * Z * Ani->Time)*sin(Z * Ani->Time));

      glPushMatrix();

      glTranslated(0, 0.5, 0);
      glColor3d(0.8, 0.8, 1);
      glutSolidSphere(1, 16, 16);
      glTranslated(0, 1, 0);
      glScaled(0.8, 0.8, 0.8);
      glutSolidSphere(1, 16, 16);
      glTranslated(0, 1, 0);                       
      glScaled(0.8, 0.8, 0.8);
      glutSolidSphere(1, 16, 16);
      glTranslated(0, 0.7, 0);
      glRotated(-90, 1, 0, 0);
      glColor3d(0.7, 0.2, 0.2);
      glutSolidCone(0.7, 1.5, 8, 8);

      glTranslated(0, -1.8, 0);
      glRotated(-90, 1, 0, 0);
      glRotated(180, 0, 1, 0);
      glTranslated(0, 0.6, -1);
      glScaled(0.5, 0.5, 0.5);
      glutSolidCone(0.3, 2, 8, 8);

      glPopMatrix();
    }
  };
}

#endif