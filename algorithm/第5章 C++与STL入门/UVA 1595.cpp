#include<bits/stdc++.h>
using namespace std;

const int  maxn = 1000 + 5;
const double eps = 1e-6;
int N;
struct node{
   double x, y;
   bool operator < (const node &rhs) const{
      return x < rhs.x;
   }
}a[maxn];

int main(){
   int T;
   scanf("%d",&T);
   while(T--){
      scanf("%d",&N);
      for(int i =0; i < N; i++) scanf("%lf%lf", &a[i].x, &a[i].y);
      sort(a, a+N);
      bool ok = true;
      double mid = a[0].x + a[N-1].x;
      for(int i = 0; i < N/2+1; i++){
         if(a[i].x + a[N-1-i].x - mid > eps || ((a[i].y - a[N-1-i].y > eps) && a[i].x - a[N-1-i].x > eps) )
            ok = false; break;
      }
      if(ok) cout<<"YES\n";
      else cout<<"NO\n";
   }
   return 0;
}


/*

Sample Input

3
5
-2 5
0 0
6 5
4 0
2 3
4
2 3
0 4
4 0
0 0
4
5 14
6 10
5 10
6 14

Sample Output
YES
NO
YES

*/