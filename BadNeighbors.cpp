#include <bits/stdc++.h>
using namespace std;

//BOTTOM-UP DP
int f[41][41];
struct BadNeighbors {
    int maxDonations(vector<int> donations) {
        int n=donations.size();
        for (int t=0; t<n; ++t)
            for (int i=0, j=t; j<n; ++i, ++j)
                f[i][j]=max(f[i+1][j], donations[i]+f[i+2][j]);
        return max(f[0][n-2], f[1][n-1]);
    }
};


//TOP-DOWN DP
int dp[41][41];
vector<int> donations;
int f(int i, int j) {
    if (i==j) return donations[i];
    if (i>j) return 0;
    int &r=dp[i][j];
    if (r) return r;
    r=donations[i]+f(i+2, j);
    r=max(r, f(i+1, j));
    return r;
}
struct BadNeighbors {
    int maxDonations(vector<int> donations) {
        ::donations=donations;
        return max(f(0, donations.size()-2), f(1, donations.size()-1));
    }
};