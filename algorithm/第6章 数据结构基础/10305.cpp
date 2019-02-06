const int maxn = 1000;
int G[maxn][maxn];
int c[maxn];
int n, m;
vector<int>ans;

void dfs(int i){
   c[i] = 1;
   for(int j = 1; j <= n; j++)
      if(G[i][j] && !c[j])
          dfs(j);
   c[i] = -1;
   ans.push_back(i);
}

int main(){
  int a, b;
  while(scanf("%d%d",&n,&m) == 2 && n){
      memset(G,0,sizeof(G));
      memset(c,0,sizeof(c));
      ans.clear();
      for(int i = 0; i < m; i++){
          scanf("%d%d",&a,&b);
          G[a][b] = 1;
      }
      for(int i = 1; i <= n; i++)
         if(!c[i])
            dfs(i);
      for(int i = ans.size() - 1; i >= 0; i--)
         printf("%d%c",ans[i],(i == 0)?'\n':' ');
  }
  return 0;
}

/*
Sample Input

SAMPLE


5 4
1 2
2 3
1 3
1 5
0 0




Sample Output

1 4 2 5 3

*/