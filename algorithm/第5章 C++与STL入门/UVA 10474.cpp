#include<bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 10;

int main(){
   int kase = 0, a, N, Q, v[maxn];
   while(scanf("%d%d",&N,&Q) == 2 && N && Q){
       for(int i = 0; i < N; i++) scanf("%d",&v[i]);
       sort(v, v+N);
       printf("CASE# %d:\n",++kase);
       while(Q--){
          scanf("%d",&a);
          int p = lower_bound(v,v+N,a) - v;
          if(v[p] == a) printf("%d found at %d\n",a,p+1);
          else printf("%d not found\n",a);
       }
   }
   return 0;
}


/*
Sample Input

4 1
2
3
5
1
5 5
2
1
3
3
3
1 2
3
0 0

Sample Output

CASE# 1:
5 found at 4
CASE# 2:
2 not found
3 found at 3

*/