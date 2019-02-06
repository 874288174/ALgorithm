#include<bits/stdc++.h>
using namespace std;

int a, b, c, k, cnt;
unordered_map< int,vector<int> > My_map;
vector< int > v;

void solve(){
   v.clear();
   My_map.clear();
   while(1){
      c = a / b;
      a = a % b;
      k = 1;
      for(auto it = My_map[c].begin(); it != My_map[c].end(); k++,it++)
         if(*it == a) return ;
      My_map[c].push_back(a);
      v.push_back(c);
      a *= 10;
   }
}

void print(){
   for(unsigned int i = 0; i < v.size(); i++){
      if(i > 49) { printf("..."); break; }
      if( v[i] == c && --k == 0 ) { cnt = v.size() - i; printf("(");}
      printf("%d",v[i]);
   }
   printf(")\n   %d = number of digits in repeating cycle\n", cnt);
}

int main(){
   int kase = 0;
   while( scanf("%d%d", &a, &b) == 2 ){
      if( kase++ ) putchar('\n');
      printf("%d/%d = %d.", a, b, a/b);
      a = ( a % b ) * 10;
      solve();
      print();
   }
   putchar('\n');
   return 0;
}


/*


Sample Input

76 25
5 43
1 397

Sample Output

76/25 = 3.04(0)
   1 = number of digits in repeating cycle

5/43 = 0.(116279069767441860465)
   21 = number of digits in repeating cycle

1/397 = 0.(00251889168765743073047858942065491183879093198992...)
   99 = number of digits in repeating cycle


*/