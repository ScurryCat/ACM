#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 2e6+9, mod = 998244353;

int q[N],h=1,t;

void qwq_(){
	int n,k; cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(h<=t && q[h]<i-k+1) h++;
		while(h<=t && a[i]>=a[q[t]]) t--;
		q[++t]=i;
		if(i>=k) cout<<a[q[h]]<<'\n';
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