#include <bits/stdc++.h>
using namespace std;

string a, b;
int n, best, ansl, ansr;
void f(int idx, int s1, int s2) {
    if (idx==n) {
        int t=abs(s1-s2);
        if (t<best) {
            best=t;
            ansl=s1;
            ansr=s2;
        } else if (t==best) {
            if (s1<ansl) {
                ansl=s1;
                ansr=s2;
            } else if (s2<ansr) {
                ansl=s1;
                ansr=s2;
            }
        }
        return;
    }
    s1*=10; s2*=10;
    if (s1==s2) {
        if (a[idx]!='?' && b[idx]!='?') {
            f(idx+1, s1+(a[idx]-'0'), s2+(b[idx]-'0'));
        }
        else if (a[idx]=='?' && b[idx]=='?') {
            f(idx+1, s1+0, s2+0);
            f(idx+1, s1+0, s2+1);
            f(idx+1, s1+1, s2+0);
        } else if (a[idx]=='?' && b[idx]!='?') {
            int t=b[idx]-'0';
            s2+=t;
            int l=max(t-1, 0);
			int h=min(t+1, 9);
			for (int z=l; z<=h; z++)
				f(idx+1, s1+z, s2);
        } else if (a[idx]!='?' && b[idx]=='?') {
            int t=a[idx]-'0';
            s1+=t;
            int l=max(t-1, 0);
			int h=min(t+1, 9);
			for (int z=l; z<=h; z++)
		        f(idx+1, s1, s2+z);
        }
    } else if (s1<s2) {
        if (a[idx]=='?' && b[idx]=='?') {
            int t=s2-s1;
            if (t>=9) f(idx+1, s1+9, s2+0);
            else f(idx+1, s1+t, s2+0);
        } else if (a[idx]!='?' && b[idx]!='?') {
            f(idx+1, s1+(a[idx]-'0'), s2+(b[idx]-'0'));
        } else if (a[idx]!='?' && b[idx]=='?') {
           f(idx+1, s1+(a[idx]-'0'), s2+0);
        } else if (a[idx]=='?' && b[idx]!='?') {
            f(idx+1, s1+9, s2+(b[idx]-'0'));
        }
    } else {
        if (a[idx]=='?' && b[idx]=='?') {
            int t=s1-s2;
            if (t>=9) f(idx+1, s1+0, s2+9);
            else f(idx+1, s1+0, s2+t);
        } else if (a[idx]!='?' && b[idx]!='?') {
            f(idx+1, s1+(a[idx]-'0'), s2+(b[idx]-'0'));
        } else if (a[idx]!='?' && b[idx]=='?') {
            f(idx+1, s1+(a[idx]-'0'), s2+9);
        } else if (a[idx]=='?' && b[idx]!='?') {
            f(idx+1, s1+0, s2+(b[idx]-'0'));
        }
    }
    return;
}
int main() {
    int ntc=1;
    cin>>ntc;
    for (int tc=1; tc<=ntc; ++tc) {
        cin>>a>>b;
        n=a.length();
        best=INT_MAX;
        f(0, 0, 0);
        ostringstream oss1, oss2;
        oss1<<ansl; oss2<<ansr;
        string s1, s2;
        s1=oss1.str(); s2=oss2.str();
        while (s1.length()!=n) s1='0'+s1;
        while (s2.length()!=n) s2='0'+s2;
        cout<<"Case #"<<tc<<": "<<s1<<' '<<s2<<'\n';
    }
    return 0;
}


/////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

