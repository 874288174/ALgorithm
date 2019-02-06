#include<bits/stdc++.h>
using namespace std;

const int maxn = 50+5, BIG = 10000;
int n ,m, a, b, k;
char cmd[3];
int buf[maxn][maxn], temp[maxn][maxn], ans[maxn][maxn], cols[maxn];

void Copy(char c, int cnt2, int i){
     if(c == 'R'){
        for(int j = 1; j <= m; j++)
            buf[cnt2][j] = temp[i][j];
     }
     else{
        for(int j = 1; j <= n; j++)
            buf[j][cnt2] = temp[j][i];
     }
}

void Del(char c){
    memcpy(temp, buf, sizeof(temp));
    int cnt = (c == 'R'? n: m), cnt2 = 0;
    for(int i = 1; i <= cnt; i++)
      if(!cols[i]) Copy(c, ++cnt2, i);
    c == 'R' ? n = cnt2 : m = cnt2;
}

void Ins(char c){
    memcpy(temp, buf, sizeof(temp));
    int cnt = (c == 'R'? n: m), cnt2 = 0;
    for(int i = 1; i <= cnt; i++){
      if(cols[i]) Copy(c, ++cnt2, 0);
      Copy(c, ++cnt2, i);
    }
    c == 'R' ? n = cnt2 : m = cnt2;
}

void EXC(){
  int A, B, C, D;
  scanf("%d%d%d%d",&A, &B, &C, &D);
  swap(buf[A][B],buf[C][D]);
}

int main(){
    int kase = 0, t;
    while( scanf("%d",&n) && n && scanf("%d",&m) ){
        memset(ans, 0, sizeof(ans));
        if( kase ) putchar('\n');
        printf("Spreadsheet #%d\n", ++kase);
        for(int i = 1; i <= n; i++)
           for(int j = 1; j <= m; j++){
              buf[i][j] = i*BIG+j;
           }

        scanf("%d",&t);
        while(t--){
            scanf("%s", cmd);
            if(cmd[0] == 'E') EXC();
            else{
                memset(cols, 0, sizeof(cols));
                scanf("%d",&k);
                while(k--){
                    int p;
                    scanf("%d", &p);
                    cols[p] = 1;
                }
                if(cmd[0] == 'D')  Del(cmd[1]);
                else if(cmd[0] == 'I') Ins(cmd[1]);
            }
        }

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                ans[buf[i][j]/BIG][buf[i][j]%BIG] = i*BIG+j;


        scanf("%d",&t);
        while(t--){
            scanf("%d%d", &a, &b);
            printf("Cell data in (%d,%d) ",a, b);
            if(!ans[a][b]) printf("GONE\n");
            else printf("moved to (%d,%d)\n", ans[a][b]/BIG, ans[a][b]%BIG);
        }
    }
    return 0;
}



/*
Sample Input

7 9
5
DR 2 1 5
DC 4 3 6 7 9
IC 1 3
IR 2 2 4
EX 1 2 6 5
4
4 8
5 5
7 8
6 5
0 0


Sample Output

Spreadsheet #1
Cell data in (4,8) moved to (4,6)
Cell data in (5,5) GONE
Cell data in (7,8) moved to (7,6)
Cell data in (6,5) moved to (1,2)

*/