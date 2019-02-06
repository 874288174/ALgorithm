const int inf = 999999;
vector<int>in, post;
int n, minn, leaf;

bool write(vector<int> &v){
   v.clear();
   string s;
   int x;
   if( !getline(cin,s) ) return false;
   stringstream ss(s);
   while(ss>>x) v.push_back(x);
   return true;
}

void solve(int inl, int inr, int postr,int v){
   if(inl == inr){
        v += in[inl];
        if(v < minn || (v == minn && in[inl] < leaf )) {
            minn = v; leaf = in[inl];
        }
        return;
   }
   if(inl > inr) return;
   int i = inl;
   while(in[i] != post[postr]) i++;
   solve(i+1,inr,postr-1,v+in[i]);
   solve(inl,i-1,postr+i-1-inr,v+in[i]);
}

int main(){
    while(1){
       minn = leaf = inf;
       if( !write(in) || !write(post)) break;
       n = in.size();
       solve(0,n-1,n-1,0);
       cout<<leaf<<endl;
    }
    return 0;
}