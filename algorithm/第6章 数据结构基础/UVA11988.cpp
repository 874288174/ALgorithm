const int maxn = 100000+10;
char s[maxn];
int order[maxn];

int main(){
    while(scanf("%s",s+1) == 1){
        int len = strlen(s+1), End = 0, cur = 0;
        order[0] = 0;
        for(int i = 1; i <= len; i++){
            if(s[i] == '[')   cur = 0;
            else if(s[i] == ']') cur = End;
            else {
                if(cur == End) End = i;
                order[i] = order[cur];
                order[cur] = i;
                cur = i;
            }
        }
        for(int i = order[0]; i != 0; i = order[i])
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}

/*
Sample Input

This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University


Sample Output

BeijuThis_is_a__text
Happy_Birthday_to_Tsinghua_University

*/