#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int f[1000001];
struct BearDartsDiv2 {
    long long count(vector<int> w) {
        long long ans=0;
        for (int i=0; i<w.size(); ++i) {
            ans+=f[w[i]];
            for (int j=0; j<i; ++j) {
                for (int k=0; k<j; ++k) {
                    long long t=w[i]*w[j]*w[k];
                    if (t<=1000000)
                        ++f[t];
                }
            }
        }
        return ans;
    }
};
