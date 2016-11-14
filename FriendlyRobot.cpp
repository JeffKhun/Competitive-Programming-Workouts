#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

string inst;
int n;
int dp[301][301];
int f(int idx, int changes) {
    if (idx+1>=n) return 0;
    if (dp[idx][changes]!=0) return dp[idx][changes];
    int r=0, c=0;
    int res=0;
    for (int i=idx; i<n-1; i+=2) {
        if (inst[i]=='U') --r;
        else if (inst[i]=='D') ++r;
        else if (inst[i]=='L') --c;
        else if (inst[i]=='R') ++c;
        if (inst[i+1]=='U') --r;
        else if (inst[i+1]=='D') ++r;
        else if (inst[i+1]=='L') --c;
        else if (inst[i+1]=='R') ++c;
        if (r==0 && c==0)
            res=max(res, 1+f(i+2, changes));
        else {
            if (changes>0)
                res=max(res, 1+f(i+2, changes-1));
        }
    }
    dp[idx][changes]=res;
    return res; 
}
struct FriendlyRobot {
    int findMaximumReturns(string inst, int changes) {
        ::inst=inst;
        n=inst.length();
        memset(dp, 0, sizeof(dp));
        return f(0, changes);
    }
};
