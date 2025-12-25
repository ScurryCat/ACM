#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e9+9, mod = 998244353;

unordered_map<ll,ll> f;
ll w[109],v[109];

void qwq_(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=w[i];j--){
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
	}
	cout<<f[m];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}