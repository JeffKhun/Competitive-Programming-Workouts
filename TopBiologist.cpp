#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
using namespace std;

struct TopBiologist {
    string findShortestNewSequence(string sequence) {
        list<string> q;
        q.push_back("A");
        q.push_back("C");
        q.push_back("G");
        q.push_back("T");
        while (!q.empty()) {
            string v=q.front();
            q.pop_front();
            if (sequence.find(v)==string::npos) return v;
            q.push_back(v+"A");
            q.push_back(v+"C");
            q.push_back(v+"G");
            q.push_back(v+"T");
        }
        return "";
    }
};
