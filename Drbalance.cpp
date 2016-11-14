#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
using namespace std;

vector<string> intree;
struct Drbalance {
    int lesscng(string s, int k) {
        list<string> q;
        q.push_back(s);
        intree.push_back(s);
        string node;
        while (!q.empty()) {
            node=q.front(); q.pop_front();
            int count=0;
            for (int i=node.size()-1; i>=0; --i) {
                int lcount=0, rcount=0;
                for (int j=0; j<=i; ++j) {
                    if (node[j]=='-') ++lcount;
                    else ++rcount;
                }
                if (lcount>rcount) ++count;
            }
            if (count==k) break;
            for (int i=0; i<node.size(); ++i) {
                string t(node);
                if (t[i]=='-') t[i]='+';
                else t[i]='-';
                for (int j=0; j<intree.size(); ++j) {
                    if (intree[j]==t)
                        continue;
                }
                q.push_back(t);
                intree.push_back(t);
            }
        }
        int count=0;
        for (int i=0; i<s.size(); ++i)
            if (s[i]!=node[i])
                ++count;
        return count;
   }
};
