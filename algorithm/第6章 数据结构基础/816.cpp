const int maxn = 10;
const char dirs[] = "NEWS";
const char turn[] = "LFR";

const int newx[4][3] = { 0,-1,0,
                         -1,0,1,
                         1,0,-1,
                         0,1,0 };

const int newy[4][3] = { -1,0,1,
                         0,1,0,
                         0,-1,0,
                         1,0,-1 };

const int newdir[4][3] = {2,0,1,
                          0,1,3,
                          3,2,0,
                          1,3,2};

int dirs_id(char c) {return (strchr(dirs,c) - dirs);}
int turn_id(char c) {return (strchr(turn,c) - turn);}

struct node{
   int x, y, dir;
};

int d[maxn][maxn][4][3];
bool visit[maxn][maxn][4];
node path[maxn][maxn][4];
int r0,c0,r1,c1,C;
char c;
bool ok;


bool read_input(){
   int x, y;
   string s;
   cin>>x;  if(!x) return false;
   cin>>y;
   while(cin>>s && s != "*")
      for(int i = 1; i < (int)s.length(); i++)
          d[x][y][ dirs_id(s[0]) ][ turn_id(s[i]) ] = 1;
   return true;
}

void solve(){
    queue<node>q;
    q.push({r0,c0,dirs_id(c)});
    visit[r0][c0][dirs_id(c)] = true;
    while(!q.empty()){
        node u = q.front();
        q.pop();
        if(u.x == r1 && u.y == c1) {
            C = u.dir; ok = true; break;
        }
        for(int k = 0; k < 3; k++){
            int xx = u.x + newx[u.dir][k], yy = u.y + newy[u.dir][k], dd = newdir[u.dir][k];
            if(d[u.x][u.y][u.dir][k] && !visit[xx][yy][dd]){
                visit[u.x][u.y][u.dir] = true;
                q.push({xx,yy,dd});
                path[xx][yy][dd] = u;
            }
        }
    }
    return ;
}
void print(){
    if(!ok) {printf(" No Solution Possible\n"); return;}
    vector<node>ans;
    node u = {r1,c1,C};
    while(u.x != r0 || u.y != c0){
        ans.push_back(u);
        u = path[u.x][u.y][u.dir];
    }
    ans.push_back(u);
    int cnt = 0;
    for(int i = ans.size() - 1; i >= 0; i--){
        printf(" (%d,%d)",ans[i].x,ans[i].y);
        if(++cnt % 10 == 0 && i != 0) cout<<endl<<" ";
    }
    putchar('\n');
    return ;
}

int main(){
    string name;
    while(cin>>name && name != "END"){
        memset(d,0,sizeof(d));
        memset(visit,false,sizeof(visit));
        cout<<name<<endl<<" ";
        cin>>r0>>c0>>c>>r1>>c1;
        d[r0][c0][ dirs_id(c) ][ 1 ] = 1;
        ok = false;
        while(read_input());
        solve();
        print();
    }
    return 0;
}

/*
Sample Input

SAMPLE
3 1 N 3 3
1 1 WL NR *
1 2 WLF NR ER *
1 3 NL ER *
2 1 SL WR NF *
2 2 SL WF ELF *
2 3 SFR EL *
0
NOSOLUTION
3 1 N 3 2
1 1 WL NR *
1 2 NL ER *
2 1 SL WR NFR *
2 2 SR EL *
0
END

Sample Output

SAMPLE
  (3,1) (2,1) (1,1) (1,2) (2,2) (2,3) (1,3) (1,2) (1,1) (2,1)
  (2,2) (1,2) (1,3) (2,3) (3,3)
NOSOLUTION
  No Solution Possible

*/