#include <bits/stdc++.h>
using namespace std;

//BOTTOM-UP DP
int f[51][2];
struct ZigZag {
    int longestZigZag(vector<int> sequence) {
        int n=sequence.size();
        f[n-1][0]=f[n-1][1]=1;
        for (int i=n-2; i>=0; --i) {
            if (sequence[i]<sequence[i+1])
                f[i][0]=max(f[i+1][0], 1+f[i+1][1]);
            else if (sequence[i]>sequence[i+1])
                f[i][1]=max(f[i+1][1], 1+f[i+1][0]);
            else {
                f[i][0]=f[i+1][0];
                f[i][1]=f[i+1][1];
            }
        }
        return max(f[0][0], f[0][1]);
   }
};


//TOP-DOWN DP
vector<int> sequence;
int n;
int dp[51][1][1];
int f(int idx, bool lt, bool gt) {
    if (idx==n-1) return 1;
    int &r=dp[idx][lt][gt];
    if (r) return r;
    if (lt && sequence[idx]<sequence[idx+1])
        r=max(r, 1+f(idx+1, 0, 1));
    if (gt && sequence[idx]>sequence[idx+1])
        r=max(r, 1+f(idx+1, 1, 0));
    dp[idx][lt][gt]=r=max(r, f(idx+1, lt, gt));
    return r;
}
struct ZigZag {
    int longestZigZag(vector<int> sequence) {
        if (sequence.size()<2) return sequence.size();
        ::sequence=sequence;
        ::n=sequence.size();
        return f(0, 1, 1);
    }
};