#include<bits/stdc++.h>
using namespace std;

void Print(unsigned int net){
   cout << ( (net&0xff000000)>>24 ) << '.' << ( (net&0x00ff0000)>>16)<<'.'
        << ( (net&0x0000ff00)>>8 ) << '.'
        << ( (net&0x000000ff) ) << endl;
}

int main(){
  int n, a[4];
  while(scanf("%d",&n) == 1){
    long long ip, IP;
    int u[32+2] = {0};
    for(int i = 0; i < n; i++){
        scanf("%d.%d.%d.%d",&a[0], &a[1], &a[2], &a[3]);
        ip = a[0]<<24 | a[1]<<16 | a[2]<<8 | a[3];
        IP = ip;
        for(int i = 0; i < 32; i++){
            if(ip & 1) u[i]++ ;
            ip >>= 1;
        }
    }
    int  Move = 0;
    for(int i = 31; i >= 0; i--)
        if(u[i] != n && u[i] != 0) { Move = i+1; break;}
    Print( (IP>>Move)<<Move );
    Print( (0xfffffffff>>Move)<<Move );
  }
  return 0;
}



//////////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;


void Print(unsigned int net){
   cout << ( (net&0xff000000)>>24 ) << '.' << ( (net&0x00ff0000)>>16)<<'.'
        << ( (net&0x0000ff00)>>8 ) << '.'
        << ( (net&0x000000ff) ) << endl;
}

int main(){
  int n, a[4];
  int i = 0;
  while(scanf("%d",&n) == 1){
    unsigned int maxip = 0, minip = i - 1, ip;
    for(int i = 0; i < n; i++){
        scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
        ip = a[0]<<24 | a[1]<<16 | a[2]<<8 | a[3];
        maxip = max(ip, maxip);
        minip = min(ip, minip);

    }
    unsigned int networkmask = minip ^ (~maxip);
    int flag = 1;
    for(int i = 31; i > -1; i--){
        if(flag && (1<<i) & networkmask) continue;
        else flag = 0;
        if((1<<i) & networkmask) networkmask -= (1<<i);
    }
    Print(networkmask & minip);
    Print(networkmask);
  }
  return 0;
}




/*
Sample Input

3
194.85.160.177
194.85.160.183
194.85.160.178

Sample Output

194.85.160.176
255.255.255.248

*/



