#include<bits/stdc++.h>
using namespace std;

#define _for(i,a,b) for(int i = (a); i < (b); i++)
int n;
const int dx[] = {0,1,1,1,-1,-1,-1,0};
const int dy[] = {1,0,1,-1,1,-1,0,-1};
const int maxn = 8 + 2;
char board[maxn][maxn];
char Next;

bool inside(int x, int y){
   if(x < 0 || y < 0 || x > 7 || y > 7) return false;
   else return true;
}

void read_input(){
   _for(i,0,8)
      scanf("%s\n", board[i]);
    scanf("%c", &Next);
}

bool legal(int x, int y, int Move){ // MOve = 0 表示判断可不可以下这里 Move = 1 表示下这里
   bool ok = false;
   for(int dic = 0; dic < 8; dic++){
       int xx = x + dx[dic], yy = y + dy[dic];
       if(inside(xx,yy) && board[xx][yy] != Next && board[xx][yy] != '-'){
          while(1){
            if(inside(xx,yy) && board[xx][yy] == Next){
               ok = true;
               if(Move) {
                  while(xx != x || yy != y){
                     board[xx][yy] = Next;
                     xx += dx[7-dic], yy += dy[7-dic];
                  }
                  board[xx][yy] = Next;
               }
               break;
            }
            else if(inside(xx,yy) && board[xx][yy] != Next && board[xx][yy] != '-') {xx += dx[dic], yy += dy[dic];}
            else break;
          }
       }
   }
   if(ok) return true;
   else return false;
}

void Lprint(){
   vector< pair<int, int> >v;
   _for(i,0,8){
     _for(j,0,8)
        if(board[i][j] == '-' && legal(i,j,0) )
           v.push_back( make_pair(i+1,j+1) );
   }
   if(v.empty()) printf("No legal move.\n");
   else for(unsigned int i = 0; i < v.size(); i++)
      printf("(%d,%d)%c", v[i].first, v[i].second, i == v.size()-1 ?'\n':' ');
}

void Mrc(int x, int y){
   if(!legal(x,y,1)) { Next = (Next == 'W'?'B':'W'); legal(x,y,1); }// 不合法 换成对方下
   Next = (Next == 'W'?'B':'W');
   int B = 0, W = 0;
   _for(i,0,8)
      _for(j,0,8)
        if(board[i][j] == 'W') W++;
        else if(board[i][j] == 'B') B++;
    printf("Black - %2d White - %2d\n",B,W);
}

void Print(){
    _for(i,0,8) printf("%s\n",board[i]);
    if(n) putchar('\n');
}

int main(){
  scanf("%d",&n);
  while(n--){
     read_input();
     while(1){
        char op[10];
        scanf("%s", op);
        if(op[0] == 'L') Lprint();
        else if(op[0] == 'M') Mrc(op[1]-'1', op[2]-'1');
        else if(op[0] == 'Q') { Print(); break; }
     }
  }
  return 0;
}



/*
Sample Input

2
--------
--------
--------
---WB---
---BW---
--------
--------
--------
W
L
M35
L
Q
WWWWB---
WWWB----
WWB-----
WB------
--------
--------
--------
--------
B
L
M25
L
Q

Sample Output

(3,5) (4,6) (5,3) (6,4)
Black - 1 White - 4
(3,4) (3,6) (5,6)

--------
--------
----W---
---WW---
---BW---
--------
--------
--------

No legal move.
Black - 3 White - 12
(3,5)
WWWWB---
WWWWW---
WWB-----
WB------
--------
--------
--------
--------

*/