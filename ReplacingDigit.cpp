#include <bits/stdc++.h>
using namespace std;

struct ReplacingDigit {
    int getMaximumStockWorth(vector<int> A, vector<int> D) {
        vector<vector<int>> v(8, vector<int>());
        for (int i=0; i<A.size(); ++i) {
            int idx=0, t=A[i];
            while (t) {
                v[idx++].push_back(t%10);
                t/=10;
            }
        }
        for (int i=7; i>=0; --i) {
            sort(v[i].begin(), v[i].end());
            for (int j=0; j<v[i].size(); ++j)
                for (int k=9; k>0; --k)
                    if (D[k-1] && k>v[i][j]) {
                        v[i][j]=k;
                        --D[k-1];
                    }
        }
        int r=0;
        for (int i=7; i>=0; --i) {
            r*=10;
            for (int j=0; j<v[i].size(); ++j)
                r+=v[i][j];
        }
        return r;
    }
};