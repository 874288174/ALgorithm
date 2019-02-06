using namespace std;


int main(){
    int N, a, p, q;
    while(scanf("%d",&N) == 1 && N){
       while(1){
          vector<int>v;
          scanf("%d",&a);
          if(!a) break;
          v.push_back(a);
          for(int i = 1; i < N; i++){
              scanf("%d",&a);
              v.push_back(a);
          }
          stack<int>S;
          p = 0, q = 1;
          while(1){
              if(S.empty() || S.top() != v[p]) S.push(q++);
              else{
                  S.pop();
                  p++;
              }
              if(p == N) {printf("Yes\n"); break;}
              if(q == N+2) {printf("No\n"); break;}
          }
       }
       printf("\n");
    }
    return 0;
}