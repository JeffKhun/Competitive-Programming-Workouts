#include <bits/stdc++.h>
using namespace std;

//BOTTOM-UP
string f[26][26];
struct ShortPalindromes {
    string shortest(string base) {
        for (int i=0; i<base.length(); ++i) f[i][i]=base[i];
        for (int t=1; t<base.length(); ++t)
            for (int i=0, j=t; j<base.length(); ++i, ++j) {
                if (base[i]==base[j]) f[i][j]=base[i]+f[i+1][j-1]+base[i];
                else {
                    string s1=base[i]+f[i+1][j]+base[i];
                    string s2=base[j]+f[i][j-1]+base[j];
                    if (s1.length()!=s2.length()) f[i][j]=(s1.length()<s2.length())?s1:s2;
                    else f[i][j]=min(s1, s2);
                }
            }
        return f[0][base.length()-1];
   }
};

//TOP-DOWN
string base;
int n;
string dp[26][26];
string f(int i, int j) {
    if (i==j) {
        dp[i][j]=string(1, base[i]);
        return dp[i][j];
    }
    if (i>j) return "";
    if (base[i]==base[j]) dp[i][j]=base[i]+f(i+1, j-1)+base[j];
    else {
        string s1=base[i]+f(i+1, j)+base[i];
        string s2=base[j]+f(i, j-1)+base[j];
        if (s1.length()!=s2.length()) dp[i][j]=(s1.length()<s2.length()?s1:s2);
        else dp[i][j]=(s1<s2?s1:s2);
    }
    return dp[i][j];
}
struct ShortPalindromes {
    string shortest(string base) {
        ::base=base;
        n=base.length();
        return f(0, n-1);
    }
};