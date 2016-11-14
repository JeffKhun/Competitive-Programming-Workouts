#include <bits/stdc++.h>
using namespace std;

struct EllysSocks {
    int getDifference(vector<int> S, int P) {
        sort(S.begin(), S.end());
        int lo=0, hi=S.back()-S.front()+1, mi, n;
        while (lo<hi) {
            mi=(lo+hi)>>1;
            n=0;
            for (int i=0; i<S.size()-1; ) {
                if (S[i+1]-S[i]<=mi) {
                    ++n;
                    i+=2;
                } else ++i;
                if (n==P) break;
            }
            if (n>=P) hi=mi;
            else lo=mi+1;
        }
        return lo;
    }
};