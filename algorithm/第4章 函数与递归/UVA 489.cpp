#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;

int main(){
    int n;
    while(scanf("%d",&n) == 1 && n != -1){
       int left = 7, ok = 1;
       printf("Round %d\n",n);
       string s1,s2;
       cin >> s1 >> s2;
       unordered_set< char > My_set;
       for(auto &p : s1) My_set.insert(p);
       for(auto &p : s2)
         if( My_set.count(p) ){
            My_set.erase(p);
            if( My_set.empty() ) { ok = 0; printf("You win.\n"); break ;}
         }
         else{
            if(--left == 0)  { ok = 0; printf("You lose.\n"); break; }
         }
       if(ok) printf("You chickened out.\n");
    }
}



/*
Sample Input

1
cheese
chese
2
cheese
abcdefg
3
cheese
abcdefgij
-1

Sample Output

Round 1
You win.
Round 2
You chickened out.
Round 3
You lose.

*/