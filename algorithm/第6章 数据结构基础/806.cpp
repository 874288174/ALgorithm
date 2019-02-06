const int maxn = 64 + 2;
char S[maxn][maxn];
int N;
vector<int> v;

int check(int x0, int y0, int x1, int y1){
   int flag1 = 0, flag2 = 0;
   for(int i = x0; i < x1; i++)
        for(int j = y0; j < y1; j++)
           if(S[i][j] == '1') flag1 = 1;
           else if(S[i][j] == '0') flag2 = 1;
  return 2*flag1+flag2;
}

void f(int x0, int y0, int x1, int y1, int num,int d){
    int len = (x1 -x0)/2;
    int k = check(x0,y0,x1,y1);
    if(k == 2) v.push_back(num);
    else if(k == 3){
        int t = pow(5,d)+0.5;
        f(x0,y0,x1-len,y1-len,num + t,d+1);
        f(x0,y0+len,x1-len,y1,num + 2*t,d+1);
        f(x0+len,y0,x1,y1-len,num + 3*t,d+1);
        f(x0+len,y0+len,x1,y1,num + 4*t,d+1);
    }
    return ;
}


void read_matrix(){
   for(int i = 0; i < N; i++) scanf("%s",S[i]);
   v.clear();
   f(0,0,N,N,0,0);
   sort(v.begin(),v.end());
   for(int i = 0; i < (int)v.size(); i++){
       printf("%d",v[i]);
       if(i % 12 == 11 || i == (int)v.size() -1 ) putchar('\n');
       else putchar(' ');
   }
   printf("Total number of black nodes = %d\n",v.size());
   return ;
}

void color(int x0, int y0, int x1, int y1){
   for(int i = x0; i < x1; i++)
        for(int j = y0; j < y1; j++)
            S[i][j] = '*';
}

void read_num(){
   memset(S,'.',sizeof(S));
   N = -N;
   int num;
   while(scanf("%d",&num) == 1 && num != -1){
      int x0 = 0, y0 = 0, x1 = N, y1 = N;
      while(num > 0){
        int t = num % 5, len = (x1 - x0)/2;
        if(t == 1)     {x1 -= len; y1 -= len;}
        else if(t == 2){y0 += len; x1 -= len;}
        else if(t == 3){x0 += len; y1 -= len;}
        else           {x0 += len; y0 += len;}
        num = num / 5;
      }
      color(x0,y0,x1,y1);
   }
   for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            printf("%c",S[i][j]);
        putchar('\n');
   }
   return ;
}


int main(){
  int kase = 0;
  while( scanf("%d",&N) == 1 && N ){
     if(kase > 0) putchar('\n');
     printf("Image %d\n",++kase);
     if(N > 0) read_matrix();
     else read_num();
  }
  return 0;
}

/*
Sample Input

8
00000000
00000000
00001111
00001111
00011111
00111111
00111100
00111000
-8
9 14 17 22 23 44 63 69 88 94 113 -1
2
00
00
-4
0 -1
0

Sample Output

Image 1
9 14 17 22 23 44 63 69 88 94 113
Total number of black nodes = 11

Image 2
........
........
....****
....****
...*****
..******
..****..
..***...

Image 3
Total number of black nodes = 0

Image 4
****
****
****
****

*/