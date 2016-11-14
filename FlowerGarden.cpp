#include <bits/stdc++.h>
using namespace std;

struct FlowerGarden {
    vector<int> getOrdering(vector<int> height, vector<int> bloom, vector<int> wilt) {
        int n=height.size();
        vector<int> f(n);
        vector<bool> intree(n);
        for (int i=0; i<n; ++i) {
            int best=-1;
            for (int j=0; j<n; ++j) {
                if (intree[j]) continue;
                bool ok=1;
                for (int k=0; k<n; ++k) {
                    if (!intree[k] && k!=j && height[j]>height[k] && wilt[j]>=bloom[k] && bloom[j]<=wilt[k]) {
                        ok=0;
                        break;
                    }
                }
                if (ok && (best==-1||height[best]<height[j]))
                    best=j;
            }
            f[i]=height[best];
            intree[best]=true;
        }
        return f;
    }
};
