#include <bits/stdc++.h>
using namespace std;

int f[101][101];
struct YetAnotherCardGame {
    int maxCards(vector<int> petr, vector<int> snuke) {
        int ng=2*petr.size();
        for (int i=1; i<=ng; ++i)
            for (int j=0; j<=100; ++j) {
                vector<int> *v;
                if (i%2) v=&petr;
                else v=&snuke;
                for (int k=0; k<v->size(); ++k)
                    if (v->at(k)>j)
                        f[i+1][v->at(k)]=max(f[i+1][v->at(k)], 1+f[i][j]);
                f[i+1][j]=max(f[i+1][j], f[i][j]);
            }
        return *max_element(f[ng+1]+1, f[ng+1]+101);
    }
};