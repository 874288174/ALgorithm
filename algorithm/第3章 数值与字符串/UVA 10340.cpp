#include<bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
char s[maxn], t[maxn];

int main(){
   while(scanf("%s%s",s, t) == 2){
      int n = strlen(s), m = strlen(t);
      int i = 0, j = -1;
      for(; i < n; i++){
         while(j < m){
           j++ ;
           if(s[i] == t[j]) break;
         }
      }
      if(i == n && j < m) printf("Yes\n");
      else printf("No\n");
   }
   return 0;
}

/*


Sample Input

sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter


Sample Output

Yes
No
Yes
No

*/