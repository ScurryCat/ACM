#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n,m; cin>>n>>m;
	vector<PII> t(n);
	for(int i=0;i<n;i++) cin>>t[i].first;
	for(int i=0;i<n;i++) cin>>t[i].second;
	sort(t.begin(),t.end());
	vector<int> a(n),b(n);
	a[0]=t[0].second;
	b[0]=0;
	for(int i=1;i<n;i++){
		if(t[i].second>a[i-1]){
			a[i]=t[i].second;
			b[i]=a[i-1];
		}
		else{
			a[i]=a[i-1];
			b[i]=max(b[i-1],t[i].second);
		}
	}
	ll ans=0;
	while(m--){
		int x; cin>>x;
		int l=-1,r=n,mid;
		while(l+1<r){
			mid=l+r>>1;
			if(t[mid].first<x) l=mid;
			else r=mid;
		}
		ans+=a[l]+b[l];
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