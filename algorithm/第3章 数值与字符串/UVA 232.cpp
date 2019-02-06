#include<bits/stdc++.h>
using namespace std;

const int maxn = 10 + 5;
int n, m;
char word[maxn][maxn];
int across[maxn][maxn], down[maxn][maxn];
int kase = 0;

void read_input(){
   memset(across, 0, sizeof(across));
   memset(down, 0, sizeof(down));
   memset(word, '*' ,sizeof(word));
   int flag, cnt = 1;
   for(int i = 0; i < n; i++) scanf("%s",word[i]);
   for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++){
          flag = 0;
          if( word[i][j] != '*' && ( !j || word[i][j-1] == '*' ) ) { across[i][j] = cnt; flag = 1; }
          if( word[i][j] != '*' && ( !i || word[i-1][j] == '*' ) ) { down[i][j] = cnt; flag = 1; }
          if(flag) t++;
      }
}

void Print(){
    if(kase) putchar('\n');
    printf("puzzle #%d:\n",++kase);
    printf("Across\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            if(across[i][j]){
                printf("%3d.",across[i][j]);
                while(j < m && word[i][j] != '*') printf("%c",word[i][j++]);
                putchar('\n');
            }
    }
    printf("Down\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            if( down[i][j] ){
                int ii = i;
                printf("%3d.",down[ii][j]);
                while(word[ii][j] != '*')  printf("%c", word[ii++][j]);
                putchar('\n');
            }
    }
}
int main(){
   while(scanf("%d",&n) == 1 && n && scanf("%d",&m) == 1){
      read_input();
      Print();
   }
   return 0;
}

/*
Sample Input

2 2
AT
*O
6 7
AIM*DEN
*ME*ONE
UPON*TO
SO*ERIN
*SA*OR*
IES*DEA
0

Sample Output

puzzle #1:
Across
  1.AT
  3.O
Down
  1.A
  2.TO

puzzle #2:
Across
  1.AIM
  4.DEN
  7.ME
  8.ONE
  9.UPON
 11.TO
 12.SO
 13.ERIN
 15.SA
 17.OR
 18.IES
 19.DEA
Down
  1.A
  2.IMPOSE
  3.MEO
  4.DO
  5.ENTIRE
  6.NEON
  9.US
 10.NE
 14.ROD
 16.AS
 18.I
 20.A

*/