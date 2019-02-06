#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
vector<int> v(maxn * maxn);

int main(){
   int T, N, a, kase = 0;
   string s;
   while( scanf("%d",&T) == 1 && T){
      queue< int > q[T], Q;
      printf("Scenario #%d\n", ++kase);
      for(int i = 0; i < T; i++){
         scanf("%d", &N);
         while(N--){
            scanf("%d",&a);
            v[a] = i;
         }
      }
      while(cin >> s && s != "STOP"){
         if(s == "ENQUEUE"){
            scanf("%d",&a);
            int team = v[a];
            if(q[team].empty()) Q.push(team);
            q[team].push(a);
         }
         else{
            int team = Q.front();
            cout << q[team].front() << endl;
            q[team].pop();
            if(q[team].empty()) Q.pop();
         }
      }
      putchar('\n');
   }
   return 0;
}


/*
Sample Input

2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
2
5 259001 259002 259003 259004 259005
6 260001 260002 260003 260004 260005 260006
ENQUEUE 259001
ENQUEUE 260001
ENQUEUE 259002
ENQUEUE 259003
ENQUEUE 259004
ENQUEUE 259005
DEQUEUE
DEQUEUE
ENQUEUE 260002
ENQUEUE 260003
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
0

Sample Output

Scenario #1
101
102
103
201
202
203

Scenario #2
259001
259002
259003
259004
259005
260001

*/
