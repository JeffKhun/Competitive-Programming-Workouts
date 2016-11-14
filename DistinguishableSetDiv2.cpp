#include <bits/stdc++.h>
using namespace std;

struct DistinguishableSetDiv2 {
    int count(vector<string> answer) {
        int n=answer.size(), m=answer[0].length(), m2=1<<m, r=0;
        for (int i=1; i<m2; ++i) {
            vector<string> v(n);
            for (int j=0; j<m; ++j) {
                if (i&1<<j) {
                    for (int k=0; k<n; ++k) {
                        v[k]+=answer[k][j];
                    }
                }
            }
            set<string> cache;
            for (int i=0; i<v.size(); ++i)
                cache.insert(v[i]);
            if (cache.size()==n) ++r;
        }
        return r;
    }
};
