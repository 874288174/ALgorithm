#include<bits/stdc++.h>
using namespace std;

string s1, s2;

int main(){
    while( cin >> s1 >> s2 ){
        int n = s1.length(), m = s2.length();
        int ans = m + n;
        for(int i = 0; i < n; i++){
            bool ok = true;
            int ii = i;
            for(int j = 0; j < m; j++){
                if(s1[ii++] - '0' + s2[j] - '0' > 3){
                    ok = false; break;
                }
                if(ii == n) break;
            }
            if(ok) {ans = max(n, i + m);break;}
        }

        swap(s1,s2); swap(n,m);
        for(int i = 0; i < n; i++){
            bool ok = true;
            int ii = i;
            for(int j = 0; j < m; j++){
                if(s1[ii++] - '0' + s2[j] - '0' > 3){
                    ok = false; break;
                }
                if(ii == n) break;
            }
            if(ok) {ans = min(ans, max(n, i + m));break;}
        }
        printf("%d\n",ans);
    }
    return 0;
}


/*
Sample Input

2112112112
2212112
12121212
21212121
2211221122
21212


Sample Output

10
8
15

*/