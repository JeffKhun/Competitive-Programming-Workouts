#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

bool f[2501][2501];
struct BalancedSubstrings {
    int countSubstrings(string s) {
        for (int i=0; i<s.length(); ++i) f[i][i]=1;
        for (int t=1; t<s.length(); ++t)
            for (int i=0, j=t; j<s.length(); ++i, ++j)
                for (int k=i; k<=j; ++k) {
                    int lsum=0, rsum=0;
                    for (int l=k-1, idx=1; l>=i; --l, ++idx)
                        lsum+=(s[l]-'0')*idx;
                    for (int r=k+1, idx=1; r<=j; ++r, ++idx)
                        rsum+=(s[r]-'0')*idx;
                    if (lsum==rsum) {
                        f[i][j]=1;
                        break;
                    }
                }
        int count=0;
        for (int i=0; i<s.length(); ++i)
            for (int j=0; j<s.length(); ++j)
                if (f[i][j]) ++count;
        return count;
   }
};
