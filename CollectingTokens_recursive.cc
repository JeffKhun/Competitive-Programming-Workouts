#include <bits/stdc++.h>
using namespace std;

vector<int> tokens;
bool tree[51][51];
bool intree[51];
int n;
int f(int node, int L) {
    if (!L) return 0;
    int r=0;
    for (int i=0; i<n; ++i) {
        if (tree[node][i]) {
            if (!intree[i]) {
                intree[i]=1;
                r=max(r, tokens[i]+f(i, L-1));
                intree[i]=0;
            }
            else
                r=max(r, f(i, L-1));
        }
    }
    return r;
}
struct CollectingTokens {
    int maxTokens(vector<int> A, vector<int> B, vector<int> tokens, int L) {
        n=tokens.size();
        ::tokens=tokens;
        for (int i=0; i<A.size(); ++i) {
            tree[A[i]-1][B[i]-1]=tree[B[i]-1][A[i]-1]=1;
        }
        intree[0]=1;
        return tokens[0]+f(0, L);
    }
};