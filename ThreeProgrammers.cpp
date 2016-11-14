#include <bits/stdc++.h>
using namespace std;

set<vector<int>> dp;
string f(int a, int b, int c, int bs, int cs) {
    if (!a && !b && !c) return "";
    vector<int> v(5);
    v[0]=a; v[1]=b; v[2]=c; v[3]=bs; v[4]=cs;
    if (dp.find(v)!=dp.end()) return "impossible";
    dp.insert(v);
    if (a) {
        string s=f(a-1, b, c, max(0, bs-1), max(0, cs-1));
        if (s!="impossible") return 'A'+s;
    }
    if (b && !bs) {
        string s=f(a, b-1, c, bs+1, max(0, cs-1));
        if (s!="impossible") return 'B'+s;
    }
    if (c && !cs) {
        string s=f(a, b, c-1, max(0, bs-1), cs+2);
        if (s!="impossible") return 'C'+s;
    }
    return "impossible";
}
struct ThreeProgrammers {
    string validCodeHistory(string code) {
        vector<int> v(3);
        for (int i=0; i<code.length(); ++i)
            ++v[code[i]-'A'];
        return f(v[0], v[1], v[2], 0, 0);
    }
};
