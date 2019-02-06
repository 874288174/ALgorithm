bool ok;

int solve(){
   int wl,dl,wr,dr;
   scanf("%d%d%d%d",&wl,&dl,&wr,&dr);
   if(!wl) wl = solve();
   if(!wr) wr = solve();
   if(wl * dl != wr * dr) ok = false;
   return wl+wr;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
       ok = true;
       solve();
       if(ok) printf("YES\n");
       else printf("NO\n");
       if(T) putchar('\n');
    }
    return 0;
}

/*
Sample Input

1
0 2 0 4
0 3 0 1
1 1 1 1
2 4 4 2
1 6 3 2


Sample Output

Yes

*/