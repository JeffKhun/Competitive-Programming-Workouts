#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct AttackOfTheClones {
    int count(vector<int> a, vector<int> b) {
        int res=0;
        int n=a.size();
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (a[i]==b[j]) {
                    int lo=i, hi=j, t=0;
                    while (lo!=hi) {
                        lo=((lo+n-1)%n);
                        ++t;
                        if (lo<=hi) break;
                    }
                    res=max(res, t);
                }
        return res+1;
    }
};
