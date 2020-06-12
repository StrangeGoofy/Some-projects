#ifndef _ADDON_H_                  
#define _ADDON_H_

#include "ANIM.H"
#include "VEC.H"
//#include
namespace segl
{                                     
  class addon : public object
  {
  private:
    static const int H = 700, W = 700;
    FILE *F;
    vec P[26][4][4];
    vec G[H][W];
                              
  public:
    void Render ( anim *Ani )
    {  
      
     int K;

      glLoadIdentity();
      gluLookAt(1, 1.9, 3, 0, 0, 0, 0, 1, 0);
     
      glRotated( -30 * Ani->Time, 0, 1, 0);
      glDisable(GL_LIGHTING);

      F = fopen("X:/TEACUP.TXT", "r");
      if (F == NULL)
        return;      
      fscanf(F, "%i", &K);
      for (int p = 0; p < K; p++)
        for (int i  = 0; i < 4; i++)
          for (int j = 0; j < 4; j++)
            for (int c = 0; c < 3; c++)
              fscanf(F, "%lf", &P[p][i][j][c]);
      fclose(F);

      int j, i;
      double u, v;
      int c[4] = {1, 3, 3, 1};
      for (i  = 0, v = 0; i < H; i++, v += 1.0 / (H-1))
      {
        double 
          vn[4] = {1, v, v * v, v * v * v},
          v1n[4] = {1, 1 - v, (1 - v) * (1 - v), (1 - v) * (1 - v) * (1 - v)};
        for (j = 0, u  = 0; j < W; j++, u += 1.0 / (W - 1))
        {
          double 
            un[4] = {1, u, u * u, u * u * u},
            u1n[4] = {1, 1 - u, (1 - u) * (1 - u), (1 - u) * (1 - u) * (1 - u)}; 
          
          for (int r = 0; r < K; r++)
          {
            vec v = vec(0, 0, 0);
            for (int s = 0; s < 4; s++)
              for (int t = 0; t < 4; t++)
              
              v += P[r][s][t] * (c[s] * c[t] * u1n[t] * un[3 - t] * u1n[s] * vn[3 - s]);
          G[i][j] = v;
           }
        }
      }
      //for (int p = 0; p < K; p++)
      for( int i = 0; i < 4; i++ )
      {
        glBegin(GL_TRIANGLE_STRIP);
        for( int j = 0; j < 4; j++ )
        {
          glColor3d(1, 0, 0);
          glVertex3d(G[i][j].x, G[i][j].y, G[i][j].z);
        }
        glEnd();
      }
      /*for( int i = 0; i < K; i++ )
        for( int j = 0; j < K; j++ )
        {
          glColor3d(1, 0, 0);
            glPushMatrix();
            glTranslated( G[i][j].x, G[i][j].y, G[i][j].z);
            glutSolidSphere(0.01, 16, 16);
            glPopMatrix();
        }                  */
       /*for (int p = 0; p < K; p++)
          for (int i  = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
               glPushMatrix();
               glTranslated( P[p][i][j].x,P[p][i][j].y, P[p][i][j].z);
               glutSolidSphere(0.01, 16, 16);
               glPopMatrix();
            } */
    }    
  };
}

#endif