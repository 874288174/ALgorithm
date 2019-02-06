#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int x[] = {2,3,5};
struct cmp{
   bool operator () (const ll a, const ll b) const {
      return a > b;
   }
};

priority_queue<ll, vector<ll> , cmp > pq;
set< ll >S;

int main() {
   pq.push(1);
   S.insert(1);
   for(int i = 1;;i++){
      ll s = pq.top();  pq.pop();
      if(i == 1500){
         printf("The 1500'th ugly number is %lld.\n",s);
         break;
      }
      for(int ii = 0; ii < 3; ii++){
         ll x2 = s * x[ii];
         if( !S.count(x2) ){
            pq.push(x2);
            S.insert(x2);
         }
      }
   }
   return 0;
}
