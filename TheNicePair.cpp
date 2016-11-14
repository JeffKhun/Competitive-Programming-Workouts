#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct TheNicePair {
    int solve(vector<int> A) {
        int N=A.size()-1;
        for (int t=N; t>=0; --t)
            for (int i=0, j=t; j<=N; ++i, ++j) {
                int h=ceil((j-i+1)/2.0);
                int me=*max_element(A.begin()+i, A.begin()+j+1);
                for (int k=2; k<=me; ++k) {
                    int count=0;
                    for (int r=i; r<=j; ++r)
                        if (A[r]%k==0)
                            ++count;
                    if (count>=h)
                        return (j-i);
                }
            }   
        return -1;
   }
};