#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int>my_map;
const int maxr = 10000 + 5;
const int maxc = 10 + 5;
int m, n, db[maxr][maxc], cnt;

int ID(string s){
   if( !my_map.count(s) ) my_map[s] = cnt++;
   return my_map[s];
}

void Find() {
  for(int c1 = 1; c1 <= m; c1++)
    for(int c2 = c1+1; c2 <= m; c2++) {
      map< pair<int, int>, int> d;
      for(int i = 1; i <= n; i++) {
        pair<int, int> p = {db[i][c1], db[i][c2]};
        if( d.count(p) ){
          printf("NO\n%d %d\n%d %d\n", d[p], i, c1, c2);
          return;
        }
        d[p] = i;
      }
    }
  printf("YES\n");
}

int main(){
   while(scanf("%d%d\n",&n, &m) == 2){
       my_map.clear();
       cnt = 0;
       for(int i = 1; i <= n; i++){
          string len, s;
          int j = 1;
          getline(cin, len);
          for(auto &k : len) if(k == ',') k = '\n';
          stringstream ss(len);
          while( getline(ss,s) )  db[i][j++] = ID(s);
       }
       Find();
   }
   return 0;
}

/*

Sample Input

3 3
How to compete in ACM ICPC,Peter,peter@neerc.ifmo.ru
How to win ACM ICPC,Michael,michael@neerc.ifmo.ru
Notes from ACM ICPC champion,Michael,michael@neerc.ifmo.ru
2 3
1,Peter,peter@neerc.ifmo.ru
2,Michael,michael@neerc.ifmo.ru

Sample Output

NO
2 3
2 3
YES

*/