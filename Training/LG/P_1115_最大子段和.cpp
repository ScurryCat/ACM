#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 2e5+9, mod = 998244353;

int a[N],s[N],q[N],hh,tt;

void qwq_(){
	int n; cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	int ans=s[1];
	for(int i=1;i<=n;i++){
		ans=max(ans,s[i]-s[q[hh]]);
		while(hh<=tt && s[i]<=s[q[tt]]) tt--;
		q[++tt]=i;
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}