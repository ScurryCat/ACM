#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	ll n, k; cin>>n>>k;
	vector<int> q(n), r(n);
	for(int i=0;i<n;i++) cin>>q[i];
	for(int i=0;i<n;i++) cin>>r[i];
	int ans=0;
	sort(q.begin(),q.end(),greater<int>());
	sort(r.begin(),r.end());
	int j=0;
	for(int i=0;i<n;i++){
		ll x=(k+1)/(q[i]+1)-1;
		if(j<n&&r[j]<=x){
			ans++;
			j++;
		}
	}
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