const int maxn = 26;
int G[maxn][maxn],temp[maxn][maxn],zero[maxn][maxn] = {0};
set<int>s;

void dfs(int i){
   for(int j = 0; j < 26; j++)
      if(temp[i][j]){
         temp[i][j]--;
         dfs(j);
      }
}

int main(){
  int T, N;
  scanf("%d",&T);
  while(T--){
      fill(G[0],G[0]+maxn*maxn,0);
      s.clear();
      scanf("%d",&N);
      for(int i = 0; i < N; i++){
          string word;
          cin>>word;
          G[*word.begin() - 'a'][*word.rbegin() - 'a']++;
          s.insert(*word.begin() - 'a');
      }

      bool ok = false;
      for(auto i : s){
         memcpy(temp,G,sizeof(G));
         dfs(i);
         if(memcmp(temp,zero,sizeof(temp)) == 0){
             ok = true; break;
         }
      }
      if(!ok) printf("The door cannot be opened.\n");
      else  printf("Ordering is possible.\n");
  }
  return 0;
}





///////////////////////////////////////////////


// UVa10129 Play on Words
// Rujia Liu
// ���⣺����n�����ʣ��Ƿ�����ų�һ�����У�ʹ��ÿ�����ʵĵ�һ����ĸ����һ�����ʵ����һ����ĸ��ͬ
// �㷨������ĸ������㣬���ʿ�������ߣ����н⵱�ҽ���ͼ����ŷ��·����ע��Ҫ������ͨ
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxn = 1000 + 5;

// ���鼯������ժ�ԡ��㷨�������ž��䡪��ѵ��ָ�ϡ������£�
int pa[256];
int findset(int x) { return pa[x] != x ? pa[x] = findset(pa[x]) : x; } 

int used[256], deg[256]; // �Ƿ���ֹ�������

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n;
    char word[maxn];

    scanf("%d", &n);
    memset(used, 0, sizeof(used));
    memset(deg, 0, sizeof(deg));
    for(int ch = 'a'; ch <= 'z'; ch++) pa[ch] = ch; // ��ʼ�����鼯
    int cc = 26; // ��ͨ�����

    for(int i = 0; i < n; i++) {
      scanf("%s", word);
      char c1 = word[0], c2 = word[strlen(word)-1];
      deg[c1]++;
      deg[c2]--;
      used[c1] = used[c2] = 1;
      int s1 = findset(c1), s2 = findset(c2);
      if(s1 != s2) { pa[s1] = s2; cc--; }
    }

    vector<int> d;
    for(int ch = 'a'; ch <= 'z'; ch++) {
      if(!used[ch]) cc--; // û���ֹ�����ĸ
      else if(deg[ch] != 0) d.push_back(deg[ch]);
    }
    bool ok = false;
    if(cc == 1 && (d.empty() || (d.size() == 2 && (d[0] == 1 || d[0] == -1)))) ok = true;
    if(ok) printf("Ordering is possible.\n");
    else printf("The door cannot be opened.\n");
  }
  return 0;
}