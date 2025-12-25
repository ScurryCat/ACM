#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int n,m;
int din[N];
vector<int> e[N],tp;

int toposort(){
  queue<int> q;
  for(int i=1;i<=n;i++) if(!din[i]) q.push(i);
  while(q.size()){
    int u=q.front(); q.pop();
    tp.push_back(u);
    for(auto v : e[u]){
      if(--din[v]==0) q.push(v);
    }
  }
  return tp.size()==n;
}

void solve(){
	cin>>n>>m;
  for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    e[u].push_back(v);
    din[v]++;
  }
  if(toposort()) for(auto x : tp) cout<<x<<' ';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}