#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> dp2;
int gcd(int a, int b) {
    pair<int, int> p=make_pair(a, b);
    if (dp2.find(p)!=dp2.end()) return dp2[p];
    while (b) {
        int t=a;
        a=b;
        b=t%a;
    }
    dp2[p]=a;
    return a;
}
int t;
bool ok=0;
set<vector<int>> dp;
void f(vector<int> v) {
    if (!(v.size())) return;
    if (dp.find(v)!=dp.end()) return;
    dp.insert(v);
    for (int i=0; i<v.size()-1; ++i)
        for (int j=i+1; j<v.size(); ++j) {
            int aa=max(v[i], v[j]), bb=min(v[i], v[j]);
            int g=gcd(aa, bb);
            int l=(aa*bb)/g;
            if (v.size()==2) {
                if (g==t || l==t)
                    ok=1;
                return;
            }
            vector<int> vt1(v);
            vt1.erase(vt1.begin()+i); vt1.erase(vt1.begin()+j-1);
            vt1.push_back(g);
            f(vt1);
        }
    return;
}
class LCMGCD {
public:
    string isPossible(vector <int> x, int t) {
        string s1="Possible", s2="Impossible";
        ::t=t;
        f(x);
        return (ok==1)?s1:s2;
    }
};