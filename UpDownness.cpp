#include <cmath>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <bitset>
using namespace std;

int N, K, mod=1e9+7;
int DP[51][5010];
struct UpDownNess {
    int count(int n, int k) {
        vector<vector<int>> DP(n+1, vector<int>(k+1, 0));
        DP[1][0]=1;
        for(int i=2; i<=n; ++i) {
            cout<<"--> i="<<i<<endl;
            for (int pos=1; pos<=i; ++pos) {
                cout<<"("<<pos<<"-"<<1<<")"<<'*'<<"("<<i<<"-"<<pos<<")"<<endl;
                int to_add=(pos-1)*(i-pos);
                cout<<"to_add: "<<to_add<<endl;
                for (int j=0; j<=k-to_add; ++j) {
                    DP[i][j+to_add]+=DP[i-1][j];
                    cout<<"updated dp, ";
                    if (DP[i][j+to_add]>=mod)
                        DP[i][j+to_add]-=mod;
                }
                cout<<endl;
            }
        }
        cout<<"------------------------"<<endl;
        for (int i=0; i<=n; ++i) {
            for (int j=0; j<=k; ++j)
                cout<<DP[i][j]<<' ';
            cout<<'\n';
        }
        cout<<endl;
        return DP[n][k];
    }
};
int main() {
    int n=5;
    int k=3;
    UpDownNess z;
    cout<<z.count(n, k)<<endl;
    cin.get();
    return 0;
}
/*
0)

    
3
1
Returns: 2
{1,3,2} and {2,3,1} meet the condition.
1)

    
3
0
Returns: 4
{1,2,3},{2,1,3},{3,1,2} and {3,2,1} meet the conditon.
2)

    
4
3
Returns: 4
Here, the four good permutations are {1,3,4,2}, {1,4,3,2}, {2,3,4,1}, and {2,4,3,1}.

For the permutation P={1,3,4,2} the three lo-hi-lo triples of indices are the following ones:
(0,1,3)==>(1,3,2), because we have 1 < 3 > 2.
(0,2,3)==>(1,4,2), because we have 1 < 4 > 2.
(1,2,3)==>(3,4,2), because we have 3 < 4 > 2.
(Note that all the indices used above are 0-based: P[0]=1, P[1]=3, P[2]=4, and P[3]=2.)
3)

    
19
19
Returns: 24969216

4)

    
50
2000
Returns: 116596757
*/