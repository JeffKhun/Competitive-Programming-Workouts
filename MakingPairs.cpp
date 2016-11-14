#include <bits/stdc++.h>
using namespace std;

struct MakingPairs {
    int get(vector<int> card) {
        int r=0;
        for (int i=0; i<card.size(); ++i)
            r+=(card[i]/2);
        return r;
    }
};