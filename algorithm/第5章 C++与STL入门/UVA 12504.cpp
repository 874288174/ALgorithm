#include<bits/stdc++.h>
using namespace std;

unordered_map<string, string> My_map;
set< string > Plus, Del, Change;

void f(string s, int Mode){   //Mode Çø·ÖÐÂ¾É
   for(auto &i : s) if(i == ':' || i == ',') i = ' ';
   stringstream ss(s);
   string key, value;
   while(ss >> key){
      ss >> value;
      if( Mode ) My_map[key] = value;
      else{
         if( !My_map.count(key) ) Plus.insert(key);
         else if(My_map[key] != value) {
            Change.insert(key);
            My_map.erase(key);
         }
         else My_map.erase(key);
      }
   }
   if(!Mode) for(auto &i : My_map){
      Del.insert(i.first);
   }
}


void init(){
   Plus.clear(), Change.clear(), Del.clear(), My_map.clear();
   string New, Old;
   cin >> Old;    f(Old.substr(1, Old.length()-2), 1);
   cin >> New;    f(New.substr(1, New.length()-2), 0);
}


bool Print(set< string > Set, char c){
   if( Set.empty() ) return false;
   for(auto it = Set.begin(); it != Set.end(); it++){
      if(it == Set.begin()) cout << c;
      else putchar(',');
      cout << *it;
   }
   putchar('\n');
   return true;
}

int main(){
  int N;
  scanf("%d", &N);
  while(N--){
     init();
     bool Equal = true;
     if( Print(Plus, '+') ) Equal = false;
     if( Print(Del, '-') ) Equal = false;
     if( Print(Change, '*') ) Equal = false;;
     if(Equal) printf("No changes\n");
     putchar('\n');
  }
  return 0;
}


/*

Sample Input

3
{a:3,b:4,c:10,f:6}
{a:3,c:5,d:10,ee:4}
{x:1,xyz:123456789123456789123456789}
{xyz:123456789123456789123456789,x:1}
{first:1,second:2,third:3}
{third:3,second:2}

Sample Output

+d,ee
-b,f
*c

No changes

-first

*/