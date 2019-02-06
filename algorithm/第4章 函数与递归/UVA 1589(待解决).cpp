/*

                             WA

*/
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int>  PII;
const int G_dx[] = {1, -1, 0, 0};
const int G_dy[] = {0, 0, 1, -1};
const int H_dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
const int H_dy[] = {1, -1, 1, -1, 2, 2, -2, -2};
bool Chess[11][10];
int N, x, y;
vector< PII > H, R, C, G;

void init(){
   getchar();
   H.clear(), R.clear(), C.clear(), G.clear();
   memset(Chess, false, sizeof(Chess));
}

bool G_inside(int x, int y){
   if(x < 1 || x > 3 || y < 4 || y > 6) return false;
   else return true;
}


int Get_num(PII T, PII GB){
   if(T == GB) return -1;     //被吃掉了
   else if(T.second == GB.second){
      int y = GB.second, cnt = 0;
      for(int x = min(GB.first, T.first)+1; x < min(GB.first, T.first); x++) if( Chess[x][y] ){
          cnt++;
      }
      return cnt;
   }
   else if(T.first == GB.first){
      int x = GB.first, cnt = 0;
      for(int y = min(GB.second, T.second)+1; y < max(GB.second, T.second); y++) if( Chess[x][y] ){
          cnt++;
      }
      return cnt;
   }
   return -1;
}


bool Judge( PII GB ){
   for(auto &r : R){            //判断车与红方将军是否把黑方将死
      if(  Get_num(r, GB) == 0)
         return true;
   }

   for(auto &c : C){        //判断炮是否把黑方将死
      if(  Get_num(c, GB) == 1)
         return true;
   }

   for(auto &h : H) for(int i = 0; i < 8; i++){       //判断马是否把黑方将死
      if( h.first+H_dx[i] == GB.first && h.second+H_dy[i] == GB.second && !Chess[h.first+G_dx[i/2]][h.second+G_dy[i/2]] )
         return true;
   }
   return false;
}

int main(){
   while( cin >> N >> x>> y && N){
      init();
      for(int i = 0; i < 4; i++){
         int xx = x+G_dx[i], yy = y+G_dy[i];
         if( G_inside(xx, yy) ) G.push_back( make_pair(xx, yy) );
      }
      while(N--){
         char c;
         cin >> c>> x >> y;
         getchar();
         Chess[x][y] = true;
         PII t = make_pair(x, y);
         if(c == 'R' || c == 'G')  R.push_back( t ); //chariot or general
         else if(c == 'H')  H.push_back( t ); //horse
         else    C.push_back( t );            //cannon
      }

      bool ok = true;
      for(auto &i : G) if( !Judge(i) ){
          ok = false;
          break;
      }

      if(!ok) cout << "NO\n";
      else cout << "YES\n";
   }
   return 0;
}

/*

Sample Input


2 1 4
G 10 5
R 6 4

3 1 5
H 4 5
G 10 5
C 7 5

0 0 0

Sample Output

YES
NO

*/