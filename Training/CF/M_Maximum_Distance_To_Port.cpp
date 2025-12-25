#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 2e5+9, mod = 998244353;

int n,m,k;
int a[N],d[N],vis[N],ans[N];
vector<int> e[N];

void dijk(int s){
	memset(d,0x3f,sizeof d);
	d[s]=0;
	priority_queue<pair<int,int>> pq;
	pq.push({d[s],s});
	while(pq.size()){
		int u=pq.top().second;
		pq.pop();
		vis[u]=1;
		ans[a[u]]=max(ans[a[u]],d[u]);
		for(int v : e[u]){
			if(vis[v]) continue;
			if(d[u]+1<d[v]){
				d[v]=d[u]+1;
				pq.push({-d[v],v});
			}
		}
	}
}

void qwq_(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		int u,v; cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dijk(1);
	// for(int i=1;i<=n;i++) cout<<d[i]<<' ';
	for(int i=1;i<=k;i++) cout<<ans[i]<<' ';

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}