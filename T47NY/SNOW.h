#ifndef _SNOW_H_
#define _SNOW_H_

#include "ANIM.h"

namespace segl
{
  class snow : public object
  {
    public:
    double r1( void )
    {
       return 9.0 * (2.0 * rand() / RAND_MAX-1);
    }
    double r0( void )
    {
       return  5 * rand() / RAND_MAX;
    }
    double X, Z, Y;
    snow( void )
    {
      Y = r0();
      X = r1();
      Z = r1();
    }
    void Render( anim *Ani )
    {   
      glTranslated(X, 0, Z);

      glPushMatrix();
      if( Y *5* fabs(sin(Ani->Time)) > 0)
        glTranslated(0, Y *5* fabs(sin(Ani->Time)), 0);
      else 
        glTranslated(0, 0, 0);
      //glTranslated(0, Y * fabs(sin(Ani->Time + 10)) - Y * 3 , 0);
      glColor3d(1, 1, 1);
      glutSolidSphere(0.1, 8, 8);                     

      glPopMatrix();
    }
  };
}

#endif