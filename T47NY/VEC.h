#ifndef _VEC_H_                  
#define _VEC_H_

#include "ANIM.H"

namespace segl
{
  class vec
    {
    public:
      double x, y, z;
      vec( void )
      {
      }
      vec( double A, double B, double C ) : x(A), y(B), z(C)
      {
      }
      vec operator+( const vec &V ) const
      {
        return vec(V.x + x, V.y + y, V.z + z);
      }
      vec operator-( const vec &V ) const
      {
        return vec(x - V.x, y - V.y, z - V.z);
      }
      vec operator/( double N )
      {
        return vec(x / N, y / N, z / N);
      }
      vec operator*( double N )
      {
        return vec(x * N, y * N, z * N);
      }
      vec & operator+=( const vec &V ) 
      {
        x += V.x;
        y += V.y;
        z += V.z;
        return *this;
      }
      vec & operator-=( const vec &V )
      {
        x -= V.x;
        y -= V.y;
        z -= V.z;
        return *this;
      }
      vec operator/=( double N )
      {
        x /= N;
        y /= N;
        z /= N;
      }
      vec operator*=( double N )
      {
        x *= N;
        y *= N;
        z *= N;
      }
      static double r1( void )
      {
        return rand()/(double)RAND_MAX;
      }
      static vec Rnd1( void )
      {
        return vec(r1(), r1(), r1());
      }  
      static vec zero( void )
      {
        return vec(0, 0, 0);
      }
      double & operator[](int i)
      {
        return *(&x + i);
      } 
    };
}
#endif