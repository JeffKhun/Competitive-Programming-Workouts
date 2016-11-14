#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int f[1<<21];
struct OrderOfOperations {
    int minTime(vector<string> s) {
        int n=s.size(), m=s[0].length();
        vector<int> v(n);
        int mask1=0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j)
                v[i]=(v[i]*2)+(s[i][j]-'0');
            mask1|=v[i];
        }
        fill(f, f+(1<<21), 10000);
        f[0]=0;
        for (int i=0; i<(1<<m); ++i)
            for (int j=0; j<n; ++j) {
                int mask2=v[j]|i;
                int mask3=mask2&~i;
                int c=0;
                for (int k=0; k<m; ++k)
                    if (mask3&1<<k)
                        ++c;
                f[mask2]=min(f[mask2], c*c+f[i]);
            }   
        return f[mask1];
    }
};
