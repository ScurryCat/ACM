#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 3e5+9, mod = 998244353;

int q[N],h,t;// 头尾一致，相当于初始化时队列内内置了s[0]

void qwq_(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1), s(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	int ans=s[1];
	for(int i=1;i<=n;i++){
		if(h<=t && q[h]<i-m) h++;
		ans=max(ans,s[i]-s[q[h]]);
		while(h<=t && s[i]<=s[q[t]]) t--;
		q[++t]=i;
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}