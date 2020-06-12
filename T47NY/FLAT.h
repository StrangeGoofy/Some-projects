#ifndef _FLAT_H_
#define _FLAT_H_

#include "ANIM.h"

namespace segl
{
  class flat : public object
  {
    void Render( anim *Ani )
    {   
      glPushMatrix();

      glScaled(20, 0.5, 20);
      glTranslated(0, -0.5, 0);
      glColor3d(1, 1, 1);
      glutSolidCube(1);                     

      glPopMatrix();
    }
  };
}

#endif