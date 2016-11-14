#include <bits/stdc++.h>
using namespace std;

long long f[101][101];
bool blocked[101][101][101][101];
struct AvoidRoads {
    long long numWays(int width, int height, vector<string> bad) {
        for (int i=0; i<bad.size(); ++i) {
            int r1, c1, r2, c2;
            istringstream iss(bad[i]);
            iss>>r1>>c1>>r2>>c2;
            blocked[r1][c1][r2][c2]=blocked[r2][c2][r1][c1]=1;
        }
        if (!blocked[0][0][0][1]) f[0][1]=1;
        if (!blocked[0][0][1][0]) f[1][0]=1;
        for (int i=0; i<=height; ++i)
            for (int j=0; j<=width; ++j) {
                if (i-1>=0 && !blocked[i-1][j][i][j]) f[i][j]+=f[i-1][j];
                if (j-1>=0 && !blocked[i][j-1][i][j]) f[i][j]+=f[i][j-1];
            }
        return f[height][width];
   }
};
