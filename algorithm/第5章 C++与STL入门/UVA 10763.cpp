#include<bits/stdc++.h>
using namespace std;


int main() {
   int N, a, b;
   while( scanf("%d",&N) == 1 && N){
      map< pair<int,int>, int> my_map;
      for(int i = 0; i < N; i++){
         scanf("%d%d", &a, &b);
         if(a > b) my_map[make_pair(a,b)]++;
         else if(a < b) my_map[make_pair(b,a)]--;
      }
      bool ok = true;
      for(auto &i : my_map) if(i.second){
         ok = false;
         break;
      }
      if(ok) printf("YES\n");
      else printf("NO\n");
   }
   return 0;
}




/*
Sample Input

10
1 2
2 1
3 4
4 3
100 200
200 100
57 2
2 57
1 2
2 1
10
1 2
3 4
5 6
7 8
9 10
11 12
13 14
15 16
17 18
19 20
0

Sample Output

YES
NO

*/