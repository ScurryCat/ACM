#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int INF = (1<<31)-1;
const int N = 1e5+9, mod = 998244353;

struct edge{int v,w;};
int n,m;
int d[N],vis[N],cnt[N];
vector<edge> e[N];

bool SPFA(int s){
  memset(vis,0,sizeof vis);
  memset(cnt,0,sizeof cnt);
  memset(d,0x3f,sizeof d);
  d[s]=0;
  queue<int> q;
  q.push(s);
  vis[s]=1;
  while(q.size()){
    int u=q.front();
    q.pop();
    vis[u]=0;
    for(auto ed : e[u]){
      int v=ed.v,w=ed.w;
      if(d[v]>d[u]+w){
        d[v]=d[u]+w;
        cnt[v]=cnt[u]+1;
        if(cnt[v]>=n) return true;
        // if(++cnt[v]>=n) return true; // 可以直接计数松弛次数，如果>=n次,则必定有环
        if(!vis[v]) q.push(v),vis[v]=1;
      }
    }
  }
  return false;
}

void solve(){
	cin>>n>>m;
  for(int i=1;i<=m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    if(w>=0){
      e[u].push_back({v,w});
      e[v].push_back({u,w});
    }
    else e[u].push_back({v,w});
  }
  if(SPFA(1)) cout<<"YES\n";
  else cout<<"NO\n";
  for(int i=1;i<=n;i++) e[i].clear();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) solve();
	return 0;
}