#ifndef _BEZPATCH_H_                  
#define _BEZPATCH_H_

#include "ANIM.H"
#include "VEC.H"

namespace segl
{
  class bez_patch : public object
  {     
  private:
    vec P[2][2];
    static const int N = 22, M = 25;
    vec G[N][M], GN[N][M];
  public:
    bez_patch ( void )
    {
      for( int i = 0; i < 2; i++ )
        for( int j = 0; j < 2; j++ )                
          P[i][j] = vec( j * 2 - 1, 0, 2 * i - 1 ); 
    }

    void Cube( void )
    {
      glColor3d(1, 1, 1);      
      glutWireCube(2);
    }    

    void Render( anim *Ani )
    {
      glLoadIdentity();
      gluLookAt(1, 1.9, 3, 0, 0, 0, 0, 1, 0);
      glRotated( -30 * Ani->Time, 0, 1, 0);
      glDisable(GL_LIGHTING);
      Cube();

      //главные точки
      for( int i = 0; i < 2; i++ )
        for( int j = 0; j < 2; j++ )
        { 

          P[i][j].y = sin(Ani->Time * (2 + (i + j) * 0.1 * 2 * i ));
        }


       /* for( int i = 0; i < N; i++ )
          for( int j = 0; j < M; j++ )
          {
            double 
              u = j / (M - 1.0),
              v = i / (N - 1.0);
            vec R = P[0][0] * (1 - u) * (1 - v) + P[0][1] * u * (1 - v) + P[1][0] * (1 - u) * v + P[1][1] * u * v;
            glColor3d(1, 0, 0);
            glPushMatrix();
            glTranslated(R.x, R.y, R.z);
            glutSolidSphere(0.03, 16, 16);
            glPopMatrix();
          }         */

          for( int i = 0; i < N; i++ )
            for( int j = 0; j < M; j++ )
            {
              double 
                u = j / (M - 1.0),
                v = i / (N - 1.0);
              G[i][j] = P[0][0] * (1 - u) * (1 - v) + P[0][1] * u * (1 - v) + P[1][0] * (1 - u) * v + P[1][1] * u * v;
              glColor3d(1, 0, 0);
              glPushMatrix();
              glTranslated( G[i][j].x, G[i][j].y, G[i][j].z);
              glutSolidSphere(0.01, 16, 16);
              glPopMatrix();
            }

            for( int i = 0; i < N; i++ )
            {
              glBegin(GL_LINE_STRIP);
              for( int j = 0; j < M; j++ )
              {
               glVertex3d(G[i][j].x, G[i][j].y, G[i][j].z);
              }
              glEnd();
            }

            for( int j = 0; j < M; j++ )
            {
              glBegin(GL_LINE_STRIP);
              for( int i = 0; i < N; i++ )
              {
               glVertex3d(G[i][j].x, G[i][j].y, G[i][j].z);
              }
              glEnd();
            }
            glColor3d(1, 1, 0);
            for( int i = 0; i < N - 1; i++ )
            {
              glBegin(GL_TRIANGLE_STRIP);
              for( int j = 0; j < M; j++ )
              {
               glVertex3dv(&G[i + 1][j].x);
               glVertex3dv(&G[i][j].x);
              }
              glEnd();
            }

    }
  };
}

#endif