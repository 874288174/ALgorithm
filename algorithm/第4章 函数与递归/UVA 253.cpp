#include<bits/stdc++.h>
using namespace std;

int newcolor[24][6] = {
   {1,2,3,4,5,6},
   {1,3,5,2,4,6},
   {1,4,2,5,3,6},
   {1,5,4,3,2,6},
   {2,1,4,3,6,5},
   {2,3,1,6,4,5},
   {2,4,6,1,3,5},
   {2,6,3,4,1,5},
   {3,1,2,5,6,4},
   {3,2,6,1,5,4},
   {3,5,1,6,2,4},
   {3,6,5,2,1,4},
   {4,1,5,2,6,3},
   {4,2,1,6,5,3},
   {4,5,6,1,2,3},
   {4,6,2,5,1,3},
   {5,1,3,4,6,2},
   {5,3,6,1,4,2},
   {5,4,1,6,3,2},
   {5,6,4,3,1,2},
   {6,2,4,3,5,1},
   {6,3,2,5,4,1},
   {6,4,5,2,3,1},
   {6,5,3,4,2,1},
};

string s;

bool painting(string s){
    string s1 = s.substr(0,6), s2 = s.substr(6,6);
    for(int i = 0; i < 24; i++){
        bool ok = true;
        for(int j = 0; j < 6; j++)
            if(s1[ newcolor[i][j] - 1 ] != s2[j])  {ok = false; break;}
        if(ok) return true;
    }
    return false;
}

int main(){
    while(cin >> s){
        if( painting(s) ) printf("TRUE\n");
        else printf("FALSE\n");
    }
    return 0;
}



/*
Sample Input

rbgggrrggbgr
rrrbbbrrbbbr
rbgrbgrrrrrg

Sample Output

TRUE
FALSE
FALSE

*/