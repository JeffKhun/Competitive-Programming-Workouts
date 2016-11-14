#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int f[1<<19];
struct SeparateConnections {
    int howMany(vector<string> mat) {
        int n=mat.size(), n2=1<<n;
        for (int i=0; i<n2; ++i)
            for (int j=0; j<n; ++j)
                if (i&1<<j)
                    for (int k=j+1; k<n; ++k)
                        if (i&1<<k)
                            if (mat[j][k]=='Y')
                                f[i]=max(f[i], 2+f[i&~(1<<j)&~(1<<k)]);
        return f[n2-1];
    }
};
