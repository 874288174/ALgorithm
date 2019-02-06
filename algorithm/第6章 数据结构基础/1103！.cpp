const int maxn = 200+5;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
const char word[] = {'W', 'A', 'K', 'J', 'S' , 'D'};
char b[maxn][maxn];
int buf[maxn][4*maxn];
bool visit[maxn][4*maxn];
int n ,m;
vector<set<int> >v;

void color(int i, int j){
   int k = ( isdigit(b[i][j]) ? (b[i][j] - '0'): (b[i][j] - 'a' + 10) );
   buf[i][4*j+1] = k / 8;
   buf[i][4*j+2] = (k % 8) / 4;
   buf[i][4*j+3] = (k % 4) / 2;
   buf[i][4*j+4] = k % 2;
}

bool inside(int x,int y){
   return (x >= 0 && y >= 0 && x < n && y < m);
}

void dfs(int i, int j, int cnt){
   visit[i][j] = true;
   buf[i][j] = cnt;
   for(int k = 0; k < 4; k++){
     int x = i + dx[k], y = j + dy[k];
     if(inside(x,y) && !visit[x][y] && buf[x][y])
        dfs(x,y,cnt);
   }
}

void Dfs(int i, int j, int Cnt){
   visit[i][j] = true;
   for(int k = 0; k < 4; k++){
     int x = i + dx[k], y = j + dy[k];
     if(inside(x,y) && !visit[x][y] && buf[x][y])
        v[ buf[x][y] ].insert(Cnt);
     if(inside(x,y) && !visit[x][y] && !buf[x][y])
        Dfs(x,y,Cnt);
   }
}

int main(){
    int kase = 0, cnt, Cnt;
    while(scanf("%d%d",&n,&m) == 2 && n && m){
        memset(buf,0,sizeof(buf));
        memset(visit,false,sizeof(visit));
        cnt = 0;
        for(int i = 1; i <= n; i++){
            scanf("%s",b[i]);
            for(int j = 0; j < m; j++)
                color(i,j);
        }
        n = n + 2; m = 4*m+2;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
               if(!visit[i][j] && buf[i][j])
                  dfs(i,j,++cnt);

        memset(visit,false,sizeof(visit));
        v.clear();
        v.resize(cnt+1);
        Cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
               if(!visit[i][j] && !buf[i][j])
                  Dfs(i,j,++Cnt);

        vector<char> ans;
        for(int i = 1; i <= cnt; i++)
           ans.push_back( word[v[i].size() - 1] );
        sort(ans.begin(), ans.end());
        printf("Case %d: ", ++kase);
        for(int i = 0; i < ans.size(); i++) printf("%c", ans[i]);
        printf("\n");
    }
    return 0;
}