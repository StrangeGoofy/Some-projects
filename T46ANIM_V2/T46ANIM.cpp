/*Streltsov Stepan, 15.11.2019, 11-2 b*/
#include "BALL.h"
#include "ANIM.h"

int main( void )
{
  segl::anim &My = segl::anim::Get();
  My<< new segl::ball;

  My.Run();

  return 0;
}