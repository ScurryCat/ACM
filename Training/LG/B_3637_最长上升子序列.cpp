#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n; cin>>n;
	vector<int> a(n+1),f(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]>a[j]) f[i]=max(f[i],f[j]+1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,f[i]);
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