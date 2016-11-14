#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

struct FourStrings {
    int shortestLength(string a, string b, string c, string d) {
        vector<string> v(4);
        v[0]=a; v[1]=b; v[2]=c; v[3]=d;
        sort(v.begin(), v.end());
        int r=a.length()+b.length()+c.length()+d.length();
        do {
            string s=v[0];
            for (int i=1; i<4; ++i) { 
                if (s.find(v[i])==string::npos) {
                    bool ok=0;
                    for (int t=v[i].length()-2; t>0; --t) {
                        if (s.length()>=t)
                            if (v[i].substr(0, t)==s.substr(s.length()-t)) {
                                s.append(v[i].substr(t));
                                ok=1;
                                break;
                            }
                    }
                    if (!ok) s.append(v[i]);
                }
            }
            r=min(r, (int)s.length());
        } while (next_permutation(v.begin(), v.end()));
        return r;
    }
};