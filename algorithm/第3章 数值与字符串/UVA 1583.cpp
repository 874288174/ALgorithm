#include<bits/stdc++.h>
using namespace std;

const int maxn = 100000;
int S[maxn];

int f(int i){
   int sum = i;
   while(i > 0){
      sum += (i%10);
      i = i/10;
   }
   return sum;
}

int main(){
    memset(S,0,sizeof(S));
    for(int i = 1; i < maxn; i++){
        int t = f(i);
        if(!S[t]) S[t] = i;
    }
    int n, a;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a);
        printf("%d\n",S[a]);
    }
    return 0;
}



/*
Sample Input

3
216
121
2005

Sample Output

198
0
1979

*/