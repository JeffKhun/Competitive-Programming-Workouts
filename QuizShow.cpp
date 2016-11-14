#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class QuizShow {
public:
   int wager(vector<int> scores, int wager1, int wager2) {
      int bestwager=0, bestres=0;
      for (int mywager=0; mywager<=scores[0]; ++mywager) {
         int res=0;
         for (int i=-1; i<2; i+=2)
            for (int j=-1; j<2; j+=2)
               for (int k=-1; k<2; k+=2) {
                  int myscore=scores[0]+i*mywager;
                  int opp1score=scores[1]+j*wager1;
                  int opp2score=scores[2]+k*wager2;
                  if (myscore>opp1score && myscore>opp2score) ++res;
               }
               if (bestres<res) {
                  bestres=res;
                  bestwager=mywager;
               }
      }
      return bestwager;
   }
};
