#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int n,cnt;
vector<int> e[N];
int vis[N],to[N];

void qwq_(){
	cin>>n;
	for(int i=1;i<=n;i++) to[i]=i;
	for(int i=1;i<=n;i++){
		int u,v;
		cin>>u>>v;
		if(to[u]==to[v]) cnt++;
		to[v]=to[u];
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(cnt==1) cout<<"YES\n";
	else cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}