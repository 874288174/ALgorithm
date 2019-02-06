const int maxn = 1000 + 10;
double x[maxn], y[maxn], r[maxn];
double Left = 1000.0, Right = 1000.0;
bool visit[maxn];
int n;

double dist(int i, int j){
   return sqrt( (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) );
}

bool dfs(int i){
   visit[i] = true;
   if(y[i] - r[i] < 0) return true;
   for(int j = 0; j < n; j++)
      if(r[i] + r[j] > dist(i,j) && !visit[j] && dfs(j) )  return true;
   if(x[i] - r[i] < 0)
      Left =  min( Left, y[i] - sqrt( r[i] * r[i] - x[i] * x[i] ) );
   if(x[i] + r[i] > 1000)
      Right = min( Right, y[i] - sqrt( r[i] * r[i] - ( 1000.0 - x[i] ) * ( 1000.0 - x[i] ) ) );
   return false;
}

int main(){
   while( scanf("%d",&n) == 1){
      memset(visit,false,sizeof(visit));
      Left = Right = 1000;
      bool ok = true;
      for(int i = 0; i < n; i++)
         scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
      for(int i = 0; i < n; i++)
         if(y[i] + r[i] >= 1000 && !visit[i] && dfs(i) )
             {ok = false; break;}
      if(!ok) printf("IMPOSSIBLE\n");
      else printf("0.00 %.2f 1000.00 %.2f\n",Left, Right);
   }
   return 0;
}

/*
Sample Input

3
500 500 499
0 0 999
1000 1000 200

Sample Output

0.00 1000.00 1000.00 800.00

*/