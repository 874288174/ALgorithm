#include<bits/stdc++.h>
using namespace std;

map< string,string > my_map;
set< string > my_set;

int main(){
   string a,b;
   while(cin >> a && a != "#"){
      b = a;
      for(int i = 0; i < a.length(); i++)  a[i] = tolower(a[i]);
      sort(a.begin(),a.end());
      if( !my_map.count(a) ) my_map[a] = b;
      else my_map[a] = "";
   }
   for(auto &i : my_map) if(i.second != ""){
      my_set.insert(i.second);
   }
   for(auto &i:my_set)
      cout << i << endl;
   return 0;
}


/*
Sample Input

ladder came tape soon leader acme RIDE lone Dreis peat ScAlE orb eye Rides dealer NotE derail LaCeS drIed noel dire Disk mace Rob dries #

Sample Output

Disk NotE derail drIed eye ladder soon

*/