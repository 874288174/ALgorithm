#include<bits/stdc++.h>
using namespace std;

int N;
set< string > Set;

int check(vector<int> &v){
   int minstart = 0;
   for(int i = 1; i < N; i++){
      int j = minstart, k = i;
      do{
        if(v[j] > v[k]) { minstart = i; break; }
        else if (v[j] < v[k] ) break;
        j = (j+1) % N; k = (k+1) % N;
      }while(k != i);
   }
   string s;
   bool ok = true;
   for(int i = 0; i < N; i++){
      int k = v[(minstart + i) % N];
      if( k ) ok = false;
      s += to_string(k);
   }
   if(ok) return 0;
   if( !Set.count(s) ) { Set.insert(s); return -1;}
   else return 1;
}

int main() {
   int T;
   scanf("%d",&T);
   while( T-- ){
      scanf("%d", &N);
      vector< int > v(N);
      Set.clear();
      for(int i = 0; i < N; i++) scanf("%d", &v[i]);
      while(1){
          int start = v[0];
          for(int i = 0; i < N-1; i++) v[i] = abs(v[i] - v[i+1]);
          v[N-1] = abs(v[N-1] - start);
          int n = check(v);
          if(n == 1) { cout << "LOOP" << endl; break;}
          else if(n == 0){ cout << "ZERO"<<endl; break;}
      }
   }
   return 0;
}




/*
Sample Input

4
4
8 11 2 7
5
4 2 0 2 0
7
0 0 0 0 0 0 0
6
1 2 3 1 2 3


Sample Output

ZERO
LOOP
ZERO
LOOP

*/