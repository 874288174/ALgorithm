#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

const int  maxn = 100 + 5, maxx = 1500 + 5;
string Line[maxn][maxx];
map< string, set<int> > M[maxn];
map< string, set<int> > paper;
set< int >U;
bool ok;

void findA(string s){
   for(auto it = paper[s].begin(); it != paper[s].end(); it++){
       for(auto ip = M[*it][s].begin(); ip != M[*it][s].end(); ip++) {ok = true; cout<<Line[*it][*ip]<<endl;}
       if(it != prev(paper[s].end() )) printf("----------\n");
       else printf("==========\n");
   }
}

void findnotA(string s){
   set<int>S, x = paper[s];
   set_difference(ALL(U), ALL(x), INS(S));
   for(auto it = S.begin(); it != S.end(); it++){
       for(auto ip = Line[*it]; *ip != ""; ip++) {ok = true; cout<<*ip<<endl;}
       if(it != prev(S.end() )) printf("----------\n");
       else printf("==========\n");
   }
}

void findAandB(string s1,string s2){
    set<int> S, x = paper[s1], y = paper[s2];
    set_intersection(ALL(x), ALL(y), INS(S));
    for(auto it = S.begin(); it != S.end(); it++){
       set< int >S1;
       set_union(ALL(M[*it][s1]), ALL(M[*it][s2]), INS(S1));
       for(auto ip = S1.begin(); ip != S1.end(); ip++) {ok = true; cout<<Line[*it][*ip]<<endl;}
       if(it != prev(S.end() )) printf("----------\n");
       else printf("==========\n");
    }
}

void findAorB(string s1, string s2){
    set<int>S, S1, x = paper[s1], y = paper[s2];
    set_union(ALL(x), ALL(y), INS(S));
    for(auto it = S.begin(); it != S.end(); it++){
       set<int>S1;
       set_union(ALL(M[*it][s1]), ALL(M[*it][s2]), INS(S1));
       for(auto ip = S1.begin(); ip != S1.end(); ip++) {ok = true; cout<<Line[*it][*ip]<<endl;}
       if(it != prev(S.end() )) printf("----------\n");
       else printf("==========\n");
    }
}



int main(){
   int T, N;
   scanf("%d", &T);
   getchar();
   for(int t = 0; t < T; t++){
      U.insert(t);
      for(int i = 0;; i++){
         string line, s;
         getline(cin, line);
         if( line == "**********" ) break;
         Line[t][i] = line;
         for(auto &p : line){
            if(isalpha(p)) p = tolower(p);
            else p = ' ';
         }
         stringstream ss(line);
         while(ss >> s){
            M[t][s].insert(i);
            paper[s].insert(t);
         }
      }
   }
   scanf("%d\n", &N);
   for(int t = 0; t < N; t++){
       ok = false;
       string s1, s2;
       getline(cin, s1);
       int p = s1.find('A'), q = s1.find('O');
       if(s1[0] == 'N')  findnotA(s1.substr(4));
       else if(p == string::npos && q == string::npos) findA(s1);
       else if(s1[p] == 'A') findAandB(s1.substr(p+4),s1.substr(0,p-1));
       else  findAorB(s1.substr(q+3),s1.substr(0,q-1));
       if(!ok) printf("Sorry, I found nothing.\n==========\n");
   }
   return 0;
}

/*
Sample Input

4
A manufacturer, importer, or seller of
digital media devices may not (1) sell,
or offer for sale, in interstate commerce,
or (2) cause to be transported in, or in a
manner affecting, interstate commerce,
a digital media device unless the device
includes and utilizes standard security
technologies that adhere to the security
system standards.
**********
Of course, Lisa did not necessarily
intend to read his books. She might
want the computer only to write her
midterm. But Dan knew she came from
a middle-class family and could hardly
afford the tuition, let alone her reading
fees. Books might be the only way she
could graduate
**********
Research in analysis (i.e., the evaluation
of the strengths and weaknesses of
computer system) is essential to the
development of effective security, both
for works protected by copyright law
and for information in general. Such
research can progress only through the
open publication and exchange of
complete scientific results
**********
I am very very very happy!
What about you?
**********
10
computer
books AND computer
books OR protected
NOT security
very
slick

Sample Output

want the computer only to write her
--------
computer system) is essential to the
==========
intend to read his books. She might
want the computer only to write her
fees. Books might be the only way she
==========
intend to read his books. She might
fees. Books might be the only way she
--------
for works protected by copyright law
==========
Of course, Lisa did not necessarily
intend to read his books. She might
want the computer only to write her
midterm. But Dan knew she came from
a middle-class family and could hardly
afford the tuition, let alone her reading
fees. Books might be the only way she
could graduate
--------
I am very very very happy!
What about you?
==========
I am very very very happy!
==========
Sorry, I found nothing.
==========
*/