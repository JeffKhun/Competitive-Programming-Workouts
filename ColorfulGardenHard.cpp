#include <bits/stdc++.h>
using namespace std;

int dp[15][1<<15][15];
string garden, forbid;
int n, mod=1e9+7;
int f(int depth, int mask, int prev) {
    if (depth==n) return 1;
    int &c=dp[depth][mask][prev];
    if (c) return c;
    for (int i=0; i<n; ++i) {
        if (!(mask&(1<<i)) && garden[i]!=forbid[depth])
            if (!depth || garden[i]!=garden[prev]) {
                bool ok=1;
                for (int j=0; j<i; ++j)
                    if (!(mask&(1<<j)) && garden[i]==garden[j]) {
                        ok=0;
                        break;
                    }
                if (ok) {
                    c+=f(depth+1, mask|(1<<i), i);
                    if (c>=mod) c-=mod;
                }
            }
    }
    return c;
}
struct ColorfulGardenHard {
    int count(string garden, string forbid) {
        ::garden=garden; ::forbid=forbid;
        ::n=garden.length();
        return f(0, 0, -1);
    }
};