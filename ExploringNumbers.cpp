#include <iostream>
using namespace std;

bool isprime(int n) {
    if (n<=1) return 0;
    for (int i=2; i*i<=n; ++i)
        if (!(n%i)) return 0;
    return 1;
}
struct ExploringNumbers {
    int numberOfSteps(int n) {
        int t=n, c=1;
        while (!isprime(t)) {
            if (c++==n) return -1;
            int tt=0;
            while (t>0) {
                tt+=(t%10)*(t%10);
                t/=10;
            }
            t=tt;
        }
        return c;
    }
};