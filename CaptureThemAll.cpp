#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int f[8][8][8][8];
struct CaptureThemAll {
    int fastKnight(string knight, string rook, string queen) {
        for (int a=0; a<8; ++a)
            for (int b=0; b<8; ++b)
                for (int c=0; c<8; ++c)
                    for (int d=0; d<8; ++d) {
                        if (a==c && b==d) f[a][b][c][d]=0;
                        else f[a][b][c][d]=1000;
                        if (abs(a-c)==1 && abs(b-d)==2) f[a][b][c][d]=1;
                        if (abs(a-c)==2 && abs(b-d)==1) f[a][b][c][d]=1;
                    }
        for (int i=0; i<8; ++i)
            for (int j=0; j<8; ++j)
                for (int a=0; a<8; ++a)
                    for (int b=0; b<8; ++b)
                        for (int c=0; c<8; ++c)
                            for (int d=0; d<8; ++d)
                                f[a][b][c][d]=min(f[a][b][c][d], f[a][b][i][j]+f[i][j][c][d]);
        int kr=knight[0]-'a', kc=knight[1]-'1';
        int rr=rook[0]-'a', rc=rook[1]-'1';
        int qr=queen[0]-'a', qc=queen[1]-'1';
        return min(f[kr][kc][rr][rc]+f[rr][rc][qr][qc], f[kr][kc][qr][qc]+f[qr][qc][rr][rc]);
    }
};
