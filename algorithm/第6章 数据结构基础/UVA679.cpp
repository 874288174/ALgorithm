const int maxn = 100000+10;


int main(){
    int n;
    while(scanf("%d",&n) == 1 && n != -1){
        while(n--){
            int D, I;
            scanf("%d%d",&D,&I);
            int start = 1<<(D-1);
            while(--D){
                if( !(I%2) ) start += (1<<D)/2;
                I = (I+1) / 2;
            }
            cout<<start<<endl;
        }
    }
    return 0;
}

/*
Sample Input

5
4 2
3 4
10 1
2 2
16 2
-1


Sample Output

12
7
512
3
255

*/