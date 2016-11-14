#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
using namespace std;

map<long long, bool> m;
struct Cdgame {
    int rescount(vector<int> a, vector<int> b) {
        long long asum=accumulate(a.begin(), a.end(), 0);
        long long bsum=accumulate(b.begin(), b.end(), 0);
        for (int i=0; i<a.size(); ++i)
            for (int j=0; j<b.size(); ++j) {
                long long ta=asum-a[i]+b[j];
                long long tb=bsum-b[j]+a[i];
                m[ta*tb]=true;
            }
        return m.size();
   }
};
