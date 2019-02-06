string in, pre;
void post(int inl,int inr, int prel){
   if(inl > inr) return;
   int i = inl;
   while(in[i] != pre[prel]) i++;
   post(inl,i-1,prel+1);
   post(i+1,inr,prel+i+1-inl);
   cout<<pre[prel];
   return;
}

int main(){
  while(cin>>pre>>in){
     int n = in.length();
     post(0,n-1,0);
     putchar('\n');
  }
  return 0;
}