const int maxn = 1000;
string line;

int main(){
   int T, t[6], N;
   scanf("%d",&T);
   while(T--){
     int var[26] = {0};
     queue<string>pro[maxn];
     queue<int> Qstop;
     deque<int> Q;
     bool lock = false;

     scanf("%d",&N);
     for(int i = 0; i < 6; i++) scanf("%d",&t[i]);
     getchar();
     for(int i = 1; i <= N; i++){
        Q.push_back(i);
        while(getline(cin,line)){
          pro[i].push(line);
          if(line == "end") break;
        }
     }

     while(!Q.empty()){
        bool ok = false;
        int p = Q.front(), left = t[5];
        Q.pop_front();
        while(left > 0){
          line = pro[p].front();
          if(line[2] == '='){
              var[(line[0] - 'a')] = stoi(line.substr(4));
              left -= t[0];
          }
          else if(line[0] == 'p'){
              cout<<p<<": "<<(int)var[line[6]-'a']<<endl;
              left -= t[1];
          }
          else if(line[0] == 'u'){
              lock = false;
              if(!Qstop.empty()){
                  Q.push_front(Qstop.front());
                  Qstop.pop();
              }
              left -= t[3];
          }
          else if(line[0] == 'l'){
              if(!lock) {lock = true; left -= t[2];}
              else      {Qstop.push(p);ok = true;break;}
          }
          else if(line[0] == 'e'){
             left = 0;
             ok = true;
          }
          pro[p].pop();
        }
        if(!ok) Q.push_back(p);
     }
     if(T) printf("\n");
   }
   return 0;
}