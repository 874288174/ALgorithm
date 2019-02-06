#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int main() {
    double M[20][40];
    long long E[20][40];
    for(int i = 0; i <= 9; ++i) for(int j = 1; j <= 30; ++j) {
        double m = 1 - pow(2, -1 - i), e = pow(2, j) - 1, t = log10(m) + e * log10(2);
        E[i][j] = t, M[i][j] = pow(10, t - E[i][j]);
    }
    string in;
    while(cin >> in && in != "0e0") {
        for(auto i = in.begin(); i != in.end(); ++i) if(*i == 'e') *i = ' ';
        stringstream ss(in);
        double A; int B;
        ss >> A >> B;
        while(A < 1) A *= 10, B -= 1;
        for(int i = 0; i < 10; ++i) for(int j = 1; j <= 30; ++j) {
            if(B == E[i][j] && (fabs(A - M[i][j]) < 1e-4 || fabs(A / 10 - M[i][j]) < 1e-4)) {
                cout << i << ' ' << j << endl;
                break;
            }
        }
    }
    return 0;
}



/*
Sample Input

5.699141892149156e76
9.205357638345294e18
0e0

Sample Output

5 8
8 6

*/