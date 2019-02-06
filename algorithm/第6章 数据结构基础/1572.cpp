const int maxn = 52;
int G[maxn][maxn];
char s[10];
bool ok;
int visit[maxn];

void link(char a, char b, char c, char d){
    if(a == '0' || c == '0') return;
    int u = (a - 'A')*2 + ( b == '+' ? 1 : 0);
    int v = (c - 'A')*2 + ( d == '+' ? 1 : 0);
    G[u^1][v] = 1;
}

bool dfs(int i){
    visit[i] = -1;
    for(int v = 0; v < 52; v++) if(G[i][v]) {
       if(visit[v] < 0) return true;
       else if(!visit[v] && dfs(v)) return true;
    }
    visit[i] = 1;
    return false;
}

int main(){
   int n;
   while(scanf("%d",&n) == 1 && n){
       fill(G[0],G[0]+maxn*maxn,0);
       while(n--){
          scanf("%s",s);
          for(int i = 0; i < 4; i++)
             for(int j = 0; j < 4; j++)
                if(i != j)
                   link(s[2*i],s[2*i+1],s[2*j],s[2*j+1]);
       }
       ok = false;
       memset(visit,0,sizeof(visit));
       for(int i = 0; i < maxn; i++){
          if( !visit[i] && dfs(i) ){ok = true; break;}
       }
       if(ok) printf("unbounded\n");
       else printf("bounded\n");
   }
   return 0;
}