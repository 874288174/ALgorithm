#include<bits/stdc++.h>
using namespace std;

const int MAXN = 80+5;
string Alpha[256];
map<string, string> My_map; //完全匹配
vector< string > v[MAXN]; // 不完全匹配
string None = "";

bool read_alpha() {
    char c;
    scanf("%c", &c);
    if(c == '*') return false;
    string s;
    cin >> s;
    getchar();
    Alpha[ (int)c  ] = s;
    return true;
}

bool read_word() {
    string s, a = "";
    cin >> s;
    getchar();
    if(None == "") None = s;
    if(s == "*") return false;
    for(auto &i : s) a += Alpha[ (int)i ];
    v[ a.length() ].push_back(a);
    if( !My_map.count(a) ) My_map[a] = s;
    else if( My_map.count(a) && *My_map[a].rbegin() != '!' ) My_map[a] += '!';
    return true;
}

bool read_Morse() {
    string s;
    cin >> s;
    if(s == "*") return false;
    if( My_map.count(s) ){
        cout << My_map[s] << endl;
        return true;
    }
    else for(int t = 1;; t++){
       string Ans = "~";                   //找一个ascii大一点的
       for(int i = 0; i < 2; i++){
          int j = s.length()+(i ? 1 : -1)*t;
          if(j > MAXN || j < 0) continue;
          for(auto k : v[j]){
            auto a = k, b = s;
            if(a.length() > b.length() ) swap(a, b);  // 使b比a长
            if( b.substr(0, a.length()) == a ){
               Ans = min(My_map[k], Ans);
               if(*Ans.rbegin() == '!') Ans = Ans.erase(Ans.length()-1 ,1);
            }
          }
       }
       if(Ans != "~"){
          cout << Ans << "?\n";
          return true;
       }
    }
    cout << None << "?\n";
    return true;
}

int main(){
   while( read_alpha() );
   while( read_word() );
   while( read_Morse() );
   return 0;
}


/*

A .-
B -...
C -.-.
D -..
E .
F ..-.
G --.
H ....
I ..
J .---
K -.-
L .-..
M --
N -.
O ---
P .--.
Q --.-
R .-.
S ...
T -
U ..-
V ...-
W .--
X -..-
Y -.--
Z --..
0 -----
1 .----
2 ..---
3 ...--
4 ....-
5 .....
6 -....
7 --...
8 ---..
9 ----.
*
AN
EARTHQUAKE
EAT
GOD
HATH
IM
READY
TO
WHAT
WROTH
*
.--.....--   .....--....
--.----..   .--.-.----..
.--.....--   .--.
..-.-.-....--.-..-.--.-.
..--   .-...--..-.--
----        ..--
*

Sample Output
WHAT
HATH
GOD
WROTH?
WHAT
AN
EARTHQUAKE
EAT!
READY
TO
EAT!

*/