string a, b;
int n, best, ansl, ansr;
void f(int idx, int s1, int s2) {
    if (idx==n) {
        int t=abs(s1-s2);
        if (t<best) {
            best=t;
            ansl=s1;
            ansr=s2;
        } else if (t==best) {
            if (s1<ansl) {
                ansl=s1;
                ansr=s2;
            } else if (s2<ansr) {
                ansl=s1;
                ansr=s2;
            }
        }
        return;
    }
    s1*=10; s2*=10;
    if (a[idx]!='?' && b[idx]!='?') {
        f(idx+1, s1+(a[idx]-'0'), s2+(b[idx]-'0'));
    }
    else if (a[idx]=='?' && b[idx]=='?') {
        for (int c1=0; c1<=9; ++c1)
            for (int c2=0; c2<=9; ++c2)
                f(idx+1, s1+c1, s2+c2);
    } else if (a[idx]=='?' && b[idx]!='?') {
        s2+=(b[idx]-'0');
        for (int c1=0; c1<=9; ++c1)
            f(idx+1, s1+c1, s2);
    } else if (a[idx]!='?' && b[idx]=='?') {
        s1+=(a[idx]-'0');
        for (int c2=0; c2<=9; ++c2)
            f(idx+1, s1, s2+c2);
    }
    return;
}
int main() {
    int ntc=1;
    cin>>ntc;
    for (int tc=1; tc<=ntc; ++tc) {
        cin>>a>>b;
        n=a.length();
        best=INT_MAX;
        f(0, 0, 0);
        ostringstream oss1, oss2;
        oss1<<ansl; oss2<<ansr;
        string s1, s2;
        s1=oss1.str(); s2=oss2.str();
        while (s1.length()!=n) s1='0'+s1;
        while (s2.length()!=n) s2='0'+s2;
        cout<<"Case #"<<tc<<": "<<s1<<' '<<s2<<'\n';
    }
    return 0;
}

// string version

#include <cmath>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <functional>
using namespace std;

string a, b;
int n, ans=INT_MAX;
string ansl1, ansl2;
vector<pair<string, string>> cache;
void f(int l, string s1, string s2) {
    if (find(cache.begin(), cache.end(), make_pair(s1, s2))!=cache.end()) return;// cache[make_pair(s1, s2)];
    if (l==n) {
        int l1, l2;
        istringstream iss1(s1); iss1>>l1;
        istringstream iss2(s2); iss2>>l2;
        if (abs(l1-l2)<ans) {
            //cout<<"==>"<<ans<<' '<<s1<<' '<<s2<<endl;
            ans=abs(l1-l2);
            ansl1=s1; ansl2=s2;
            cache.push_back(make_pair(ansl1, ansl2));
        }
        else if (abs(l1-l2)==ans) {
            //cout<<"==>"<<ans<<' '<<s1<<' '<<s2<<endl;
            istringstream iss1(ansl1), iss2(ansl2);
            int tansl1, tansl2;
            iss1>>tansl1; iss2>>tansl2;
            if (l1<tansl1) {
                ansl1=s1;
                ansl2=s2;
                cache.push_back(make_pair(ansl1, ansl2));
                return;
            }
            if (l1==tansl1) {
                if (l2<tansl2) {
                    ansl2=s2;
                    ansl1=s1;
                    cache.push_back(make_pair(s1,s2));
                }
            }
        }
        return;
    }
    if (a[l]!='?' && b[l]!='?') {
        string s11(s1);
        string s22(s2);
        s11+=a[l];
        s22+=b[l];
        f(l+1, s11, s22);
        return;
    }
    if (a[l]=='?' && b[l]=='?') {
        for (char ch1='0'; ch1<='9'; ++ch1) {
            for (char ch2='0'; ch2<='9'; ++ch2) {
                string s11(s1);
                string s22(s2);
                s11+=ch1;
                s22+=ch2;
                f(l+1, s11, s22);
            }
        }
        return;
    }
    if (a[l]=='?' && b[l]!='?') {
        for (char ch='0'; ch<='9'; ++ch) {
            string s11(s1);
            string s22(s2);
            s11+=ch;
            s22+=b[l];
            f(l+1, s11, s22);
        }
        return;
    }
    if (a[l]!='?' && b[l]=='?') {
        for (char ch='0'; ch<='9'; ++ch) {
            string s11(s1);
            string s22(s2);
            s11+=a[l];
            s22+=ch;
            f(l+1, s11, s22);
        }
        return;
    }
}
int main() {
    int ntc=1;
    cin>>ntc;
    for (int tc=1; tc<=ntc; ++tc) {
        cin>>a>>b;
        //a="?5"; b="?0";
        n=a.length();
        ans=INT_MAX;
        ansl1=""; ansl2="";
        cache.clear();
        f(0, "", "");
        cout<<"Case #"<<tc<<": "<<ansl1<<' '<<ansl2<<'\n';//<<ans<<'\n';
        //in.get();
    }
}

