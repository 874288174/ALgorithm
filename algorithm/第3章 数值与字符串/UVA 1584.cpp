#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
char s[maxn];
int len, best;

void f(int i){
    for(int k = 0; k < len; k++)
       if(s[ (i+k) % len ] > s[ (best+k) % len ]) break;
       else if(s[ (i+k) % len ] < s[ (best+k) % len ]) {best = i; break;}
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        len = strlen(s);
        best = 0;
        for(int i = 0; i < len; i++) f(i);
        for(int i = 0; i < len; i++)
           printf("%c",s[(best+i) % len]);
        putchar('\n');
    }
    return 0;
}


/*
Sample Input

2
CGAGTCAGCT
CTCC

Sample Output

AGCTCGAGTC
CCCT

*/
