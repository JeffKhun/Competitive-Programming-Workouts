#include <cmath>
#include <cstdlib>
#include <cstdio>
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
#include <bitset>
using namespace std;

struct Gperm {
    int countfee(vector <int> x, vector <int> y) {
        int V=50, E=x.size(), r=INT_MAX;
        for (int i=0; i<(1<<E); ++i) {
            vector<int> d(V+1);
            for (int j=0; j<E; ++j)
                if (i&1<<j)
                    ++d[x[j]];
                else
                    ++d[y[j]];
            bool ok=1;
            for (int j=0; j<E; ++j)
                if (i&1<<j)
                    if (d[x[j]]<d[y[j]]) {
                        ok=0;
                        break;
                    }
                else
                    if (d[y[j]]<d[x[j]]) {
                        ok=0;
                        break;
                    }
            sort(d.begin(), d.end());
            int c1=0, c2=0;
            for (int j=1; j<=V; ++j)
                c2+=(c1+=d[j]);
            r=min(r, c2);
        }
        return r;
    }
};
int main() {
    int x[]={7,8,9};//{45,28,42,5,27,27,42,36,14,27,19,42,24,27,8,31,24,27,14,28};//{4,7,7};//{0,0,1};
    int y[]={4,5,6};//{45,27,45,8,34,34,28,0,11,42,24,19,14,31,45,42,14,24,28,27};//{7,4,4};//{1,2,2};
    vector<int> vx(x, x+sizeof(x)/sizeof(int));
    vector<int> vy(y, y+sizeof(y)/sizeof(int));
    Gperm z;
    cout<<z.countfee(vx, vy)<<endl;
    cin.get();
    return 0;
}
/*
0)

    
{0}
{1}
Returns: 1
One optimal order of painting the vertices is 49, 48, 47, ..., 3, 2, 1, 0. The first 49 times the fee is 0. After Hero paints the last vertex, the last fee is 1.
1)

    
{0,1}
{1,2}
Returns: 2
One optimal order of painting these vertices is 49, 48, ..., 5, 4, 3, 0, 2, 1. The last three fees will be 0, 0, and 2.
2)

    
{4,7,7}
{7,4,4}
Returns: 3

3)

    
{0,0,1}
{1,2,2}
Returns: 4
Hero should first paint the 47 isolated vertices and then the remaining three vertices in any order. Regardless of the order in which Hero paints the last three vertices, the last three fees will be 0, 1, and 3.
4)

    
{7,8,9}
{4,5,6}
Returns: 6

5)

    
{45,28,42,5,27,27,42,36,14,27,19,42,24,27,8,31,24,27,14,28}
{45,27,45,8,34,34,28,0,11,42,24,19,14,31,45,42,14,24,28,27}
Returns: 53
*/

////////////////////////////////////////////////////////

#include <cmath>
#include <cstdlib>
#include <cstdio>
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
#include <bitset>
using namespace std;

struct Gperm {
    int countfee(vector <int> x, vector <int> y) {
        const int n=50, m=x.size();
        for (int i=0; i<(1<<m); ++i)
            dp[i]=INT_MIN;
        vector<int> masks(n);
        for (int i=0; i<m; ++i) {
            masks[x[i]]|=(1<<i);
            masks[y[i]]|=(1<<i);
        }
        dp[0]=m;
        for (int i=0; i<(1<<m); ++i) {
            for (int j=0; j<n; ++j) {
               const int k=i|masks[j];
               const int t=m-__builtin_popcount(k);
               dp[k]=min(dp[k], dp[i]+t);
            }
        }
        return dp[(1<<m)-1];
    }
};
int main() {
    int x[]={45,28,42,5,27,27,42,36,14,27,19,42,24,27,8,31,24,27,14,28};//{4,7,7};//{0,0,1};
    int y[]={45,27,45,8,34,34,28,0,11,42,24,19,14,31,45,42,14,24,28,27};//{7,4,4};//{1,2,2};
    vector<int> vx(x, x+sizeof(x)/sizeof(int));
    vector<int> vy(y, y+sizeof(y)/sizeof(int));
    Gperm z;
    cout<<z.countfee(vx, vy)<<endl;
    cin.get();
    return 0;
}
/*
0)

    
{0}
{1}
Returns: 1
One optimal order of painting the vertices is 49, 48, 47, ..., 3, 2, 1, 0. The first 49 times the fee is 0. After Hero paints the last vertex, the last fee is 1.
1)

    
{0,1}
{1,2}
Returns: 2
One optimal order of painting these vertices is 49, 48, ..., 5, 4, 3, 0, 2, 1. The last three fees will be 0, 0, and 2.
2)

    
{4,7,7}
{7,4,4}
Returns: 3

3)

    
{0,0,1}
{1,2,2}
Returns: 4
Hero should first paint the 47 isolated vertices and then the remaining three vertices in any order. Regardless of the order in which Hero paints the last three vertices, the last three fees will be 0, 1, and 3.
4)

    
{7,8,9}
{4,5,6}
Returns: 6

5)

    
{45,28,42,5,27,27,42,36,14,27,19,42,24,27,8,31,24,27,14,28}
{45,27,45,8,34,34,28,0,11,42,24,19,14,31,45,42,14,24,28,27}
Returns: 53
*/