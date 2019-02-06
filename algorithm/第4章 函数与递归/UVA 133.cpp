#include<bits/stdc++.h>
using namespace std;

const int maxn = 20 + 5;
int a[maxn];
int n, m ,k;

int go(int pos,int k,int cnt){
    while(cnt--){
        pos = (pos+k+n)%n;
        while( !a[pos] ) pos = (pos+k+n)%n;
    }
    return pos;
}

int main(){
    while(scanf("%d%d%d",&n,&k,&m) == 3 && n ){
       memset(a,1,sizeof(a));
       int p = n-1, q = 0, cnt = n;
       while(1){
           p = go(p,1,k);
           q = go(q,-1,m);
           if(p == q) {printf("%3d",p+1); a[p] = 0; cnt --;}
           else{
               printf("%3d%3d",p+1,q+1); a[p] = a[q] = 0; cnt = cnt - 2;
           }
           if(!cnt) break;
           else putchar(',');
       }
       putchar('\n');
    }
}



/*
Sample Input

10 4 3
0 0 0

Sample Output

  4  8,  9  5,  3  1,  2  6, 10,  7

*/