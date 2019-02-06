#include<bits/stdc++.h>
using namespace std;

int main(){
   int n;
   scanf("%d",&n);
   for(int cnt = 0; cnt < n; cnt++){
      string s;
      cin >> s;
      int len = s.length(), T = 0;
      while( ++T ){
         if(len % T != 0) continue;
         if(T > len/2) {
             printf("%d\n",len);
             break;
         }
         bool ok = true;
         for(int i = 0; i < T; i++){
            int k = i;
            while(k < len){
               if(s[k] != s[i] ){
                 ok = false; 
                 break;
               }
               k += T;
            }
            if(!ok) break;
         }
         if(ok) {
            printf("%d\n",T);
            break;
         }
      }
      if(cnt != n - 1) putchar('\n');
   }
   return 0;
}

/*
Sample Input

1
HoHoHo

Sample Output

2

*/