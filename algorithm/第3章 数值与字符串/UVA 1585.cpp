#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, sum, cnt;
    string s;
    scanf("%d", &n);
    while (n--) {
        cin >> s;
        sum = cnt = 0;
        for (auto c : s) {
            if (c == 'X')  cnt = 0;		
            else   sum += (++cnt);
        }
        printf("%d\n", sum);
    }
    return 0;
}

/*
Sample Input

5
OOXXOXXOOO
OOXXOOXXOO
OXOXOXOXOXOXOX
OOOOOOOOOO
OOOOXOOOOXOOOOX

Sample Output
10
9
7
55
30
*/