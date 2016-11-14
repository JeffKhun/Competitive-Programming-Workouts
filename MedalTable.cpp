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

struct C {
    string name;
    int g, s, b;
    C() {}
    C(string name, int g, int s, int b) : name(name), g(g), s(s), b(b) {}
    bool operator<(const C &rhs) const {
        if (g!=rhs.g) return g>rhs.g;
        if (s!=rhs.s) return s>rhs.s;
        if (b!=rhs.b) return b>rhs.b;
        return name<rhs.name;
    }
};
map<string, C> m;
struct MedalTable {
    vector<string> generate(vector<string> results) {
        for (int i=0; i<results.size(); ++i) {
            istringstream iss(results[i]);
            string g, s, b;
            iss>>g>>s>>b;
            pair<map<string, C>::iterator, bool> p=m.insert(make_pair(g, C(g,1,0,0)));
            if (!p.second) ++p.first->second.g; 
            p=m.insert(make_pair(s, C(s,0,1,0)));
            if (!p.second) ++p.first->second.s;
            p=m.insert(make_pair(b, C(b,0,0,1)));
            if (!p.second) ++p.first->second.b;
        }
        vector<C> t(m.size());
        int idx=0;
        for (auto i=m.begin(); i!=m.end(); ++i)
            t[idx++]=i->second;
        sort(t.begin(), t.end());
        vector<string> r(t.size());
        for (int i=0; i<t.size(); ++i) {
            ostringstream oss;
            oss<<t[i].name<<' '<<t[i].g<<' '<<t[i].s<<' '<<t[i].b;
            r[i]=oss.str();
        }
        return r; 
    }
};