You've been put in charge of creating the problems for a certain high-profile programming contest series.
The series will consist of one or more contests of exactly 4 problems each. Every problem has a difficulty rating (an integer between 1 and 100, inclusive), and the ratings of the 4 problems in each contest must be strictly increasing, but with a difference of no more than 10 between consecutive problems. In other words, if the problems in a contest have difficulties a, b, c, and d (in order), then the inequalities a < b < c < d, b - a≤ 10, c - b ≤ 10, d - c ≤ 10 must all hold.
You've been given an ordered list of N problems to use. Being an experienced problemsetter, you may also write some new problems to insert at any positions in the list, each with an integer difficulty between 1 and 100, inclusive. The final list of problems must still include the original Nproblems in their original order, though (with your new problems optionally mixed in).
Once the problem list is finalized, the first 4 problems (in order) will form a contest, the next 4 problems will form another contest, and so on. Note that the number of problems in the list must be divisible by 4, and that each of the contests formed must feature a valid ordered set of 4 problems. What's the minimum number of additional problems you must write in order to create a set of valid contests?
Input
Input begins with an integer T, the number of contest series you need to create. For each series, there is first a line containing the integer N, then a line containing N space-separated integers, the ith of which is Di, the difficulty rating of the ith existing problem.
Output
For the ith series, print a line containing "Case #i: " followed by the minimum number of additional problems you'll need to write.
Constraints
1 ≤ T ≤ 50 
1 ≤ N ≤ 100,000 
1 ≤ Di ≤ 100 
Explanation of Sample
In the first series, the four problems given are already a valid contest, so no new problems need to be written. In the second series, the four existing problems most certainly do not form a valid contest, due to the gap between the third and fourth ones - one possible way to salvage the situation is to add three new problems with difficulties 30, 29, and 30 after the third problem, as well as a problem with difficulty 42 at the end, creating two valid contests: [15, 20, 25, 30] and [29, 30, 40, 42].
5
4
10 15 25 30
4
15 20 25 40
3
3 3 3
8
60 90 61 62 63 91 92 93
11
5 14 30 32 39 46 47 47 30 58 47

Case #1: 0
Case #2: 4
Case #3: 9
Case #4: 4
Case #5: 9

---------------

Matt Laundro is about to engage in his favourite activity — doing laundry! He's brought L indistinguishable loads of laundry to his local laundromat, which has N washing machines and M dryers. The ith washing machine takes Wi minutes to wash one load of laundry, and each dryer takes D minutes to dry a load of laundry. At any point in time, each machine may only be processing at most one load of laundry.
As one might expect, Matt wants to wash and then dry each of his L loads of laundry. Each load of laundry will go through the following steps in order:
1.	A non-negative amount of time after Matt arrives at the laundromat, Matt places the load in an unoccupied washing machine i
2.	Wi minutes later, he removes the load from the washing machine, placing it in a temporary holding basket (which has unlimited space)
3.	A non-negative amount of time later, he places the load in an unoccupied dryer
4.	D minutes later, he removes the load from the dryer
Matt can instantaneously add laundry to or remove laundry from a machine. Help Matt minimize the amount of time (in minutes after he arrives at the laundromat) after which he can be done drying all L loads of laundry!
Input
Input begins with an integer T, the number of times Matt goes to the laundromat. For each trip to the laundromat, there is first a line containing the space-separated integers L, N, M, and D in that order. After that is a line containing N space-separated integers, the ith of which is Wi.
Output
For the ith trip, print a line containing "Case #i: " followed by the minimum time it will take Matt to finish his laundry.
Constraints
1 ≤ T ≤ 50 
1 ≤ L ≤ 1,000,000 
1 ≤ N ≤ 100,000 
1 ≤ M ≤ 1,000,000,000 
1 ≤ D ≤ 1,000,000,000 
1 ≤ Wi ≤ 1,000,000,000 
Explanation of Sample
In the first case, Matt has just one load of laundry. He washes it for 1200 minutes, and dries it for 34 minutes. In the second case, Matt uses the 1-minute washer for both loads of laundry. The second load finishes at the 2-minute mark, so it finishes drying at the 12-minute mark.
5
1 1 1 34
1200
2 3 2 10
100 10 1
3 3 3 3
1 2 3
4 2 2 7
5 8
999 1 999 6
3
 
Case #1: 1234
Case #2: 12
Case #3: 5
Case #4: 22
Case #5: 3003


#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <list>
using namespace std;
int main() {
    int ntc;
    cin>>ntc;
    for (int tc=1; tc<=ntc; ++tc) {
        int L, N, M, D, k;
        cin>>L>>N>>M>>D;
        priority_queue<pair<int, int>> q;
        list<int> l;
        for (int i=0; i<N; ++i) {
            cin>>k;
            q.push(make_pair(-k, k));
        }
        while (L>0) {
            pair<int, int> v=q.top(); q.pop();
            int t=-v.first;
            --L;
            q.push(make_pair(-(t+v.second), v.second));
            if (l.size()<M)
                l.push_back(t+D);
            else {
                int t2=l.front(); l.pop_front();
                l.push_back(max(t2, t)+D);
            }
        }
        cout<<"Case #"<<tc<<": "<<l.back()<<'\n';
    }
    return 0;
}
