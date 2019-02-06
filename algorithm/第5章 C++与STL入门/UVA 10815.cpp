#include<bits/stdc++.h>
using namespace std;

set<string>my_set;

int main(){
   string s, buf;
   while(cin >> s){
      int len = s.length();
      for(int i = 0; i < len; i++){
          if(isalpha(s[i])) s[i] = tolower(s[i]); 
          else s[i] = ' ';
       }
      stringstream ss(s);
      while(ss >> buf) my_set.insert(buf);
   }
   for(auto & i: my_set) cout << i << endl;
   return 0;
}


/*
Sample Input

Adventures in Disneyland

Two blondes were going to Disneyland when they came to a fork in the road. The sign read: "Disneyland Left."

So they went home.


Sample Output

a adventures blondes came disneyland fork going home in left read road sign so the they to two went were when

*/