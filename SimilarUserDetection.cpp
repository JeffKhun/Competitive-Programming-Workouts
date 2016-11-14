#include <bits/stdc++.h>
using namespace std;

struct SimilarUserDetection {
    bool same(string &s1, string &s2) {
        if (s1.length()!=s2.length()) return false;
        for (int i=0; i<s1.length(); ++i) {
            if ((s1[i]=='O' || s1[i]=='0') && (s2[i]=='O' || s2[i]=='0')) continue;
            if ((s1[i]=='1' || s1[i]=='l' || s1[i]=='I') && (s2[i]=='1' || s2[i]=='l' || s2[i]=='I')) continue;
            if (s1[i]!=s2[i]) return false;
        }
        return true;
    }
    string haveSimilar(vector<string> handles) {
       for (int i=0; i<handles.size(); ++i)
           for (int j=i+1; j<handles.size(); ++j)
               if (same(handles[i], handles[j]))
                   return "Similar handles found";
       return "Similar handles not found";
    }
};