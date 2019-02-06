#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;

struct node{
   int id;
   double x, y, l, w, h;
   bool operator < (const node & rhs) const{
      return x < rhs.x || (x == rhs.x && y < rhs.y);
   }
}build[maxn];

int x[maxn*2], N;

bool cover(int i,double x0){
   if( build[i].x > x0 || build[i].x + build[i].l < x0 ) return false;
   return true;
}

bool visible(int i, double x0){
    if( !cover(i,x0) ) return false;
    for(int j = 0; j < N; j++){
        if(build[j].y < build[i].y && build[j].h >= build[i].h && cover(j,x0) )
            return false;
    }
    return true;
}

int main(){
   int kase = 0;
   while(scanf("%d",&N) == 1 && N){
       for(int i = 0; i < N; i++){
           scanf("%lf%lf%lf%lf%lf", &build[i].x, &build[i].y, &build[i].l, &build[i].w, &build[i].h);
           x[2*i] = build[i].x;    x[2*i+1] = build[i].x + build[i].l;
           build[i].id = i+1;
       }
       sort(build, build+N);
       sort(x, x+2*N);
       int n = unique(x, x+2*N) - x;
       if( kase ) putchar('\n');
       printf("For map #%d, the visible buildings are numbered as follows:\n%d", ++kase, build[0].id);
       for(int i = 1; i < N; i++){
           bool ok = false;
           for(int j = 0; j < n-1; j++) if( visible(i,(x[j]+x[j+1])/2) ) {
              ok = true;
              break;
           }
           if(ok) printf(" %d",build[i].id);
       }
       putchar('\n');
   }
   return 0;
}

/*
Sample Input

14
160 0 30 60 30
125 0 32 28 60
95 0 27 28 40
70 35 19 55 90
0 0 60 35 80
0 40 29 20 60
35 40 25 45 80
0 67 25 20 50
0 92 90 20 80
95 38 55 12 50
95 60 60 13 30
95 80 45 25 50
165 65 15 15 25
165 85 10 15 35
0


Sample Output

For map #1, the visible buildings are numbered as follows:
5 9 4 3 10 2 1 14

*/