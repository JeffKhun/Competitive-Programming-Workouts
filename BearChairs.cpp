#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

struct BearChairs {
    vector<int> findPositions(vector<int> atLeast, int d) {
        set<int> s;
        s.insert(atLeast[0]);
        for (int i=1; i<atLeast.size(); ++i) {
            for (auto j=s.begin(); j!=s.end(); ++j)
                if (abs(*j-atLeast[i])<d)
                        atLeast[i]=*j+d;
            s.insert(atLeast[i]);
        }
        return atLeast;
    }
};
