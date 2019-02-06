const int maxn = 26;


int main(){
  int T;
  scanf("%d\n",&T);
  while(T--){
     string s;
     getline(cin,s);
     stack<char>S;
     bool ok = true;
     for(auto i:s){
        if(i == '(' || i == '[') S.push(i);
        else{
            if(S.empty()) {ok = false; break;}
            char c = S.top(); S.pop();
            if( (c == '[' && i == ']')  || (c == '(' && i == ')') ) continue;
            else {ok = false; break;}
        }
     }
     if(ok && S.empty()) cout<<"Yes\n";
     else cout<<"No\n";

  }
  return 0;
}

/*
Sample Input

3
([])
(([()])))
([()[]()])()

Sample Output

Yes
No
Yes

*/
