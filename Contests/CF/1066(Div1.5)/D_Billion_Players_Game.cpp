#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

struct p{ll n,l,r;};

void qwq_(){
	ll n,l,r;
	cin>>n>>l>>r;
	ll ans=0;
	vector<p> a(n+1);
	vector<ll> s1(n+1),s2(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i].n;
		a[i].l=l-a[i].n;
		a[i].r=a[i].n-r;
		s1[i]=s1[i-1]+a[i].l;
		s2[i]=s2[i-1]+a[i].r;
		cout<<s1[i]<<' '<<s2[i]<<'\n';
	}
	// cout<<s1[n]<<' '<<s2[n]<<'\n';
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}