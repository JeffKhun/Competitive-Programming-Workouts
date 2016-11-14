#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct MoveStonesEasy {
    int get(vector<int> a, vector<int> b) {
        int n=a.size();
        vector<int> v(n);
        for (int i=0; i<n; ++i)
            v[i]=b[i]-a[i];
        int res=0;
        for (int i=0; i<n; ++i) {
            if (v[i]==0) continue;
            if (v[i]>0) {
                for (int j=i+1; j<n; ++j) {
                    if (v[i]==0) break;
                    if (v[j]<0) {
                        int t=min(v[i], -v[j]);
                        v[i]-=t;
                        v[j]+=t;
                        res+=(t*(j-i));
                    }
                }
                if (v[i]!=0) return -1;
            } else {
                for (int j=i+1; j<n; ++j) {
                    if (v[i]==0) break;
                    if (v[j]>0) {
                        int t=min(-v[i], v[j]);
                        v[i]+=t;
                        v[j]-=t;
                        res+=(t*(j-i));
                    }
                }
                if (v[i]!=0) return -1;
            }
        }
        return res;
    }
};
