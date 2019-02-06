#include<bits/stdc++.h>
using namespace std;

char w[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(){
  char c;
  while((c = getchar()) != EOF){
     char *p = w;
     while(*p != '\0' && *(p+1) != c) p++;
     if(*p != '\0') putchar(*p);
     else putchar(c);
  }
  return 0;
}


/*
Sample Input

O S, GOMR YPFSU/

Sample Output

I AM FINE TODAY.

*/