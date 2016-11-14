#include <bits/stdc++.h>
using namespace std;

int f[1<<20];
struct OrderOfOperationsDiv2 {
    int minTime(vector<string> s) {
        int n=s.size(), n2=1<<n, m=s[0].length();
        vector<int> v(n);
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                v[i]=(v[i]<<1)+(s[i][j]-'0');
        fill(f, f+(1<<20), 1000);
        f[0]=0;
        for (int i=1; i<n2; ++i) {
            for (int j=0; j<n; ++j) {
                if (i&1<<j) {
                    int s2=i&~(1<<j);
                    int mask=0;
                    for (int k=0; k<n; ++k)
                        if (s2&1<<k)
                            mask|=v[k];
                    int mask2=v[j]&~mask;
                    int c=0;
                    for (int k=0; k<m; ++k)
                        if (mask2&1<<k)
                            ++c;
                    f[i]=min(f[i], c*c+f[s2]);
                }
            }
        }
        return f[n2-1];
    }
};
