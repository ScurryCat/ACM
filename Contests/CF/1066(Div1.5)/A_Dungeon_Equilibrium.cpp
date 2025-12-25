#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	// for(int i=0;i<n;i++) cout<<a[i]<<' ';cout<<'\n';
	int ans=0;
	for(int i=0;i<n;i++){
		int cnt=1, j;
		for(j=i+1;a[j]==a[j-1] && j<n;j++) cnt++;
		if(cnt>=a[i]) ans += cnt-a[i];
		else ans+=cnt;
		// cout<<cnt<<' '<<ans<<' ';
		i=j-1;
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