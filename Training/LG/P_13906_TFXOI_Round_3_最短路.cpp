#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void bfs(const vector<int> e[],vector<int> &vis,int s,int t){
	queue<pair<int,int>> q;
	q.push({s,0});
	while(q.size()){
		int u=q.front().first, w=q.front().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto v:e[u]){
			if(v==t){
				cout<<w+1<<'\n';
				return ;
			}
			q.push({v,w+1});
		}
	}
}

void qwq_(){
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	vector<int> e[n+1], vis(n+1);
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	bfs(e,vis,s,t);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}