#include<bits/stdc++.h>
using namespace std;

int d, s, b, Mode;
char c;
string Ans;
vector< string > Disk;

bool read_input(){
    if(scanf("%d",&d) != 1 || !d) return false;
    scanf("%d%d\n%c\n", &s, &b, &c);
    Mode = (c == 'E') ? 0 : 1;
    return true;
}

bool solve(){
    Ans.clear();
    Disk.clear();
    Disk.resize(d);
    for(int i = 0; i < d; i++) cin >> Disk[i];
    for(int i = 0; i < b*s; i++){
        int check = Mode, cnt = 0, wrongdisk = -1;
        for(int j = 0; j < d; j++)
            if(Disk[j][i] != 'x')
              check ^= Disk[j][i]-'0';
            else{
              if(++cnt >= 2 ) return false;
              wrongdisk = j;
            }
        if(check && !cnt) return false;
        if(cnt) Disk[wrongdisk][i] = check+'0';
    }

     for(int i = 0, Raid = -1; i < b; i++){
        Raid = (Raid+1) % d;
        for(int j = 0; j < d; j++)
          if(j == Raid ) continue;
          else Ans += Disk[j].substr(i*s,s);
    }
    return true;
}

void Print(){
    printf("valid, contents are: ");
    while( !Ans.empty() ){
        int t = 0;
        for(int i = 0; i < 4; i++){
           if(Ans.length() != 0){
              t = t*2 + Ans[0] - '0';
              Ans.erase( Ans.begin() );
           }
           else t *= 2;
        }
        if(t <= 9) cout << t;
        else cout << char(t-10+'A');
    }
    putchar('\n');
}

int main(){
  int kase = 0;
  while(read_input()){
      printf("Disk set %d is ", ++kase);
      if( solve() )  Print();
      else printf("invalid.\n");
  }
  return 0;
}



/*
5 2 5
E
0001011111
0110111011
1011011111
1110101100
0010010111
3 2 5
E
0001111111
0111111011
xx11011111
3 5 1
O
11111
11xxx
x1111
0

Sample Output

Disk set 1 is valid, contents are: 6C7A79EDFC
Disk set 2 is invalid.
Disk set 3 is valid, contents are: FFC

*/