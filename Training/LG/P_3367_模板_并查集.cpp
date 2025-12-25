#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 2e5+9, mod = 998244353;

int fa[N],siz[N];

int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

void unionset(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return;
	if(siz[x]>siz[y]) swap(x,y);
	fa[x]=y;
	siz[y]+=siz[x];
}

void qwq_(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=m;i++){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1){
			unionset(x,y);
		}
		else{
			if(find(x)==find(y)) cout<<"Y\n";
			else cout<<"N\n";
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}