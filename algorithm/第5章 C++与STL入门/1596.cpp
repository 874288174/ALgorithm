#include<bits/stdc++.h>
using namespace std;


const int maxn = 10000+5;
unordered_map< string, int> Array_Id;
unordered_map< int, int > Array_Size;
unordered_map< int, int > My_Set[maxn];
bool ok;

int Get_Id(string s){
    if( !Array_Id.count(s) ) Array_Id[s] = (int)Array_Id.size();
    return Array_Id[s];
}

int f(string s, int option, int value, int cnt){ //0代表数组定义 1代表赋值左边 2代表赋值右边  // cnt代表第几层【】
   int p = s.find('[');
   if(p == string::npos) return stoi(s);
   else{
      int id = Get_Id( s.substr(0,p) );
      int Index = f(s.substr(p+1,s.length()-p-2), option, value, cnt+1);
      if( ( (option == 2 || cnt) ) && !My_Set[id].count(Index) ) ok = false;
      else if( (option != 1 || cnt) && My_Set[id].count(Index) ) return My_Set[id][Index];
      else if( option == 1 && !cnt){
         if(Array_Size[id] > Index) My_Set[id][Index] = value;
         else ok = false;
      }
      else if(!option && !cnt) Array_Size[id] = Index;
   }
}

int main(){
   string s, s1, s2;
   while( cin >> s && s[0] != '.'){
      Array_Id.clear();
      Array_Size.clear();
      for(int i = 0; i < maxn; i++) My_Set[i].clear();
      ok = true;
      int cnt = 0;
      do{
          if( !ok )  continue;
          cnt++;
          int p = s.find('=');
          s1 = s.substr(0,p);
          if(p == string::npos) f(s1,0,0,0);
          else{
             s2 = s.substr(p+1);
             int value = f(s2,2,0,0); if( !ok )  continue;
             f(s1,1,value,0);
          }
      }while( cin >> s && s[0] != '.');
      cout << (ok ? 0 : cnt) << endl;
   }
   return 0;
}



/*


a[3]
a[0]=a[1]
.
x[1]
x[0]=x[0]
.
a[0]
a[0]=1
.
b[2]
b[0]=2
b[1]=b[b[0]]
b[0]=b[1]
.
g[2]
G[10]
g[0]=0
g[1]=G[0]
.
a[2147483647]
a[0]=1
B[2]
B[a[0]]=2
a[B[a[0]]]=3
a[2147483646]=a[2]
.
.

Sample Output

2
2
2
3
4
0


*/