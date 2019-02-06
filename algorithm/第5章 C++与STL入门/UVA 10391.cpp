#include<bits/stdc++.h>
using namespace std;

set<string>s;

int main(){
   string a;
   while( cin >> a) s.insert(a);
   for(auto &a : s){
      int len = a.length();
      for(int i = 1; i < len-1; i++){
         if(s.count(a.substr(0,i)) && s.count(a.substr(i)) ){
            cout << a << endl; break;
         }
      }
   }
   return 0;
}

/*
Sample Input

a
alien
born
less
lien
never
nevertheless
new
newborn
the
zebra


Sample Output

alien
newborn

*/