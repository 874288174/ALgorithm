#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000+5;
int n ,m;
int a[MAXN][4];
char s[MAXN];
char w[5] = "ACGT";

int main(){
   int T;
   scanf("%d",&T);
   while(T--){
      memset(a,0,sizeof(a));
      scanf("%d%d", &m, &n);
      while(m--){
         scanf("%s",s);
         int len = strlen(s);
         for(int i = 0; i < len; i++){
            switch(s[i]){
               case 'A': { a[i][0]++; break; }
               case 'C': { a[i][1]++; break; }
               case 'G': { a[i][2]++; break; }
               case 'T': { a[i][3]++; break; }
            }
         }
      }
      int sum = 0;
      for(int i = 0; i < n; i++){
         int maxn = max( max(a[i][0],a[i][1]),max(a[i][2],a[i][3]) );
         sum += a[i][0] + a[i][1] + a[i][2] + a[i][3] - maxn;
         for(int k = 0; k < 4; k++) if(a[i][k] == maxn) {
            printf("%c",w[k]);
            break;
         }
      }
      printf("\n%d\n",sum);
   }
   return 0;
}