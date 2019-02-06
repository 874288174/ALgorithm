typedef pair<int,int> PI;
const int maxn = 8;
const int dx[] = {2, 1, -1, -2, -2, -1,  1,  2};
const int dy[] = {1, 2,  2,  1, -1, -2, -2, -1};
bool visit[maxn][maxn];
int cnt[maxn][maxn];
PI a, b;


bool inside(int x,int y){
   return (x >= 0 && y >= 0 && x < maxn && y < maxn);
}


void bfs(){
    queue<PI>Q;
    Q.push(a);
    while(!Q.empty()){
       PI u = Q.front();
       Q.pop();
       if(u == b){
          cout<<cnt[b.first][b.second];
          return;
       }
       for(int k = 0; k < 8; k++){
          int xx = u.first +  dx[k], yy = u.second + dy[k];
          if(inside(xx,yy) && !visit[xx][yy]){
              visit[xx][yy] = true;
              cnt[xx][yy] = cnt[u.first][u.second] + 1;
              Q.push(make_pair(xx,yy));
          }
       }
    }
}

int main(){
    char buf[maxn];
    while(fgets(buf,maxn,stdin) ){
        memset(visit,false,sizeof(visit));
        memset(cnt,0,sizeof(cnt));
        printf("To get from %c%c to %c%c takes ",buf[0],buf[1],buf[3],buf[4]);
        int x0, y0, x1, y1;
        x0 = buf[0] - 'a'; y0 = buf[1] - '1';
        x1 = buf[3] - 'a'; y1 = buf[4] - '1';
        visit[x0][y0] = true;
        a = make_pair(x0,y0), b = make_pair(x1,y1);
        bfs();
        printf(" knight moves.\n");
    }
    return 0;
}