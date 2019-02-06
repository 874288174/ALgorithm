#include<bits/stdc++.h>
using namespace std;


const int maxn = 30+5;
int A[maxn*maxn], B[maxn*maxn];
double water, level;
int k;

int main(){
    int kase = 0, n , m;
    while(scanf("%d%d",&n, &m) == 2 && n && m){
        for(int i = 0; i < n*m; i++) scanf("%d",&A[i]);
        sort(A, A+n*m);
        B[0] = 0;
        for(int i = 1; i <= n*m; i++) B[i] = B[i-1] + A[i-1];
        scanf("%lf", &water);
        water /= 100;
        for(int i = 1; i <= n*m; i++){
            if(i == n*m || water + B[i] <= A[i]*i ){
                level = (water + B[i]) / i;
                k = i;
                break;
            }
        }
        printf("Region %d\n", ++kase);
        printf("Water level is %.2f meters.\n", level);
        printf("%.2f percent of the region is under water.\n\n", k*100.0/(n*m));
    }
    return 0;
}


/*

Sample Input

3 3
25 37 45
51 12 34
94 83 27
10000
0 0

Sample Output

Region 1
Water level is 46.67 meters.
66.67 percent of the region is under water.

*/