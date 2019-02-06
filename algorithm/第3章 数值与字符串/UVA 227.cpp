#include<bits/stdc++.h>
using namespace std;

const int maxn = 10;
char frame[maxn][maxn];
int spacex, spacey;
bool ok;

bool inside(int x, int y){
   if(x < 0 || y < 0 || x > 4 || y > 4) return false;
   return true;
}

bool read_input(){
    for(int i = 0; i < 5; i++){
        fgets(frame[i], maxn, stdin);
        if(frame[0][0] == 'Z') return false;
    }
    for(int x = 0; x < 5; x++)
       for(int y = 0; y < 5; y++){
           if(frame[x][y] == ' '){
               spacex = x; spacey = y;
               return true;
           }
       }
    return false;
}

bool op(char c){
    int tempx, tempy;
    if( !ok ) return false;
    switch(c){
        case 'A': {tempx = spacex - 1; tempy = spacey; break;}
        case 'B': {tempx = spacex + 1; tempy = spacey; break;}
        case 'L': {tempx = spacex; tempy = spacey - 1; break;}
        case 'R': {tempx = spacex; tempy = spacey + 1; break;}
    }
    if( inside(tempx, tempy) ){
        swap( frame[tempx][tempy], frame[spacex][spacey]);
        spacex = tempx; spacey = tempy;
        return true;
    }
    else return false;
}

int main(){
   int kase = 0;
   while(read_input()){
      char c;
      ok = true;
      while( (c = getchar() ) != '0')  if(c != '\n') ok = op(c);
      getchar();
      if(kase) printf("\n");
      printf("Puzzle #%d:\n",++kase);
      if(ok){
          for(int x = 0; x < 5; x++)
              for(int y = 0; y < 5; y++)
                  printf("%c%c", frame[x][y], (y == 4)?'\n':' ');
      }
      else printf("This puzzle has no final configuration.\n");
   }
   return 0;
}



/*


Sample Input

TRGSJ
XDOKI
M VLN
WPABE
UQHCF
ARRBBL0
ABCDE
FGHIJ
KLMNO
PQRS
TUVWX
AAA
LLLL0
ABCDE
FGHIJ
KLMNO
PQRS
TUVWX
AAAAABBRRRLL0
Z

Sample Output

Puzzle #1:
T R G S J
X O K L I
M D V B N
W P   A E
U Q H C F

Puzzle #2:
  A B C D
F G H I E
K L M N J
P Q R S O
T U V W X

Puzzle #3:
This puzzle has no final configuration.

*/