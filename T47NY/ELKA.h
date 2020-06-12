#ifndef _ELKA_H_
#define _ELKA_H_

#include <cstdlib>

#include "ANIM.h"

namespace segl
{ 
  class elka : public object
  {
  public:
    double r1( void )
    {
       return 9.0 * (2.0 * rand() / RAND_MAX-1);
    }
    double X, Z;
    elka( void )
    {
      X = r1();
      Z = r1();
    }
    void Render( anim *Ani )
    { 
      glTranslated(X, 0, Z);

      glPushMatrix();  
      glScaled(1, 5, 1);
      glColor3d(0.5, 0.3, 0.01);
      glutSolidCube(0.5);
      glPopMatrix();

      glTranslated(0, 1, 0);

      glPushMatrix();     
      glRotated(-90, 1, 0, 0);
      glRotated(6*X*sin(3 * Ani->Time) - X, 1, 0, 1);
      glColor3d(0.1, 0.9, 0.1);
      glutSolidCone(1, 1, 8, 8);

      glRotated(2*X*sin(3
        * Ani->Time), 1, 0, 1);
      glScaled(0.8, 0.8, 0.8);
      glTranslated(0, 0, 1);
      glutSolidCone(1, 1, 8, 8);
      glPopMatrix();
    } 
  };
}

#endif