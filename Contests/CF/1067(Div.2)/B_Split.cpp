#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n; cin>>n;
	vector<int> a(n+n+1);
	int ans=0, cnt1=0, cnt2=0;
	for(int i=1;i<=n+n;i++){
		int x; cin>>x;
		if(!a[x]) ans++;
		a[x]++;
	}
	// cout<<ans<<' ';
	for(int i=1;i<=n+n;i++){
		if(a[i]){
			cnt1++;
			if(a[i]&1) cnt2++;
			ans+=(a[i]-1)%2;
		}
	}
	if (!cnt2 && ((cnt1&1) != (n&1))) ans-=2;
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