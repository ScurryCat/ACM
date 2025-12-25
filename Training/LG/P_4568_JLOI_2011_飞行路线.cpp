#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e4+9, M = 1e5+9, mod = 998244353;

int n,m,k,s,t;
struct edge{int v,w,ne;}e[M];
int h[N],d[11*N],tot=1;

inline void add(int u,int v,int w){
	e[++tot].v=v; e[tot].w=w; e[tot].ne=h[u]; h[u]=tot;
}

void dijkstra(int s){
	memset(d,0x3f,sizeof d);
	d[s]=0;
	priority_queue<pair<ll,int>> q;
	q.push({0,s});
	while(q.size()){
		int u=q.top().second; q.pop();
		int uu=u%n, f=u/n;
		for(int i=h[uu];i;i=e[i].ne){
			int v=f*n+e[i].v, w=e[i].w;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({-d[v],v});
			}
			if(f<k){
				if(d[n+v]>d[u]){
					d[n+v]=d[u];
					q.push({-d[n+v],n+v});
				}
			}
		}
	}
}

void qwq_(){
	cin>>n>>m>>k>>s>>t;
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		add(u,v,w); add(v,u,w);
	}
	dijkstra(s);
	int ans=0x3f3f3f3f;
	for(int i=0;i<=k;i++) ans=min(ans,d[i*n+t]);
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