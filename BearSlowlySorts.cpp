#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

struct BearSlowlySorts {
    int minMoves(vector<int> w) {
        vector<int> sorted(w);
        sort(sorted.begin(), sorted.end());
        list<pair<vector<int>, int>> q;
        q.push_back(make_pair(w, 0));
        while (!q.empty()) {
            pair<vector<int>, int> v=q.front(); q.pop_front();
            if (v.first==sorted) return v.second;
            vector<int> v1(v.first), v2(v.first);
            sort(v1.begin(), v1.end()-1);
            sort(v2.begin()+1, v2.end());
            q.push_back(make_pair(v1, v.second+1));
            q.push_back(make_pair(v2, v.second+1));
        }
        return 0;
    }
};
