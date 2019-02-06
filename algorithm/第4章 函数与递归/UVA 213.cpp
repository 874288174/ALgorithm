#include<bits/stdc++.h>
using namespace std;

char buf[8][1<<8];
int cnt, k;
char c;

bool read_input(){
   for(int i = 1;; i++){
      for(int j = 0; j < (1<<i) - 1; j++){
          if( (c = getchar()) == EOF) return false;
          if(c == '\n') return true;
          buf[i][j] = c;
      }
   }
}

int read(int t){
   int sum = 0;
   while(t--){
      while( (c = getchar()) == '\n') ;
      sum = sum * 2 + (c - '0');
   }
   return sum;
}

int main(){
    while(read_input()){
       while(cnt = read(3)){
          while( (k = read(cnt) ) != ((1 << cnt) - 1)){
              printf("%c",buf[cnt][k]);
          }
       }
       putchar('\n');
       getchar();
    }
    return 0;
}



/*
Sample Input

TNM AEIOU
0010101100011
1010001001110110011
11000
$#**\
0100000101101100011100101000

Sample Output

TAN ME
##*\$

*/