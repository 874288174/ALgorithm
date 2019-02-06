#include<bits/stdc++.h>
using namespace std;

int main(){
   int n, m;
   scanf("%d",&n);
   while(n--){
      int a[10] = {0};
      scanf("%d",&m);
      while(m--) {
         int t = m+1;
         while(t){
            a[t % 10]++;
            t /= 10;
         }
      }
      for(int i = 0; i < 10; i++)
         printf("%d%c",a[i],(i == 9 ? '\n' : ' '));
   }
   return 0;
}

/*
Sample Input

2
3
13

Sample Output

0 1 1 1 0 0 0 0 0 0
1 6 2 2 1 1 1 1 1 1

*/