const int maxn = 10000;
const int dx[] = {1,1,0,-1,-1,-1,0,1};
const int dy[] = {0,1,1,1,0,-1,-1,-1};
char buf[maxn][maxn];
bool visit[maxn][maxn];
int n ,m;

bool inside(int x, int y){
   return (x >= 0 && y >= 0 && x < n && y < m);
}

void dfs(int x,int y){
   visit[x][y] = true;
   for(int i = 0; i < 8; i++){
      int xx = x + dx[i], yy = y + dy[i];
      if(inside(xx,yy) && !visit[xx][yy] && buf[xx][yy] == '@' )
         dfs(xx,yy);
   }
}

int main(){
    int cnt;
    while(scanf("%d%d",&n,&m) == 2 && n && m){
        for(int i = 0; i < n; i++)
            scanf("%s",buf[i]);
        memset(visit,false,sizeof(visit));
        cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!visit[i][j] && buf[i][j] == '@'){
                    cnt++;
                    dfs(i,j);
                }
        cout<<cnt<<endl;
    }
    return 0;
}

/*
Sample Input

1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0


Sample Output

0
1
2
2

*/