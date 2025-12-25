#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int n;
int din[N],vis[N];
vector<int> e[N],tp,pos;

void toposort(){
  queue<int> q;
  for(auto u : pos) if(!din[u]) q.push(u);
  while(q.size()){
    int u=q.front(); q.pop();
    tp.push_back(u);
    for(auto v : e[u]){
      if(--din[v]==0&&vis[v]) q.push(v);
    }
  }
}

void solve(){
	cin>>n;
  for(int i=1;i<=n;i++){
    int u,m;
    cin>>u>>m;
    vis[u]=1;
    pos.push_back(u);
    for(int j=1;j<=m;j++){
      int v; cin>>v;
      e[u].push_back(v);
      din[v]++;
    }
  }
  toposort();
  // for(auto x : tp) cout<<x<<' ';cout<<'\n';
  if(tp.size()==n) cout<<"YES\n";
  else cout<<n-tp.size();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}