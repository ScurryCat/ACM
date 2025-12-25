#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> q(n+1,0);
	int h=1,t=0;
	cout<<"0\n";
	for(int i=1;i<n;i++){
		if(h<=t && q[h]<=i-m) h++;
		while(h<=t && a[i]<=a[q[t]]) t--;
		q[++t]=i;
		cout<<a[q[h]]<<'\n';
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