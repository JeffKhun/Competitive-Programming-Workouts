#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <list>
using namespace std;

double d[50][50];
bool intree[50][50];

struct N {
    int k;
    double t;
    N(int k, double t) : k(k), t(t) {}
};
struct ShortestPathWithMagic {
    double getTime(vector<string> dist, int k) {
        for (int i=0; i<dist.size(); ++i)
            for (int j=0; j<dist[i].length(); ++j)
                d[i][j]=dist[i][j]-'0';
        double res=DBL_MAX-1;
        list<pair<int, N>> q;
        N n(k, 0.0);
        q.push_back(make_pair(0, n));
        intree[0][0]=1;
        while (!q.empty()) {
            pair<int, N> v=q.front();
            q.pop_front();
            if (v.first==1) {
                res=min(res, v.second.t);
                continue;
            }
            for (int i=0; i<dist.size(); ++i) {
                if (i==v.first) continue;
                if (intree[v.first][i]||intree[i][v.first]) continue;
                if (v.second.k) {
                    N n1(v.second.k-1, v.second.t+(d[v.first][i]/2.0));
                    q.push_back(make_pair(i, n1));
                }
                N n2(v.second.k, v.second.t+d[v.first][i]);
                q.push_back(make_pair(i, n2));
                intree[v.first][i]=intree[i][v.first]=1;
            }
        }
        return res;
    }
};
