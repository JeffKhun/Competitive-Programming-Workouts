#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

string s;
int n;
int g[301][301];
int f(int idx, int k, int r, int c) {
    if (idx+1>=n) return 0;
    if (!r && !c && !g[idx][k]) return g[idx][k];
    if (s[idx]=='U') ++r;
    else if (s[idx]=='D') --r;
    else if (s[idx]=='L') --c;
    else ++c;
    if (s[idx+1]=='U') ++r;
    else if (s[idx+1]=='D') --r;
    else if (s[idx+1]=='L') --c;
    else ++c;
    int res=0;
    if (!r && !c) {
        if (g[idx+2][k]!=0) res=max(res, 1+g[idx+2][k]);
        else {
            g[idx+2][k]=f(idx+2, k, 0, 0);
            res=max(res, 1+g[idx+2][k]);
        }
    } else {
        if (k) {
            if (g[idx+2][k-1]!=0) res=max(res, 1+g[idx+2][k-1]);
            else {
                g[idx+2][k-1]=f(idx+2, k-1, 0, 0);
                res=max(res, 1+g[idx+2][k-1]);
            }
        }
        res=max(res, f(idx+2, k, r, c));
    }
    return res;
}
struct FriendlyRobot {
    int findMaximumReturns(string s, int k) {
        ::s=s;
        ::n=s.length();
        return f(0, k, 0, 0);
    }
};