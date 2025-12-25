#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9, M = 2e5+9;

int n,m;
int h[N],to[M],ne[M],tot=1;
int dfn[N],low[N],idx;
struct bridge{int u,v;}bri[M];
int cnt;

inline void add(int u,int v){
	to[++tot]=v; ne[tot]=h[u]; h[u]=tot;
}

inline void tarjan(int u,int ed){
	dfn[u]=low[u]=++idx;
	for(int i=h[u];i;i=ne[i]){
    int v=to[i];
    if(!dfn[v]){
      tarjan(v,i);
      low[u]=min(low[u],low[v]);
      if(low[v]>dfn[u]){
        bri[++cnt]={u,v}; // 割边
      }
    }
    else if(i!=(ed^1)){ // 不是反边
      low[u]=min(low[u],dfn[v]);
    }
  }
}

inline void qwq_(){
	cin>>n>>m;
	while(m--){
		int u,v; cin>>u>>v;
		add(u,v); add(v,u);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i,0);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}