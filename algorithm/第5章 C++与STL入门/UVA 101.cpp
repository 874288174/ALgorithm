#include<bits/stdc++.h>
using namespace std;

const int maxn = 10;
char s1[maxn], s2[maxn];
vector< vector< int > > v;
vector< int > pos;

void putback(int a){
   int pile = pos[a], i = 0;
   while(v[pile][i] != a) i++;
   for(int j = i + 1; j < (int)v[pile].size(); j++)
      v[ v[pile][j] ].push_back( pos[v[pile][j]] = v[pile][j] );
   v[pile].resize(i + 1);
}

void Move(int a,int b){
   int pile_a = pos[a], pile_b = pos[b], i = 0;
   while(v[pile_a][i] != a) i++;
   for(int j = i; j < (int)v[pile_a].size(); j++)
      v[ pos[v[pile_a][j]] = pile_b ].push_back( v[pile_a][j] );
   v[pile_a].resize(i);
}

int main(){
   int N;
   scanf("%d",&N);
   v.resize(N);
   pos.resize(N);
   for(int i = 0; i < N; i++)
     v[i].push_back(pos[i] = i);

   while(scanf("%s",s1) && strcmp(s1,"quit")){
       int a, b;
       scanf("%d%s%d",&a,s2,&b);
       if(pos[a] == pos[b]) continue;
       if(s1[0] == 'm') putback(a);
       if(s2[1] == 'n') putback(b);
       Move(a,b);
   }
   for(int i = 0; i < N; i++){
       printf("%d:",i);
       for(int j = 0; j < v[i].size(); j++)
          printf(" %d",v[i][j]);
       putchar('\n');
   }
   return 0;
}


/*
Sample Input

10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
quit

Sample Output

0: 0
1: 1 9 2 4
2:
3: 3
4:
5: 5 8 7 6
6:
7:
8:
9:

*/