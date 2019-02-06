#include<bits/stdc++.h>
using namespace std;

char s[100];

double w(char c){
   switch(c){
      case 'C' : return 12.01;
      case 'H' : return 1.008;
      case 'O' : return 16.00;
      case 'N' : return 14.01;
   }
}

double Weight(char *p, char *q){
   int cnt = 0;
   for(auto k = p+1; k < q; k++)
      cnt = cnt*10 + *k - '0';
   return w(*p) * (cnt ? cnt : 1);
}

int main(){
   int n;
   scanf("%d",&n);
   while(n--){
      scanf("%s",s);
      char *p = s, *q = s+1;
      double sum = 0;
      while(*p != '\0'){
         while(*q != '\0' && isdigit(*q) ) q++;
         sum += Weight(p, q);
         p = q++;
      }
      printf("%.3f\n",sum);
   }
   return 0;
}


/*

Sample Input

4
C
C6H5OH
NH2CH2COOH
C12H22O11

Sample Output
12.010
94.108
75.070
342.296


*/