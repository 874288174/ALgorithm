#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
char s1[maxn], s2[maxn];


int main(){
    while(scanf("%s%s",s1,s2) == 2 ){
        bool ok = true;
        int A[26] = {0},B[26] = {0};
        int n = strlen(s1), m = strlen(s2);
        for(int i = 0; i < n; i++) A[s1[i] - 'A'] ++ ;
        for(int i = 0; i < m; i++) B[s2[i] - 'A'] ++ ;
        sort(A, A+26); sort(B, B+26);
        for(int i = 0; i < 26; i++)
           if(A[i] != B[i]) {
               ok = false;
               break;
           }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
}



/*
Sample Input

JWPUDJSTVP
VICTORIOUS
MAMA
ROME
HAHA
HEHE
AAA
AAA
NEERCISTHEBEST
SECRETMESSAGES

Sample Output

YES
NO
YES
YES
NO

*/