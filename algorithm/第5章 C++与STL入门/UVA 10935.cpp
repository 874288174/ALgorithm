#include<bits/stdc++.h>
using namespace std;

int N;

int main() {
   while( scanf("%d",&N) == 1 && N){
      int flag = 0;
      printf("Discarded cards:");
      queue< int > q;
      for(int i = 1; i <= N; i++) q.push(i);
      while(q.size() >= 2){
         if(flag) printf(", %d",q.front());
         else printf(" %d",q.front());
         q.pop();
         q.push(q.front());
         q.pop();
         flag = 1;
      }
      printf("\nRemaining card: %d\n",q.front());
   }
   return 0;
}




/*
Sample Input

7
19
10
6
0

Sample Output

Discarded cards: 1, 3, 5, 7, 4, 2
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 4, 8, 12, 16, 2, 10, 18, 14
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 2, 6, 10, 8
Remaining card: 4
Discarded cards: 1, 3, 5, 2, 6
Remaining card: 4

*/