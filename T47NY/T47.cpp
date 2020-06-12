/*Streltsov Stepan, 15.11.2019, 11-2 b*/
#include "ELKA.h"
#include "FLAT.h"
#include "SNOWMAN.h"
#include "SNOW.h"
#include "ANIM.h"
#include "BEZIER.H"
#include "BEZPATCH.h"
#include "ADDON.h"
#include "VEC.H"


int main( void )
{
  segl::anim &My = segl::anim::Get();

  My << new segl::addon;
  /*My << new segl::flat;
  for(int i = 0; i < 9; i++)
    My << new segl::elka;
  My << new segl::snowman;
  for(int j = 0; j < 500; j++)
    My << new segl::snow;*/


  My.Run();

  return 0;
}