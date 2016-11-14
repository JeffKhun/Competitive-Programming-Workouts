#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int f[8][8][8][8];
struct CaptureThemAll {
   int fastKnight(string knight, string rook, string queen) {
      int kr=knight[1]-'1', kc=knight[0]-'a';
      int rr=rook[1]-'1', rc=rook[0]-'a';
      int qr=queen[1]-'1', qc=queen[0]-'a';
      for (int i=0; i<8; ++i)
         for (int j=0; j<8; ++j)
            for (int r=0; r<8; ++r)
               for (int c=0; c<8; ++c) {
                  f[i][j][r][c]=10000;
                  if (i==r && j==c) f[i][j][r][c]=0;
                  if (abs(i-r)==2 && abs(j-c)==1) f[i][j][r][c]=1;
                  if (abs(i-r)==1 && abs(j-c)==2) f[i][j][r][c]=1;
               }
      for (int a=0; a<8; ++a)
         for (int b=0; b<8; ++b)
            for (int k=0; k<8; ++k)
               for (int i=0; i<8; ++i)
                  for (int j=0; j<8; ++j)
                     for (int r=0; r<8; ++r)
                        for (int c=0; c<8; ++c)
                           f[i][j][r][c]=min(f[i][j][r][c],f[i][j][a][b]+f[a][b][r][c]);
      return min(f[kr][kc][rr][rc]+f[rr][rc][qr][qc], f[kr][kc][qr][qc]+f[qr][qc][rr][rc]);
   }
};