const int maxn = 52+2;
int Left[maxn], Right[maxn];
stack< string >pile[maxn];
int num[maxn];
int cnt;

bool read_input(){
  string s;
  for(int i = 1; i <= 52; i++){
      cin>>s;
      if(s[0] == '#') return false;
      pile[i].push(s);
  }
  return true;
}

void init(){
   for(int i = 0; i < maxn; i++){
      Right[i] = i+1;
      Left[i] = i-1;
   }
   cnt = 52;
   fill(num,num+maxn,1);
}

int check(int i, int k){
   int t = i;
   while(k--){
      t = Left[t];
      if(!t) return 0;
   }
   string a = pile[t].top(), b = pile[i].top();
   if(a[0] == b[0] || a[1] == b[1] ) return t;
   else return 0;
}

void link(int i,int j){
   Right[i] = j; Left[j] = i;
}

void solve(){
    for(int x = 1;x != 53; x = Right[x]){
        int t;
        if( ( t = check(x,3) ) || ( t = check(x,1)) ){
            pile[t].push( pile[x].top() );
            pile[x].pop();
            num[x]--; num[t]++;
            if(!num[x]) { link(Left[x], Right[x]); cnt--; }
            x = Left[t];
        }
    }
    if(cnt == 1 ) printf("%d pile remaining:",cnt);
    else printf("%d piles remaining:",cnt);
    for(int i = 1; i <= 52; i++)
      if(num[i])
        printf(" %d",num[i]);
    putchar('\n');
}

int main(){
  while( read_input() ){
     init();
     solve();
  }
  return 0;
}