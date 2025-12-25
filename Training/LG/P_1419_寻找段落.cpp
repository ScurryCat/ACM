#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int s[N];
int q[N],h,t;

void qwq_(){
	int n,l,r; cin>>n>>l>>r;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		s[i]=s[i-1]+x;
	}
	int ans=0;
	for(int i=(r-l+1);i<=n;i++){
		if(h<=t && q[h]<i-(r-l+1)) h++;
		if(h<=t) ans=max(ans,s[i]-s[q[h]]);
		while(h<=t && s[i]>=s[q[t]]) t--;
		q[++t]=i;
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