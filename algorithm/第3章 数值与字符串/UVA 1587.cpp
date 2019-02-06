#include<bits/stdc++.h>
using namespace std;

#define _for(i,a,b) for(int i = (a); i < (b); i++)

struct node{
   int a[2];
   bool operator < (const node &rhm) const{
        return ( a[0] < rhm.a[0]) || ( a[0] == rhm.a[0] && a[1] < rhm.a[1] );
   }
}S[6];

int main(){
   while(1){
      bool ok = true;
      _for(i,0,6){
         if(scanf("%d%d", &S[i].a[0], &S[i].a[1]) != 2) return 0;
         sort(S[i].a, S[i].a+2);
      }
      sort(S, S+6);
      for(int i = 0; i < 6; i = i+2){
         if(S[i].a[0] != S[i+1].a[0] || S[i].a[1] != S[i+1].a[1]){
            ok = false; break;
         }
      }
      if(!ok || S[0].a[0] != S[2].a[0] || S[0].a[1] != S[4].a[0] || S[2].a[1] != S[4].a[1]) ok = false;
      if( ok ) printf("POSSIBLE\n");
      else printf("IMPOSSIBLE\n");
   }
   return 0;
}

/*


Sample Input

1345 2584
2584 683
2584 1345
683 1345
683 1345
2584 683
1234 4567
1234 4567
4567 4321
4322 4567
4321 1234
4321 1234



Sample Output

POSSIBLE
IMPOSSIBLE

*/