#include<bits/stdc++.h>
using namespace std;

const int maxn = 80+5;

struct node{
   string book, author;
   bool operator < (const node & rhs) const{
      return author < rhs.author || (author == rhs.author && book < rhs.book);
   }
};
vector< node > v;
set< int > bookself, temp;
unordered_map< string, int > booktoid;
unordered_map< int, string > idtobook;

bool read(){
   string s;
   getline(cin, s);
   if(s == "END") return false;
   int p = s.find('"',1);
   v.push_back( {s.substr(0,p+1),s.substr(p+5)} );
   return true;
}

bool option(){
   string s;
   getline(cin, s);
   if(s == "END") return false;
   if(s[0] == 'S'){
       while( !temp.empty() ){
           int bookid = *temp.begin();
           cout << "Put " << idtobook[bookid] << " ";
           temp.erase( temp.begin() );
           bookself.insert( bookid );
           auto p = bookself.find(bookid);
           if(p == bookself.begin()) printf("first\n");
           else cout << "after "<< idtobook[ *prev(p) ] << endl;
       }
       printf("END\n");
   }
   else{
       int bookid = booktoid[s.substr(7)];
       if(s[0] == 'B')  bookself.erase(bookid);
       else temp.insert(bookid);
   }
   return true;
}

int main(){
   while( read() );
   sort(v.begin(), v.end());
   for(int i = 0; i < v.size(); i++){
      booktoid[ v[i].book ] = i;
      idtobook[ i ] = v[i].book;
      bookself.insert(i);
   }
   while(option());
   return 0;
}

/*
Sample Input

"The Canterbury Tales" by Chaucer, G.
"Algorithms" by Sedgewick, R.
"The C Programming Language" by Kernighan, B. and Ritchie, D.
END
BORROW "Algorithms"
BORROW "The C Programming Language"
RETURN "Algorithms"
RETURN "The C Programming Language"
SHELVE
END


Sample Output

Put "The C Programming Language" after "The Canterbury Tales"
Put "Algorithms" after "The C Programming Language"
END

*/