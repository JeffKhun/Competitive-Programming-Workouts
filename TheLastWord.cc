#include <bits/stdc++.h>
using namespace std;

int main() {
    int ntc;
    cin>>ntc;
    for (int tc=1; tc<=ntc; ++tc) {
        string s;
        cin>>s;
        string r(1, s[0]);
        for (int i=1; i<s.length(); ++i) {
            if (s[i]>=r[0]) r=s[i]+r;
            else r+=s[i];
        }
        cout<<"Case #"<<tc<<": "<<r<<'\n';
    }
    return 0;
}
