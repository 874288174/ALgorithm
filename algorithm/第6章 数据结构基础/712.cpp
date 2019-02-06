const int maxn = 26;


int main(){
  int N, T, kase = 0;
  string s;
  while(scanf("%d",&N) == 1 && N){
     printf("S-Tree #%d:\n",++kase);
     vector<int>v;
     char d[(1 << N) + 10];
     for(int i = 0; i < N; i++){
        cin>>s;
        v.push_back( stoi( s.substr(1) ) );
     }
     scanf("%s%d",d,&T);
     while(T--){
        int ans = 0;
        cin>>s;
        for(int i = 0; i < N; i++)
            if( s[ v[i]-1 ] == '1') ans += ( 1<<(N-1-i) );
        cout<<d[ans];
     }
     cout<<endl<<endl;
  }
  return 0;
}

/*
Sample Input

3
x1 x2 x3
00000111
4
000 010 111 110
3
x3 x1 x2
00010011
4
000 010 111 110
0

Sample Output

S-Tree #1:
0011

S-Tree #2:
0011

*/