#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n,m; cin>>n>>m;
	vector<int> t(n+1), x(n+1);
	vector<int> mi(n+1), ma(n+1);
	for(int i=1,p=0;i<=m;i++){
		cin>>t[i]>>x[i];
		if(p==x[i]) mi[t[i]]=mi[t[i-1]]+1,p=(p?0:1);
		else mi[t[i]]=mi[t[i-1]];
	}
	for(int i=1;i<=n;i++){
		if(mi[i]) continue;
		mi[i]=mi[i-1];
	}
	for(int i=1,j=1,p=0;i<=n;i++){
		if(i>t[j]) j++;
		if(i==t[j] && p==x[j]) ma[i]=ma[i-1];
		else{
			p=(p?0:1);
			ma[i]=ma[i-1]+1;
		}
	}
	for(int i=1;i<=n;i++) cout<<mi[i]<<' '<<ma[i]<<'\n';
	int op; cin>>op;
	for(int i=1;i<=op;i++){
		int q; cin>>q;
		if(q<mi[n] || q>ma[n]) cout<<"No\n";
		else{
			cout<<"Yes\n";
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