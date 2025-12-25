#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n; cin>>n;
	vector<int> a(n);
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>2) cnt+=a[i]-2,a[i]=2;
	}
	for(int i=0;i<n;i++){
		if(a[i]<2 && cnt>=2-a[i]) cnt-=2-a[i],a[i]=2;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]==2) ans++;
	}
	if(cnt&1) ans--;
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