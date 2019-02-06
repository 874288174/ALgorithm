#include<bits/stdc++.h>
using namespace std;

#define _for(i,a,b) for(int i = (a); i < (b); i++)
const int maxn = 10 + 2;
int n, m;
int kase = 0;
bool board[maxn][maxn][2];
int S[maxn];
int hmax[maxn][maxn], vmax[maxn][maxn];

bool solve(){
   bool ok = false;
   for(int i = n; i > 0; i--)
     for(int j = n; j > 0; j--){
        if( board[i][j][0] ) hmax[i][j] = hmax[i][j+1] + 1;
        else hmax[i][j] = 0;
        if( board[i][j][1] ) vmax[i][j] = vmax[i+1][j] + 1;
        else vmax[i][j] = 0;
     }
   _for(i,1,n)
      _for(j,1,n){
         int maxsize = min(hmax[i][j], vmax[i][j]);
         _for(k,1,maxsize+1){
            int Right = i + k, Down = j + k;
            if(hmax[Right][j] >= k && vmax[i][Down] >= k){
                S[k]++;
                ok = true;
            }
         }
      }
   if(ok) return true;
   else return false;
}

void Print(){
    _for(i,1,n) if(S[i])
      printf("%d square (s) of size %d\n",S[i],i);
}

int main(){
   while(scanf("%d\n",&n) == 1){
       int a, b;
       char c;
       memset(S, 0, sizeof(S));
       memset(board, false, sizeof(board));
       memset(hmax, 0, sizeof(hmax));
       memset(vmax, 0, sizeof(vmax));
       scanf("%d\n",&m);
       _for(i,0,m){
          scanf("%c %d %d\n",&c, &a, &b);
          if(c == 'H') board[a][b][0] = true;
          else board[b][a][1] = true;
       }
       if(kase) printf("\n**********************************\n\n");
       printf("Problem #%d\n\n", ++kase);
       if( solve() ) Print();
       else printf("No completed squares can be found.\n");
   }
   return 0;
}


/*
Sample Input

4
16
H 1 1
H 1 3
H 2 1
H 2 2
H 2 3
H 3 2
H 4 2
H 4 3
V 1 1
V 2 1
V 2 2
V 2 3
V 3 2
V 4 1
V 4 2
V 4 3
2
3
H 1 1
H 2 1
V 2 1

Sample Output

Problem #1

2 square (s) of size 1
1 square (s) of size 2

**********************************

Problem #2

No completed squares can be found.

*/