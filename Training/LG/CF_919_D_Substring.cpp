#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 3e5+9, mod = 998244353;

bool ring=0;
int n,m;
int din[N],ans[30],c[N];
string s;
vector<int> e[N],tp;

int dfs(int u){

}

void toposort(){
  for(int u=1;u<=n;u++){
    if(!dfs(u))
  }
}

// void toposort(){
//   queue<int> q;
//   for(int i=1;i<=n;i++) if(din[i]==0) q.push(i);
//   while(q.size()){
//     int u=q.front();
//     q.pop();
//     tp.push_back(u);
//     for(auto v : e[u]){
//       if(--din[v]==0) q.push(v),ans[s[v-1]-'a']++;
//     }
//   }
// }

void solve(){
  cin>>n>>m>>s;
  for(int i=1;i<=m;i++){
    int v;  
    cin>>v;
    e[i].push_back(v);
    din[v]++;
  }
  toposort();
  if(!ring){
    int mx=0;
    for(int i=0;i<26;i++) mx=max(mx,ans[i]);
    cout<<mx<<'\n';
  }
  else cout<<"-1\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}