#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5, maxc = 180 + 5;
vector< vector<string> >v(maxn);
vector< int > len(maxc);

void Print(string s, int length){
    length -= (s.length() -1);
    cout << s;
    while(length--) putchar(' ');
}

int main() {
  string buf, s;
  int i = 0, j;
  fill(len.begin(), len.end(), 0);
  while( getline(cin, buf) ){
     stringstream ss(buf);
     j = 0;
     while(ss >> s){
        v[i].push_back(s);
        len[j] = max(len[j], (int)s.length());
        j++;
     }
     i++;
  }
  for(int k = 0; k < i; k++){
     for(int t = 0; t < v[k].size(); t++)
       if(t != v[k].size() - 1 ) Print(v[k][t],len[t]);
       else cout << v[k][t] << endl;
  }
  return 0;
}




/*
Sample Input

  start:  integer;    // begins here
stop: integer; //  ends here
 s:  string;
c:   char; // temp


Sample Output

start: integer; // begins here
stop:  integer; // ends   here
s:     string;
c:     char;    // temp

*/