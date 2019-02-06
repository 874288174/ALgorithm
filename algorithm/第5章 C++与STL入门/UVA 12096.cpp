#include<bits/stdc++.h>
using namespace std;

typedef set<int> Set;
map<Set, int> IDcache;
vector< Set > Setcache;
int cnt;
string op;


int ID(Set x){
   if( IDcache.count(x) )return IDcache[x];
   Setcache.push_back(x);
   return IDcache[x] = Setcache.size() - 1;
}


int main(){
   int T, N;
   scanf("%d",&T);
   while(T--){
      stack< int >s;
      scanf("%d",&N);
      while(N--){
         cin >> op;
         if(op[0] == 'P') s.push( ID(Set{}) );
         else if(op[0] == 'D') s.push( s.top() );
         else{
            Set A = Setcache[s.top()];    s.pop();
            Set B = Setcache[s.top()];    s.pop();
            Set x;
            if(op[0] == 'U') set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(x,x.begin()));
            if(op[0] == 'A') {x = B; x.insert( ID(A) );}
            if(op[0] == 'I') set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(x,x.begin()));
            s.push( ID(x) );
         }
         cout << Setcache[s.top()].size() << endl;
      }
      cout <<"***\n";
   }
   return 0;
}


/*
Sample Input

2
9
PUSH
DUP
ADD
PUSH
ADD
DUP
ADD
DUP
UNION
5
PUSH
PUSH
ADD
PUSH
INTERSECT

Sample Output

0
0
1
0
1
1
2
2
2
***
0
0
1
0
0
***

*/