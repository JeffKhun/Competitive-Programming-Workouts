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

bool f[400][600];
pair<int, int> g() {
    for (int i=0; i<400; ++i)
        for (int j=0; j<600; ++j)
            if (!f[i][j]) return make_pair(i, j);
    return make_pair(-1, -1);
}
struct grafixMask {
    vector<int> sortedAreas(vector<string> rect) {
        for (int i=0; i<rect.size(); ++i) {
            istringstream iss(rect[i]);
            int r1, c1, r2, c2;
            iss>>r1>>c1>>r2>>c2;
            for (int j=r1; j<=r2; ++j)
                for (int k=c1; k<=c2; ++k)
                    f[j][k]=1;
        }
        pair<int, int> start=g();
        vector<int> areas;
        while (start.first!=-1 || start.second!=-1) {
            vector<pair<int, int>> st;
            st.push_back(start);
            int area=0;
            while (!st.empty()) {
                pair<int, int> v=st.back(); st.pop_back();
                int x=v.first, y=v.second;
                if (f[x][y]) continue;
                ++area;
                f[x][y]=1;
                if (x-1>=0 && !f[x-1][y]) st.push_back(make_pair(x-1, y));
                if (y-1>=0 && !f[x][y-1]) st.push_back(make_pair(x, y-1));
                if (y+1<600 && !f[x][y+1]) st.push_back(make_pair(x, y+1));
                if (x+1<400 && !f[x+1][y]) st.push_back(make_pair(x+1, y));
            }
            areas.push_back(area);
            start=g();
        }
        sort(areas.begin(), areas.end());
        return areas; 
    }
};