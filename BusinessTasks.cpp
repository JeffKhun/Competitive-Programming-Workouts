#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct BusinessTasks {
   string getTask(vector<string> list, int n) {
      int i=0;
      while (list.size()>1) {
         i=(i+n-1)%list.size();
         list.erase(list.begin()+i);
      }
      return list[0];
   }
};
