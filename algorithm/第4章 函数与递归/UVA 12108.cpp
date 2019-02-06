#include<bits/stdc++.h>
using namespace std;

const int maxn = 10 + 2;
int n, T;
int A[maxn], B[maxn], C[maxn];


int main(){
  int kase = 0;
  bool ok;
  while(scanf("%d",&n) == 1 && n){
     for(int i = 0; i < n; i++) scanf("%d%d%d", &A[i], &B[i], &C[i]);
     ok = false;
     T = 1;
     for(; T < 1000000; T++){
        int cnt = 0;
        for(int i = 0; i < n; i++)
            if((C[i] + T - 2) % (A[i] + B[i]) <= A[i]-1) cnt++;
        if(cnt == n){ ok = true; break;}
        else if(cnt*2 >= n)
           for(int i = 0; i < n; i++)
              if((C[i] + T - 2) % (A[i] + B[i]) == A[i]-1) C[i] -= A[i];
     }

     if(ok) printf("Case %d: %d\n", ++kase, T);
     else printf("Case %d: -1\n", ++kase);
  }
  return 0;
}

/*
Sample Input

3
2 4 1
1 5 2
1 4 3
3
1 2 1
1 2 2
1 2 3
0

Sample Output

Case 1: 18
Case 2: -1

*/
