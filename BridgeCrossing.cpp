#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

vector<int> times;
int n, n2;
int f(int s) {
    if (!s) return 0;
    if (!(s&(s-1))) for (int i=0; i<n; ++i) if (s&1<<i) return times[i];
    int r=10000;
    for (int i=0; i<n; ++i)
        if (s&1<<i)
            for (int j=i+1; j<n; ++j)
                if (s&1<<j) {
                    int t=max(times[i], times[j]);
                    int s2=s&~(1<<i)&~(1<<j);
                    if (!s2) {
                        r=min(r, t);
                        continue;
                    }
                    for (int k=0; k<n; ++k)
                    if (!(s2&1<<k))
                        r=min(r, t+times[k]+f(s2|(1<<k)));
                }
    return r;
}
struct BridgeCrossing {
    int minTime(vector<int> times) {
        ::times=times;
        n=times.size(), n2=1<<n;
        return f(n2-1);
    }
};