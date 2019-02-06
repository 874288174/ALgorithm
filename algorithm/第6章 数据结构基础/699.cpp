using namespace std;

const int maxn =  1000+10;
int A[maxn], kase = 0, a;
bool ok;

void solve(int p){
   scanf("%d",&a);
   if(a != -1) {
      ok = true;
      A[p] += a;
      solve(p-1);
      solve(p+1);
   }
}

int main(){
    while(1){
        memset(A,0,sizeof(A));
        int p = maxn/2, q;
        ok = false;
        solve(p);
        if(!ok) break;
        else{
           printf("Case %d:\n",++kase);
           for(p = 0; A[p] == 0; p++);
           for(q = p+1; A[q] != 0; q++);
           for(int i = p; i < q; i++)
              if(i == p) printf("%d",A[i]);
              else printf(" %d",A[i]);
           printf("\n\n");
        }
    }
    return 0;
}