using namespace std;

struct node{
   int x, y;
}var[26];

int main(){
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        int a, b; char c;
        scanf("%c %d %d\n",&c,&a,&b);
        var[c-'A'] = {a,b};
    }
    string a;
    while(getline(cin,a) ){
        bool ok = true;
        int sum = 0;
        stack<node> S;
        for(auto i: a){
            if(isalpha(i)) S.push(var[i-'A']);
            else if(i == ')'){
                node B = S.top(); S.pop();
                node A = S.top(); S.pop();
                if(A.y != B.x){
                    printf("error\n");
                    ok = false;
                    break;
                }
                sum += (A.x *A.y * B.y);
                S.push({A.x, B.y});
            }
        }
        if(ok) printf("%d\n",sum);
    }
    return 0;
}

/*
Sample Input

9
A 50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
A
B
C
(AA)
(AB)
(AC)
(A(BC))
((AB)C)
(((((DE)F)G)H)I)
(D(E(F(G(HI)))))
((D(EF))((GH)I))


Sample Output

0
0
0
error
10000
error
3500
15000
40500
47500
15125

*/