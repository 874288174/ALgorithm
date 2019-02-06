#include<bits/stdc++.h>
using namespace std;

const char *S[] = {" -- is not a palindrome.\n\n",
                  " -- is a regular palindrome.\n\n",
                  " -- is a mirrored string.\n\n",
                  " -- is a mirrored palindrome.\n\n"};

char word[256], s[1000];

bool f(char a,char b){
    if(word[a] != b) return false;
    else return true;
}

int c1, c2, len;

int is_palindrome(char *s){
    int i = 0, j = len-1;
    while(i < j)
        if(s[i++] != s[j--] ) return 0;
    return 1;
}

int is_mirrored(char *s){
    int i = 0, j = len-1;
    while(i <= j)
        if( !f( s[i++], s[j--]) ) return 0;
    return 1;
}

int main(){
  memset(word,' ',sizeof(word));
  word['A'] =  'A'; word['E'] = '3'; word['H'] = 'H'; word['I'] = 'I'; word['J'] = 'L';
  word['L'] =  'J'; word['M'] = 'M'; word['O'] = 'O'; word['S'] = '2'; word['T'] = 'T';
  word['U'] =  'U'; word['V'] = 'V'; word['W'] = 'W'; word['X'] = 'X'; word['Y'] = 'Y';
  word['Z'] =  '5'; word['1'] = '1'; word['2'] = 'S'; word['3'] = 'E'; word['5'] = 'Z';
  word['8'] =  '8';
  while(scanf("%s", s) == 1){
     len = strlen(s);
     c1 = is_mirrored(s);
     c2 = is_palindrome(s);
     printf("%s%s",s, S[2*c1+c2]);
  }
  return 0;
}





/*
Sample Input

NOTAPALINDROME
ISAPALINILAPASI
2A3MEAS
ATOYOTA

Sample Output

NOTAPALINDROME -- is not a palindrome.

ISAPALINILAPASI -- is a regular palindrome.

2A3MEAS -- is a mirrored string.

ATOYOTA -- is a mirrored palindrome.

*/