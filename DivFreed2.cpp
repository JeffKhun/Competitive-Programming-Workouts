#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[11][100001];
int mod=1e9+7;
struct DivFreed2 {
   int count(int n, int k) {
        for (int i=1; i<=k; ++i) dp[0][i]=1;
        for (int i=1; i<n; ++i) {
            ll sum=0;
            for (int j=1; j<=k; ++j)
                sum=(sum+dp[i-1][j])%mod;
            for (int j=1; j<=k; ++j) {
                ll sum2=0;
                for (int f=2; f*j<=k; ++f)
                    sum2=(sum2+dp[i-1][f*j])%mod;
                dp[i][j]=(sum-sum2)%mod;
            }
       }
       ll r=0;
       for (int i=1; i<=k; ++i)
            r=(r+dp[n-1][i])%mod;
       return r;
   } 
};
