#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
void print(vector<int>& v) {
	for (int i=0; i<v.size(); ++i)
		cout<<v[i]<<'\n';
	cout<<endl;
}
int n, n2, m;
vector<int> v;
int f(int S) {
	if (!S) return 0;
	if (!(S-1))
		for (int i=0; i<n; ++i)
			if (S&1<<i) {
				int c=0;
				for (int k=0; k<m; ++k)
					if (v[i]&1<<k)
						++c;
				cout<<"ret: "<<c*c<<endl;
				return c*c;
			} 
	int res=INT_MAX;
	for (int i=0; i<n; ++i)
		if (S&1<<i) {
			int S2=S&~(1<<i);
			int mask=0;
			for (int j=0; j<n; ++j)
				if (S2&1<<j)
					mask|=v[j];
			int t=v[i]&~mask;
			int c=0;
			for (int j=0; j<m; ++j)
				if (t&1<<j)
					++c;
			res=min(res, c*c+f(S2));
		}
	return res;
}
struct OrderOfOperationsDiv2 {
	int minTime(vector<string> s) {
		n=s.size(), n2=1<<n;
		m=s[0].length();
		for (int i=0; i<n; ++i) {
			string ss=s[i];
			int mask=0;
			for (int j=0, k=m-1; j<m; ++j, --k)
				if (ss[j]=='1')
					mask+=(1<<k);
			v.push_back(mask);
		}
		return f(n2-1);
	}
};
