#include <bits/stdc++.h>
using namespace std;

struct SumFullSet {
    string isSumFullSet(vector<int> elements) {
        if (!(elements.size())) return "closed";
        for (int i=0; i<elements.size()-1; ++i)
            for (int j=i+1; j<elements.size(); ++j)
                if (find(elements.begin(), elements.end(), elements[i]+elements[j])==elements.end())
                    return "not closed";
        return "closed";
    }
};