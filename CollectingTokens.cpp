#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

bool tree[102][102];
bool intree[102];
int f[102][101][2];
vector<int> tokens;
int L;
void dfs(int start) {
    if (intree[start]) return;
    intree[start]=1;
    for (int v=0; v<tokens.size(); ++v)
        if (!intree[v] && tree[start][v]) {
            dfs(v);
            for (int j=L; j>=0; --j)
                for (int k=1; k<=j; ++k) {
                    f[start][j][0]=max(f[start][j][0], f[start][j-k][0]+f[v][k-2][1]);
                    f[start][j][0]=max(f[start][j][0], f[start][j-k][1]+f[v][k-1][0]);
                    f[start][j][1]=max(f[start][j][1], f[start][j-k][1]+f[v][k-2][1]);
                }
        }
}
struct CollectingTokens  {
    int maxTokens(vector<int> A, vector<int> B, vector<int> tokens, int L) {
        ::tokens=tokens;
        ::L=L;
        for (int i=0; i<A.size(); ++i)
            tree[A[i]-1][B[i]-1]=tree[B[i]-1][A[i]-1]=1;
        for (int i=0; i<tokens.size(); ++i)
            for (int j=0; j<=L; ++j)
                f[i][j][0]=f[i][j][1]=tokens[i];
        dfs(0);
        return max(f[0][L][0], f[0][L][1]);
    }
};
