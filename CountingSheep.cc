#include <bits/stdc++.h>
using namespace std;

int main() {
    int ntc;
    cin>>ntc;
    for (int tc=1; tc<=ntc; ++tc) {
        int n, mask=0, t, k=1;
        cin>>n;
        if (n==0) {
            cout<<"Case #"<<tc<<": INSOMNIA\n";
            continue;
        }
        while (mask!=((1<<10)-1)) {
            t=n*(k++);
            while (t>0) {
                mask|=1<<(t%10);
                t/=10;
            }
        }
        cout<<"Case #"<<tc<<": "<<(k-1)*n<<'\n';
    }
    return 0;
}
