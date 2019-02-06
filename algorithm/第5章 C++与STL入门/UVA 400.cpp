#include<bits/stdc++.h>
using namespace std;

int N, M;
string s;
vector<string>v;

bool read_input(){
   if(scanf("%d",&N) == 1 && !N) return false;
   M = 0;
   v.clear();
   for(int i = 0; i < N; i++){
       cin >> s;
       M = max(M, (int)s.length());
       v.push_back(s);
   }
   return true;
}


void Print(string s,int Size){
   Size -= s.length();
   cout << s;
   while(Size--) putchar(' ');
}

int main() {
  while( read_input() ){
      printf("------------------------------------------------------------\n");
      int cols = (60-M) / (M+2) + 1, rows = (N-1) / cols + 1;
      for(int r = 0; r < rows; r++){
         for(int c = 0; c < cols; c++){
           int t = rows*c + r;
           if(t < N) Print(v[t], (c == cols - 1 ? M: M+2) );
         }
         putchar('\n');
      }
  }
  return 0;
}




/*
Sample Input

10
tiny
2short4me
very_long_file_name
shorter
size-1
size2
size3
much_longer_name
12345678.123
mid_size_name
12
Weaser
Alfalfa
Stimey
Buckwheat
Porky
Joe
Darla
Cotton
Butch
Froggy
Mrs_Crabapple
P.D.
19
Mr._French
Jody
Buffy
Sissy
Keith
Danny
Lori
Chris
Shirley
Marsha
Jan
Cindy
Carol
Mike
Greg
Peter
Bobby
Alice
Ruben

Sample Output

-----------------------------------------------------------
12345678.123 size-1
2short4me size2
mid_size_name size3
much_longer_name tiny
shorter very_long_file_name
-----------------------------------------------------------
Alfalfa Cotton Joe Porky
Buckwheat Darla Mrs_Crabapple Stimey
Butch Froggy P.D. Weaser
-----------------------------------------------------------
Alice Chris Jan Marsha Ruben
Bobby Cindy Jody Mike Shirley
Buffy Danny Keith Mr._French Sissy
Carol Greg Lori Peter

*/