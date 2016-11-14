#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
using namespace std;

int f[26][26][26][26];
bool intree[26][26][26][26];
bool blocked[26][26][26][26];
struct SmartWordToy {
    int minPresses(string start, string finish, vector<string> forbid) {
        for (int i=0; i<forbid.size(); ++i) {
            istringstream iss(forbid[i]);
            string s1, s2, s3, s4;
            iss>>s1>>s2>>s3>>s4;
            for (int a=0; a<s1.length(); ++a)
                for (int b=0; b<s2.length(); ++b)
                    for (int c=0; c<s3.length(); ++c)
                        for (int d=0; d<s4.length(); ++d)
                            blocked[s1[a]-'a'][s2[b]-'a'][s3[c]-'a'][s4[d]-'a']=true;
        }
        vector<int> vs(4), vf(4);
        for (int i=0; i<4; ++i) {
            vs[i]=start[i]-'a';
            vf[i]=finish[i]-'a';
        }
        if (blocked[vf[0]][vf[1]][vf[2]][vf[3]]) return -1;
        list<vector<int>> q;
        q.push_back(vs);
        intree[vs[0]][vs[1]][vs[2]][vs[3]]=true;
        while (!q.empty()) {
            vector<int> v=q.front(); q.pop_front();
            if (v==vf) return f[v[0]][v[1]][v[2]][v[3]];
            for (int i=0; i<4; ++i) {
                vector<int> fwd(v), bwd(v);
                fwd[i]=(fwd[i]+1)%26;
                if (!intree[fwd[0]][fwd[1]][fwd[2]][fwd[3]] && !blocked[fwd[0]][fwd[1]][fwd[2]][fwd[3]]) {
                    intree[fwd[0]][fwd[1]][fwd[2]][fwd[3]]=true;
                    f[fwd[0]][fwd[1]][fwd[2]][fwd[3]]=f[v[0]][v[1]][v[2]][v[3]]+1;
                    q.push_back(fwd);
                }
                bwd[i]=(bwd[i]+25)%26;
                if (!intree[bwd[0]][bwd[1]][bwd[2]][bwd[3]] && !blocked[bwd[0]][bwd[1]][bwd[2]][bwd[3]]) {
                    intree[bwd[0]][bwd[1]][bwd[2]][bwd[3]]=true;
                    f[bwd[0]][bwd[1]][bwd[2]][bwd[3]]=f[v[0]][v[1]][v[2]][v[3]]+1;
                    q.push_back(bwd);
                }
            }
        }
        return -1;
   }
};
