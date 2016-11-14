#include <bits/stdc++.h>
using namespace std;

struct NonDeterministicSubstring {
    long ways(string A, string B) {
       set<string> s;
       int n=B.length();
       for (int i=0; i<(A.length()-n+1); ++i)
           s.insert(A.substr(i, n));
       return s.size();
    }
};