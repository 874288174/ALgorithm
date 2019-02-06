
const int maxn = 32;
int buf[maxn][maxn], ans;

void print(int x0, int y0, int x1, int y1){
   char c = getchar();
   if(c == 'p'){
      int len = (x1 - x0) / 2;
      print(x0+len,y0,x1,y1-len);
      print(x0,y0,x1-len,y1-len);
      print(x0,y0+len,x1-len,y1);
      print(x0+len,y0+len,x1,y1);
   }
   else if(c == 'f') {
       for(int i = x0; i < x1; i++)
          for(int j = y0; j < y1; j++){
             if(!buf[i][j]) ans++;
             buf[i][j] = 1;
          }
   }
}

int main(){
    int N;
    scanf("%d\n",&N);
    while(N--){
       ans = 0;
       memset(buf,0,sizeof(buf));
       print(0,0,32,32);
       getchar();
       print(0,0,32,32);
       getchar();
       printf("There are %d black pixels.\n",ans);
    }
    return 0;
}