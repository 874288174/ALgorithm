#include<bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
char buf[maxn];
int main(){
  int flag = 1;
  while( fgets(buf,maxn,stdin) ){
     int len = strlen(buf);
     for(int i = 0; i < len; i++){
        if(buf[i] == '"' && flag) {
            printf("``"); flag = !flag;
        }
        else if(buf[i] == '"' && !flag){
            printf("''"); flag = !flag;
        }
        else printf("%c",buf[i]);
     }
  }
  return 0;
}



/*
Sample Input

"To be or not to be," quoth the Bard, "that
is the question".
The programming contestant replied: "I must disagree.
To `C' or not to `C', that is The Question!"

Sample Output

``To be or not to be,'' quoth the Bard, ``that
is the question''.
The programming contestant replied: ``I must disagree.
To `C' or not to `C', that is The Question!''

*/