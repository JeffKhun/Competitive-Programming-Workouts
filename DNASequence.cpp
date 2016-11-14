#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

struct DNASequence {
    int longestDNASequence(string s) {
        int N=s.length();
        for (int t=N-1; t>=0; --t)
            for (int i=0, j=t; j<N; ++i, ++j) {
                bool ok=1;
                for (int k=i; k<=j; ++k)
                    if (s[k]!='A' && s[k]!='C' && s[k]!='G' && s[k]!='T') {
                        ok=0;
                        break;
                    }
                    if (ok) return (j-i+1);
            }
        return 0;
    }
};
