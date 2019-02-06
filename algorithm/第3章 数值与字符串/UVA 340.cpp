#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int n, a, b, guess;
int s[maxn];

int main(){
   int kase = 0;
   while(scanf("%d",&n) == 1 && n){
      int s1[10] = {0};
      printf("Game %d:\n",++kase);
      for(int i = 0; i < n; i++) {
          scanf("%d",&s[i]);
          s1[ s[i] ]++;
      }
      while(1){
         int s2[10] = {0}, s3[10] = {0};
         a = b = 0;
         for(int i = 0; i < n; i++){
             scanf("%d",&guess);
             if(guess == s[i]) {a++; s3[guess]++;}
             s2[guess]++;
         }
         if(guess == 0) break;
         for(int i = 1; i < 10; i++)
            if(s1[i] > 0)
               b += min(s1[i] - s3[i], s2[i] - s3[i]);

         printf("    (%d,%d)\n",a ,b);
      }
   }
   return 0;
}