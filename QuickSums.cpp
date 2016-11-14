#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int res;
int f(string numbers, int sum) {
    istringstream iss(numbers);
    ll i;
    iss>>i;
    if (i<sum) return 10;
    if (i==sum) return 0;
    int r=10;
    for (int j=1; j<numbers.length(); ++j) {
        istringstream iss(numbers.substr(0, j));
        string s2=numbers.substr(j);
        iss>>i;
        if (i>sum) break;
        r=min(r, 1+f(s2, sum-i));
    }
    return r;
}
struct QuickSums {
    int minSums(string numbers, int sum) {
        int r=f(numbers, sum);
        if (r<0 || r>=1000) return -1;
        return r;
    }
};