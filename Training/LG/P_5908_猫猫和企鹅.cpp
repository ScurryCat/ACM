#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

struct edge{int v;};
vector<int> e[N];
int vis[N],d[N];
int n,m,ans;

void bfs(int u){
	memset(d,0x3f,sizeof d);
	d[u]=0;
	queue<int> q;
	q.push(u);
	while(q.size()){
		u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v : e[u]){
			d[v]=min(d[v],d[u]+1);
			q.push(v);
		}
	}
}

void qwq_(){
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	bfs(1);
	for(int i=2;i<=n;i++){
		if(d[i]<=m) ans++;
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}