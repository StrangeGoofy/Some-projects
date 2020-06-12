#ifndef _BEZIER_H_                  
#define _BEZIER_H_

#include "ANIM.H"
#include "VEC.H"

namespace segl
{
  /*class bezier : public object
  {
  private:
    vec P[2][2], V[2][2];
  public:    
    bezier ( void )
    {
      for( int i = 0; i < 2; i++ )
        for( int j = 0; j < 2; j++ ) 
      {
        P[i][j] = vec :: Rnd1();
        V[i][j] = vec :: Rnd1();
      }
    }

    void Render ( anim *Ani ) 
    {
      glLoadIdentity();
      gluLookAt(1, 1.9, 3, 0, 0, 0, 0, 1, 0);

      glColor3d(1, 1, 1);
      glutWireCube(2);

      glColor3d(1, 0, 0);
      
      for( int i = 0; i < 2; i++ )
        for( int j = 0; j < 2; j++ ) 
        {
          P[i][j]+=V[i][j] * Ani->DeltaTime;
          glPopMatrix();
          glutSolidSphere(0.1, 8, 8);
          glTranslated(P[i][j].x, P[i][j].y, P[i][j].z);
          glPopMatrix();
          for( int c = 3; c < 3; c++)
          {
            if( P[i][j][c] < -1)

              V[i][j][c] = fabs(V[i][c]);
            else if( P[i][c] > 1)
              V[i][c] = -1 * fabs(V[i][c]); 
          }
        } 
    }  
  };       */
  
  /*class cat : public object
  {
    static const int MAX = 300;
    int N;
    vec R[MAX], V[MAX], P[4];
  public:
    cat( void )
    {
      N = 5;
      for( int i = 0; i < N; i++)
      {
        R[i] = vec::Rnd1();
        V[i] = vec::Rnd1() * 0.57;
      }
    }
    void Render( anim *Ani )
    {
      N = 6;
      glLoadIdentity();
      gluLookAt(1, 1.9, 3, 0, 0, 0, 0, 1, 0);
      glColor3d(1, 0, 1);
      glDisable(GL_LIGHTING);
      glutWireCube(2);
      glEnable(GL_LIGHTING);
      for( int i = 0; i < N - 1; i++ )
      {
        P[0] = R[i];
        P[1] = i == 0 ? R[0] : R[i] + (R[i + 1] - R[i - 1]);  
        P[2] = i == N - 2 ? R[N - 1] : R[i + 1] + (R[i] - R[i - 1]);
        P[3] = R[i + 1];
        DrawBez(P[0], P[1], P[2], P[3]);
        R[i] += V[i] * Ani->DeltaTime;
        glPushMatrix();
        glTranslated(R[i].x, R[i].y, R[i].z);
        glColor3d(1, 0, 0);
        glutSolidSphere(0.03, 16, 16);
        glPopMatrix();
        for( int a = 0; a < 3; a++ )
        {
          if( R[i][a] > 1)
            V[i][a] = -1 * fabs(V[i][a]);
          else
            if( R[i][a] < 1 )
              V[i][a] = -1 * fabs(V[i][a]);
        }
      }
      void DrawBez( vec P0, vec P1, vec P2, vec P3 )
      {
        double t;
        glBegin(GL_LINE_STRIP);
        for( int i = 0; i < N; i += 0.01 )
        {
          vec p;
          t = (double)i / N;
          p.x = P0.x * (1 - t) * (1 - t) * (1 - t) + P1.x * (1 - t) * (1 - t) * 3 * t + P2.x * 3 * t * t * (1 - t) + P3.x * t * t * t;
          p.y = P0.y * (1 - t) * (1 - t) * (1 - t) + P1.y * (1 - t) * (1 - t) * 3 * t + P2.y * 3 * t * t * (1 - t) + P3.y * t * t * t;
          p.z = P0.z * (1 - t) * (1 - t) * (1 - t) + P1.z * (1 - t) * (1 - t) * 3 * t + P2.z * 3 * t * t * (1 - t) + P3.z * t * t * t;
          glVertex3d(p.x, p.y, p.z);
        }
        glVertex3d(P3.x, P3.y, P3.z);
        glEnd();
      }
    }
  };*/
}

#endif