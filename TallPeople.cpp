#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <climits>
#include <sstream>
using namespace std;

int f[51][51];
struct TallPeople {
    vector<int> getPeople(vector<string> people) {
        int r=people.size(), c;
        for (int i=0; i<r; ++i) {
            istringstream iss(people[i]);
            c=0;
            while (iss>>f[i][c++]);
        }
        --c;
        vector<int> res(2);
        res[0]=INT_MIN;
        for (int i=0; i<r; ++i) {
            int target=INT_MAX;
            for (int j=0; j<c; ++j)
                target=min(target, f[i][j]);
            res[0]=max(res[0], target);
        }
        res[1]=INT_MAX;
        for (int j=0; j<c; ++j) {
            int target=INT_MIN;
            for (int i=0; i<r; ++i)
                target=max(target, f[i][j]);
            res[1]=min(res[1], target);
        }
        return res;
    }
};
