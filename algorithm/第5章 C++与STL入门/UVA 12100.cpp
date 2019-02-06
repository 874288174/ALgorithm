#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;

struct cmp{
   bool operator () (const int &a, const int &b)const{
      return a < b;
   }
};

int main(){
   int N, n, id;
   scanf("%d",&N);
   while(N--){
       scanf("%d%d", &n, &id);
       queue< int > q;
       priority_queue< int, vector<int>, cmp > pq;
       for(int i = 0; i < n; i++){
           int a;
           scanf("%d",&a);
           q.push( (i == id) ? -a : a);
           pq.push(a);
       }
       int cnt = 0;
       while(1){
           int t = q.front();
           if( pq.top() > abs(t) ){
              q.push(t); q.pop();
           }
           else if(t < 0) {
              printf("%d\n",++cnt);
              break;
           }
           else{
             ++cnt;
             q.pop(); pq.pop();
           }
       }
   }
   return 0;
}

/*
Sample Input

3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1


Sample Output

1
2
5

*/